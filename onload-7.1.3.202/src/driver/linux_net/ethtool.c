/****************************************************************************
 * Driver for Solarflare network controllers and boards
 * Copyright 2005-2006 Fen Systems Ltd.
 * Copyright 2006-2017 Solarflare Communications Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, incorporated herein by reference.
 */

#include <linux/netdevice.h>
#include <linux/ethtool.h>
#include <linux/rtnetlink.h>
#include <linux/in.h>
#include "mcdi_pcol.h"
#include "net_driver.h"
#include "workarounds.h"
#include "selftest.h"
#include "efx.h"
#include "filter.h"
#include "nic.h"
#ifdef CONFIG_SFC_DUMP
#include "dump.h"
#endif

#ifdef EFX_NOT_UPSTREAM
#include "sfctool.h"
#endif

struct efx_sw_stat_desc {
	const char *name;
	enum {
		EFX_ETHTOOL_STAT_SOURCE_nic,
		EFX_ETHTOOL_STAT_SOURCE_channel,
		EFX_ETHTOOL_STAT_SOURCE_tx_queue
	} source;
	unsigned int offset;
	u64(*get_stat) (void *field); /* Reader function */
};

/* Initialiser for a struct efx_sw_stat_desc with type-checking */
#define EFX_ETHTOOL_STAT(stat_name, source_name, field, field_type, \
				get_stat_function) {			\
	.name = #stat_name,						\
	.source = EFX_ETHTOOL_STAT_SOURCE_##source_name,		\
	.offset = ((((field_type *) 0) ==				\
		      &((struct efx_##source_name *)0)->field) ?	\
		    offsetof(struct efx_##source_name, field) :		\
		    offsetof(struct efx_##source_name, field)),		\
	.get_stat = get_stat_function,					\
}

static u64 efx_get_uint_stat(void *field)
{
	return *(unsigned int *)field;
}

static u64 efx_get_atomic_stat(void *field)
{
	return atomic_read((atomic_t *) field);
}

#define EFX_ETHTOOL_ATOMIC_NIC_ERROR_STAT(field)		\
	EFX_ETHTOOL_STAT(field, nic, errors.field,		\
			 atomic_t, efx_get_atomic_stat)

#define EFX_ETHTOOL_UINT_CHANNEL_STAT(field)			\
	EFX_ETHTOOL_STAT(field, channel, n_##field,		\
			 unsigned int, efx_get_uint_stat)
#define EFX_ETHTOOL_UINT_CHANNEL_STAT_NO_N(field)		\
	EFX_ETHTOOL_STAT(field, channel, field,			\
			 unsigned int, efx_get_uint_stat)

#define EFX_ETHTOOL_UINT_TXQ_STAT(field)			\
	EFX_ETHTOOL_STAT(tx_##field, tx_queue, field,		\
			 unsigned int, efx_get_uint_stat)

static const struct efx_sw_stat_desc efx_sw_stat_desc[] = {
	EFX_ETHTOOL_UINT_TXQ_STAT(merge_events),
	EFX_ETHTOOL_UINT_TXQ_STAT(tso_bursts),
	EFX_ETHTOOL_UINT_TXQ_STAT(tso_long_headers),
	EFX_ETHTOOL_UINT_TXQ_STAT(tso_packets),
	EFX_ETHTOOL_UINT_TXQ_STAT(tso_fallbacks),
	EFX_ETHTOOL_UINT_TXQ_STAT(pushes),
	EFX_ETHTOOL_UINT_TXQ_STAT(pio_packets),
	EFX_ETHTOOL_UINT_TXQ_STAT(cb_packets),
	EFX_ETHTOOL_ATOMIC_NIC_ERROR_STAT(rx_reset),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_tobe_disc),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_ip_hdr_chksum_err),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_tcp_udp_chksum_err),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_inner_ip_hdr_chksum_err),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_inner_tcp_udp_chksum_err),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_outer_ip_hdr_chksum_err),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_outer_tcp_udp_chksum_err),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_eth_crc_err),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_mcast_mismatch),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_frm_trunc),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_merge_events),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_merge_packets),
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_XDP)
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_xdp_drops),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_xdp_bad_drops),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_xdp_tx),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rx_xdp_redirect),
#endif
#ifdef CONFIG_RFS_ACCEL
	EFX_ETHTOOL_UINT_CHANNEL_STAT_NO_N(rfs_filter_count),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rfs_succeeded),
	EFX_ETHTOOL_UINT_CHANNEL_STAT(rfs_failed),
#endif
};

#define EFX_ETHTOOL_SW_STAT_COUNT ARRAY_SIZE(efx_sw_stat_desc)

#define EFX_ETHTOOL_EEPROM_MAGIC 0xEFAB

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_PRIV_FLAGS)
static const char efx_ethtool_priv_flags_strings[][ETH_GSTRING_LEN] = {
	"phy-power-follows-link",
};

#define EFX_ETHTOOL_PRIV_FLAGS_PHY_POWER	BIT(0)

#define EFX_ETHTOOL_PRIV_FLAGS_COUNT ARRAY_SIZE(efx_ethtool_priv_flags_strings)
#endif

/**************************************************************************
 *
 * Ethtool operations
 *
 **************************************************************************
 */

/* Identify device by flashing LEDs */
static int efx_ethtool_phys_id(struct net_device *net_dev,
			       enum ethtool_phys_id_state state)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	enum efx_led_mode mode = EFX_LED_DEFAULT;

	switch (state) {
	case ETHTOOL_ID_ON:
		mode = EFX_LED_ON;
		break;
	case ETHTOOL_ID_OFF:
		mode = EFX_LED_OFF;
		break;
	case ETHTOOL_ID_INACTIVE:
		mode = EFX_LED_DEFAULT;
		break;
	case ETHTOOL_ID_ACTIVE:
		return 1;	/* cycle on/off once per second */
	}

	efx->type->set_id_led(efx, mode);
	return 0;
}

#if defined(EFX_USE_KCOMPAT) && !defined(EFX_HAVE_ETHTOOL_SET_PHYS_ID)
static int efx_ethtool_phys_id_loop(struct net_device *net_dev, u32 count)
{
	/* Driver expects to be called at twice the frequency in rc */
	int rc = efx_ethtool_phys_id(net_dev, ETHTOOL_ID_ACTIVE);
	int n = rc * 2, i, interval = HZ / n;

	/* Count down seconds */
	do {
		/* Count down iterations per second */
		i = n;
		do {
			efx_ethtool_phys_id(net_dev,
					    (i & 1) ? ETHTOOL_ID_OFF
					    : ETHTOOL_ID_ON);
			schedule_timeout_interruptible(interval);
		} while (!signal_pending(current) && --i != 0);
	} while (!signal_pending(current) &&
		 (count == 0 || --count != 0));

	(void)efx_ethtool_phys_id(net_dev, ETHTOOL_ID_INACTIVE);
	return 0;
}
#endif

#if defined(EFX_USE_KCOMPAT) && !defined(EFX_HAVE_ETHTOOL_LINKSETTINGS) || defined(EFX_HAVE_ETHTOOL_LEGACY)
/* This must be called with rtnl_lock held. */
static int efx_ethtool_get_settings(struct net_device *net_dev,
				    struct ethtool_cmd *ecmd)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	struct efx_link_state *link_state = &efx->link_state;

	mutex_lock(&efx->mac_lock);
	efx->phy_op->get_settings(efx, ecmd);
	mutex_unlock(&efx->mac_lock);

	/* Both MACs support pause frames (bidirectional and respond-only) */
	ecmd->supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;

	if (LOOPBACK_INTERNAL(efx)) {
		ethtool_cmd_speed_set(ecmd, link_state->speed);
		ecmd->duplex = link_state->fd ? DUPLEX_FULL : DUPLEX_HALF;
	}

	return 0;
}

/* This must be called with rtnl_lock held. */
static int efx_ethtool_set_settings(struct net_device *net_dev,
				    struct ethtool_cmd *ecmd)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	int rc;

	/* GMAC does not support 1000Mbps HD */
	if ((ethtool_cmd_speed(ecmd) == SPEED_1000) &&
	    (ecmd->duplex != DUPLEX_FULL)) {
		netif_dbg(efx, drv, efx->net_dev,
			  "rejecting unsupported 1000Mbps HD setting\n");
		return -EINVAL;
	}

	mutex_lock(&efx->mac_lock);
	rc = efx->phy_op->set_settings(efx, ecmd);
	mutex_unlock(&efx->mac_lock);
	return rc;
}
#endif

static void efx_ethtool_get_drvinfo(struct net_device *net_dev,
				    struct ethtool_drvinfo *info)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	strlcpy(info->driver, KBUILD_MODNAME, sizeof(info->driver));
	strlcpy(info->version, EFX_DRIVER_VERSION, sizeof(info->version));
	if (!in_interrupt())
		efx_mcdi_print_fwver(efx, info->fw_version,
				     sizeof(info->fw_version));
	else
		strlcpy(info->fw_version, "N/A", sizeof(info->fw_version));
	strlcpy(info->bus_info, pci_name(efx->pci_dev), sizeof(info->bus_info));
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_PRIV_FLAGS)
	info->n_priv_flags = EFX_ETHTOOL_PRIV_FLAGS_COUNT;
#endif
}

static int efx_ethtool_get_regs_len(struct net_device *net_dev)
{
	return efx_nic_get_regs_len(netdev_priv(net_dev));
}

static void efx_ethtool_get_regs(struct net_device *net_dev,
				 struct ethtool_regs *regs, void *buf)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	regs->version = efx->type->revision;
	efx_nic_get_regs(efx, buf);
}

static u32 efx_ethtool_get_msglevel(struct net_device *net_dev)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	return efx->msg_enable;
}

static void efx_ethtool_set_msglevel(struct net_device *net_dev, u32 msg_enable)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	efx->msg_enable = msg_enable;
}

/**
 * efx_fill_test - fill in an individual self-test entry
 * @test_index:		Index of the test
 * @strings:		Ethtool strings, or %NULL
 * @data:		Ethtool test results, or %NULL
 * @test:		Pointer to test result (used only if data != %NULL)
 * @unit_format:	Unit name format (e.g. "chan\%d")
 * @unit_id:		Unit id (e.g. 0 for "chan0")
 * @test_format:	Test name format (e.g. "loopback.\%s.tx.sent")
 * @test_id:		Test id (e.g. "PHYXS" for "loopback.PHYXS.tx_sent")
 *
 * Fill in an individual self-test entry.
 */
static void efx_fill_test(unsigned int test_index, u8 *strings, u64 *data,
			  int *test, const char *unit_format, int unit_id,
			  const char *test_format, const char *test_id)
{
	char unit_str[ETH_GSTRING_LEN], test_str[ETH_GSTRING_LEN];

	/* Fill data value, if applicable */
	if (data)
		data[test_index] = *test;

	/* Fill string, if applicable */
	if (strings) {
		if (strchr(unit_format, '%'))
			snprintf(unit_str, sizeof(unit_str),
				 unit_format, unit_id);
		else
			strcpy(unit_str, unit_format);
		snprintf(test_str, sizeof(test_str), test_format, test_id);
		snprintf(strings + test_index * ETH_GSTRING_LEN,
			 ETH_GSTRING_LEN,
			 "%-6s %-24s", unit_str, test_str);
	}
}

#define EFX_LOOPBACK_NAME(_mode, _counter)			\
	"loopback.%s." _counter, STRING_TABLE_LOOKUP(_mode, efx_loopback_mode)

/**
 * efx_fill_loopback_test - fill in a block of loopback self-test entries
 * @efx:		Efx NIC
 * @lb_tests:		Efx loopback self-test results structure
 * @mode:		Loopback test mode
 * @test_index:		Starting index of the test
 * @strings:		Ethtool strings, or %NULL
 * @data:		Ethtool test results, or %NULL
 *
 * Fill in a block of loopback self-test entries.  Return new test
 * index.
 */
static int efx_fill_loopback_test(struct efx_nic *efx,
				  struct efx_loopback_self_tests *lb_tests,
				  enum efx_loopback_mode mode,
				  unsigned int test_index,
				  u8 *strings, u64 *data)
{
	struct efx_channel *channel =
		efx_get_channel(efx, efx->tx_channel_offset);
	struct efx_tx_queue *tx_queue;

	efx_for_each_channel_tx_queue(tx_queue, channel) {
		efx_fill_test(test_index++, strings, data,
			      &lb_tests->tx_sent[tx_queue->queue],
			      EFX_TX_QUEUE_NAME(tx_queue),
			      EFX_LOOPBACK_NAME(mode, "tx_sent"));
		efx_fill_test(test_index++, strings, data,
			      &lb_tests->tx_done[tx_queue->queue],
			      EFX_TX_QUEUE_NAME(tx_queue),
			      EFX_LOOPBACK_NAME(mode, "tx_done"));
	}
	efx_fill_test(test_index++, strings, data,
		      &lb_tests->rx_good,
		      "rx", 0,
		      EFX_LOOPBACK_NAME(mode, "rx_good"));
	efx_fill_test(test_index++, strings, data,
		      &lb_tests->rx_bad,
		      "rx", 0,
		      EFX_LOOPBACK_NAME(mode, "rx_bad"));

	return test_index;
}

/**
 * efx_ethtool_fill_self_tests - get self-test details
 * @efx:		Efx NIC
 * @tests:		Efx self-test results structure, or %NULL
 * @strings:		Ethtool strings, or %NULL
 * @data:		Ethtool test results, or %NULL
 *
 * Get self-test number of strings, strings, and/or test results.
 * Return number of strings (== number of test results).
 *
 * The reason for merging these three functions is to make sure that
 * they can never be inconsistent.
 */
static int efx_ethtool_fill_self_tests(struct efx_nic *efx,
				       struct efx_self_tests *tests,
				       u8 *strings, u64 *data)
{
	struct efx_channel *channel;
	unsigned int n = 0, i;
	enum efx_loopback_mode mode;

	efx_fill_test(n++, strings, data, &tests->phy_alive,
		      "phy", 0, "alive", NULL);
	efx_fill_test(n++, strings, data, &tests->nvram,
		      "core", 0, "nvram", NULL);
	efx_fill_test(n++, strings, data, &tests->interrupt,
		      "core", 0, "interrupt", NULL);

	/* Event queues */
	efx_for_each_channel(channel, efx) {
		efx_fill_test(n++, strings, data,
			      tests ? &tests->eventq_dma[channel->channel] : NULL,
			      EFX_CHANNEL_NAME(channel),
			      "eventq.dma", NULL);
		efx_fill_test(n++, strings, data,
			      tests ? &tests->eventq_int[channel->channel] : NULL,
			      EFX_CHANNEL_NAME(channel),
			      "eventq.int", NULL);
	}

	efx_fill_test(n++, strings, data, &tests->memory,
		      "core", 0, "memory", NULL);
	efx_fill_test(n++, strings, data, &tests->registers,
		      "core", 0, "registers", NULL);

	if (efx->phy_op->run_tests != NULL) {
		EFX_WARN_ON_PARANOID(efx->phy_op->test_name == NULL);

		for (i = 0; true; ++i) {
			const char *name;

			EFX_WARN_ON_PARANOID(i >= EFX_MAX_PHY_TESTS);
			name = efx->phy_op->test_name(efx, i);
			if (name == NULL)
				break;

			efx_fill_test(n++, strings, data, &tests->phy_ext[i],
				      "phy", 0, name, NULL);
		}
	}

	/* Loopback tests */
	for (mode = LOOPBACK_NONE; mode <= LOOPBACK_TEST_MAX; mode++) {
		if (!(efx->loopback_modes & (1 << mode)))
			continue;
		n = efx_fill_loopback_test(efx,
					   &tests->loopback[mode], mode, n,
					   strings, data);
	}

	return n;
}

static size_t efx_describe_per_queue_stats(struct efx_nic *efx, u8 *strings)
{
	size_t n_stats = 0;
	struct efx_channel *channel;

	efx_for_each_channel(channel, efx) {
		if (efx_channel_has_tx_queues(channel)) {
			n_stats++;
			if (strings != NULL) {
				unsigned int core_txq = channel->channel -
							efx->tx_channel_offset;

				snprintf(strings, ETH_GSTRING_LEN,
					 "tx-%u.tx_packets", core_txq);
				strings += ETH_GSTRING_LEN;
			}
		}
	}
	efx_for_each_channel(channel, efx) {
		if (efx_channel_has_rx_queue(channel)) {
			n_stats++;
			if (strings != NULL) {
				snprintf(strings, ETH_GSTRING_LEN,
					 "rx-%d.rx_packets", channel->channel);
				strings += ETH_GSTRING_LEN;
			}
		}
	}
	if (efx->xdp_tx_queue_count && efx->xdp_tx_queues) {
		unsigned short xdp;

		for (xdp = 0; xdp < efx->xdp_tx_queue_count; xdp++) {
			n_stats++;
			if (strings != NULL) {
				snprintf(strings, ETH_GSTRING_LEN,
					 "tx-xdp-cpu-%hu.tx_packets", xdp);
				strings += ETH_GSTRING_LEN;
			}
		}
	}

	return n_stats;
}

static int efx_ethtool_get_sset_count(struct net_device *net_dev,
				      int string_set)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	switch (string_set) {
	case ETH_SS_STATS:
		return efx->type->describe_stats(efx, NULL) +
		       EFX_ETHTOOL_SW_STAT_COUNT +
		       efx_describe_per_queue_stats(efx, NULL) +
		       efx_ptp_describe_stats(efx, NULL);
	case ETH_SS_TEST:
		return efx_ethtool_fill_self_tests(efx, NULL, NULL, NULL);
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_PRIV_FLAGS)
	case ETH_SS_PRIV_FLAGS:
		return EFX_ETHTOOL_PRIV_FLAGS_COUNT;
#endif
	default:
		return -EINVAL;
	}
}

#if defined(EFX_USE_KCOMPAT) && !defined(EFX_USE_ETHTOOL_GET_SSET_COUNT)
static int efx_ethtool_get_stats_count(struct net_device *net_dev)
{
	return efx_ethtool_get_sset_count(net_dev, ETH_SS_STATS);
}
static int efx_ethtool_self_test_count(struct net_device *net_dev)
{
	return efx_ethtool_get_sset_count(net_dev, ETH_SS_TEST);
}
#endif

static void efx_ethtool_get_strings(struct net_device *net_dev,
				    u32 string_set, u8 *strings)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	int i;

	switch (string_set) {
	case ETH_SS_STATS:
		strings += (efx->type->describe_stats(efx, strings) *
			    ETH_GSTRING_LEN);
		for (i = 0; i < EFX_ETHTOOL_SW_STAT_COUNT; i++)
			strlcpy(strings + i * ETH_GSTRING_LEN,
				efx_sw_stat_desc[i].name, ETH_GSTRING_LEN);
		strings += EFX_ETHTOOL_SW_STAT_COUNT * ETH_GSTRING_LEN;
		strings += (efx_describe_per_queue_stats(efx, strings) *
			    ETH_GSTRING_LEN);
		efx_ptp_describe_stats(efx, strings);
		break;
	case ETH_SS_TEST:
		efx_ethtool_fill_self_tests(efx, NULL, strings, NULL);
		break;
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_PRIV_FLAGS)
	case ETH_SS_PRIV_FLAGS:
		for (i = 0; i < EFX_ETHTOOL_PRIV_FLAGS_COUNT; i++)
			strlcpy(strings + i * ETH_GSTRING_LEN,
				efx_ethtool_priv_flags_strings[i],
				ETH_GSTRING_LEN);
		break;
#endif
	default:
		/* No other string sets */
		break;
	}
}

static void efx_ethtool_get_stats(struct net_device *net_dev,
				  struct ethtool_stats *stats
				  __attribute__ ((unused)), u64 *data)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	const struct efx_sw_stat_desc *stat;
	struct efx_channel *channel;
	struct efx_tx_queue *tx_queue;
	struct efx_rx_queue *rx_queue;
	int i;

	/* Get NIC statistics */
	data += efx->type->update_stats(efx, data, NULL);
	/* efx->stats is obtained in update_stats and held */

	/* Get software statistics */
	for (i = 0; i < EFX_ETHTOOL_SW_STAT_COUNT; i++) {
		stat = &efx_sw_stat_desc[i];
		switch (stat->source) {
		case EFX_ETHTOOL_STAT_SOURCE_nic:
			data[i] = stat->get_stat((void *)efx + stat->offset);
			break;
		case EFX_ETHTOOL_STAT_SOURCE_channel:
			data[i] = 0;
			efx_for_each_channel(channel, efx)
				data[i] += stat->get_stat((void *)channel +
							  stat->offset);
			break;
		case EFX_ETHTOOL_STAT_SOURCE_tx_queue:
			data[i] = 0;
			efx_for_each_channel(channel, efx) {
				efx_for_each_channel_tx_queue(tx_queue, channel)
					data[i] +=
						stat->get_stat((void *)tx_queue
							       + stat->offset);
			}
			break;
		}
	}
	data += EFX_ETHTOOL_SW_STAT_COUNT;

	/* release stats_lock obtained in update_stats */
	spin_unlock_bh(&efx->stats_lock);

	efx_for_each_channel(channel, efx) {
		if (efx_channel_has_tx_queues(channel)) {
			data[0] = 0;
			efx_for_each_channel_tx_queue(tx_queue, channel) {
				data[0] += tx_queue->tx_packets;
			}
			data++;
		}
	}
	efx_for_each_channel(channel, efx) {
		if (efx_channel_has_rx_queue(channel)) {
			data[0] = 0;
			efx_for_each_channel_rx_queue(rx_queue, channel) {
				data[0] += rx_queue->rx_packets;
			}
			data++;
		}
	}
	if (efx->xdp_tx_queue_count && efx->xdp_tx_queues) {
		int xdp;

		for (xdp = 0; xdp < efx->xdp_tx_queue_count; xdp++) {
			data[0] = efx->xdp_tx_queues[xdp]->tx_packets;
			data++;
		}
	}

	efx_ptp_update_stats(efx, data);
}

#if defined(EFX_USE_KCOMPAT) && !defined(EFX_HAVE_NDO_SET_FEATURES) && !defined(EFX_HAVE_EXT_NDO_SET_FEATURES)

static int efx_ethtool_set_tso(struct net_device *net_dev, u32 enable)
{
	struct efx_nic *efx __attribute__ ((unused)) = netdev_priv(net_dev);
	u32 features;

	features = NETIF_F_TSO;
#if !defined(EFX_USE_KCOMPAT) || defined(NETIF_F_IPV6_CSUM)
	if (efx->type->offload_features & (NETIF_F_IPV6_CSUM | NETIF_F_HW_CSUM))
		features |= NETIF_F_TSO6;
#endif

	if (enable)
		net_dev->features |= features;
	else
		net_dev->features &= ~features;

	return 0;
}

static int efx_ethtool_set_tx_csum(struct net_device *net_dev, u32 enable)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	u32 features = efx->type->offload_features & NETIF_F_CSUM_MASK;

	if (enable)
		net_dev->features |= features;
	else
		net_dev->features &= ~features;

	return 0;
}

static int efx_ethtool_set_rx_csum(struct net_device *net_dev, u32 enable)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	/* No way to stop the hardware doing the checks; we just
	 * ignore the result.
	 */
	efx->rx_checksum_enabled = !!enable;

	return 0;
}

static u32 efx_ethtool_get_rx_csum(struct net_device *net_dev)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	return efx->rx_checksum_enabled;
}

#if defined(EFX_USE_ETHTOOL_FLAGS)
static int efx_ethtool_set_flags(struct net_device *net_dev, u32 data)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	u32 supported = (efx->type->offload_features &
			 (ETH_FLAG_RXHASH | ETH_FLAG_NTUPLE));
	int rc;

#if defined(EFX_NOT_UPSTREAM) && defined(EFX_USE_SFC_LRO)
	if (efx->lro_available)
		supported |= ETH_FLAG_LRO;
#endif

	if (data & ~supported)
		return -EINVAL;

	if (net_dev->features & ~data & ETH_FLAG_NTUPLE) {
		rc = efx->type->filter_clear_rx(efx, EFX_FILTER_PRI_MANUAL);
		if (rc)
			return rc;
	}

	net_dev->features = (net_dev->features & ~supported) | data;
	return 0;
}
#endif

#endif /* EFX_HAVE_NDO_SET_FEATURES && EFX_HAVE_EXT_NDO_SET_FEATURES */

static void efx_ethtool_self_test(struct net_device *net_dev,
				  struct ethtool_test *test, u64 *data)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	struct efx_self_tests *efx_tests;
	bool already_up;
	int rc = -ENOMEM;

	efx_tests = kzalloc(sizeof(*efx_tests), GFP_KERNEL);
	if (!efx_tests)
		goto fail;

	efx_tests->eventq_dma = kcalloc(efx->n_channels,
					sizeof(*efx_tests->eventq_dma),
					GFP_KERNEL);
	efx_tests->eventq_int = kcalloc(efx->n_channels,
					sizeof(*efx_tests->eventq_int),
					GFP_KERNEL);

	if (!efx_tests->eventq_dma || !efx_tests->eventq_int) {
		goto fail;
	}

	if (efx->state != STATE_READY) {
		rc = -EBUSY;
		goto out;
	}

	netif_info(efx, drv, efx->net_dev, "starting %sline testing\n",
		   (test->flags & ETH_TEST_FL_OFFLINE) ? "off" : "on");

	/* We need rx buffers and interrupts. */
	already_up = (efx->net_dev->flags & IFF_UP);
	if (!already_up) {
		rc = dev_open(efx->net_dev, NULL);
		if (rc) {
			netif_err(efx, drv, efx->net_dev,
				  "failed opening device.\n");
			goto out;
		}
	}

	rc = efx_selftest(efx, efx_tests, test->flags);

	if (!already_up)
		dev_close(efx->net_dev);

	netif_info(efx, drv, efx->net_dev, "%s %sline self-tests\n",
		   rc == 0 ? "passed" : "failed",
		   (test->flags & ETH_TEST_FL_OFFLINE) ? "off" : "on");

out:
	efx_ethtool_fill_self_tests(efx, efx_tests, NULL, data);

fail:
	if (efx_tests) {
		kfree(efx_tests->eventq_dma);
		kfree(efx_tests->eventq_int);
		kfree(efx_tests);
	}

	if (rc)
		test->flags |= ETH_TEST_FL_FAILED;
}

/* Restart autonegotiation */
static int efx_ethtool_nway_reset(struct net_device *net_dev)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	return mdio45_nway_restart(&efx->mdio);
}

#if defined(EFX_USE_KCOMPAT) && !defined(EFX_USE_ETHTOOL_OP_GET_LINK)
static u32 efx_ethtool_get_link(struct net_device *net_dev)
{
	return netif_running(net_dev) && netif_carrier_ok(net_dev);
}
#endif

/*
 * Each channel has a single IRQ and moderation timer, started by any
 * completion (or other event).  Unless the module parameter
 * separate_tx_channels is set, IRQs and moderation are therefore
 * shared between RX and TX completions.  In this case, when RX IRQ
 * moderation is explicitly changed then TX IRQ moderation is
 * automatically changed too, but otherwise we fail if the two values
 * are requested to be different.
 *
 * The hardware does not support a limit on the number of completions
 * before an IRQ, so we do not use the max_frames fields.  We should
 * report and require that max_frames == (usecs != 0), but this would
 * invalidate existing user documentation.
 *
 * The hardware does not have distinct settings for interrupt
 * moderation while the previous IRQ is being handled, so we should
 * not use the 'irq' fields.  However, an earlier developer
 * misunderstood the meaning of the 'irq' fields and the driver did
 * not support the standard fields.  To avoid invalidating existing
 * user documentation, we report and accept changes through either the
 * standard or 'irq' fields.  If both are changed at the same time, we
 * prefer the standard field.
 *
 * We implement adaptive IRQ moderation, but use a different algorithm
 * from that assumed in the definition of struct ethtool_coalesce.
 * Therefore we do not use any of the adaptive moderation parameters
 * in it.
 */

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_COALESCE_CQE)
static int efx_ethtool_get_coalesce(struct net_device *net_dev,
				    struct ethtool_coalesce *coalesce,
				    struct kernel_ethtool_coalesce *kernel_coal,
				    struct netlink_ext_ack *extack)
#else
static int efx_ethtool_get_coalesce(struct net_device *net_dev,
				    struct ethtool_coalesce *coalesce)
#endif
{
	struct efx_nic *efx = netdev_priv(net_dev);
	unsigned int tx_usecs, rx_usecs;
	bool rx_adaptive;

	efx_get_irq_moderation(efx, &tx_usecs, &rx_usecs, &rx_adaptive);

	coalesce->tx_coalesce_usecs = tx_usecs;
	coalesce->tx_coalesce_usecs_irq = tx_usecs;
	coalesce->rx_coalesce_usecs = rx_usecs;
	coalesce->rx_coalesce_usecs_irq = rx_usecs;
	coalesce->use_adaptive_rx_coalesce = rx_adaptive;
	coalesce->stats_block_coalesce_usecs = efx->stats_period_ms * 1000;

	return 0;
}

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_COALESCE_CQE)
static int efx_ethtool_set_coalesce(struct net_device *net_dev,
				    struct ethtool_coalesce *coalesce,
				    struct kernel_ethtool_coalesce *kernel_coal,
				    struct netlink_ext_ack *extack)
#else
static int efx_ethtool_set_coalesce(struct net_device *net_dev,
				    struct ethtool_coalesce *coalesce)
#endif
{
	struct efx_nic *efx = netdev_priv(net_dev);
	struct efx_channel *channel;
	unsigned int tx_usecs, rx_usecs;
	bool adaptive, rx_may_override_tx;
	unsigned int stats_usecs;
	int rc;

#if defined(EFX_USE_KCOMPAT) && !defined(EFX_HAVE_COALESCE_PARAMS)
	if (coalesce->use_adaptive_tx_coalesce)
		return -EINVAL;
#endif

	efx_get_irq_moderation(efx, &tx_usecs, &rx_usecs, &adaptive);

	if (coalesce->rx_coalesce_usecs != rx_usecs)
		rx_usecs = coalesce->rx_coalesce_usecs;
	else
		rx_usecs = coalesce->rx_coalesce_usecs_irq;

	adaptive = coalesce->use_adaptive_rx_coalesce;

	/* If channels are shared, TX IRQ moderation can be quietly
	 * overridden unless it is changed from its old value.
	 */
	rx_may_override_tx = (coalesce->tx_coalesce_usecs == tx_usecs &&
			      coalesce->tx_coalesce_usecs_irq == tx_usecs);
	if (coalesce->tx_coalesce_usecs != tx_usecs)
		tx_usecs = coalesce->tx_coalesce_usecs;
	else
		tx_usecs = coalesce->tx_coalesce_usecs_irq;

	rc = efx_init_irq_moderation(efx, tx_usecs, rx_usecs, adaptive,
				     rx_may_override_tx);
	if (rc != 0)
		return rc;

	efx_for_each_channel(channel, efx)
		efx->type->push_irq_moderation(channel);

	stats_usecs = coalesce->stats_block_coalesce_usecs;
	if (stats_usecs > 0 && stats_usecs < 1000)
		stats_usecs = 1000;
	efx_set_stats_period(efx, stats_usecs / 1000);

	return 0;
}

static void efx_ethtool_get_ringparam(struct net_device *net_dev,
				      struct ethtool_ringparam *ring)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	ring->rx_max_pending = EFX_MAX_DMAQ_SIZE;
	ring->tx_max_pending = EFX_TXQ_MAX_ENT(efx);
	ring->rx_pending = efx->rxq_entries;
	ring->tx_pending = efx->txq_entries;
}

static int efx_ethtool_set_ringparam(struct net_device *net_dev,
				     struct ethtool_ringparam *ring)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	int rc;

	if (ring->rx_mini_pending || ring->rx_jumbo_pending)
		return -EINVAL;

	if (ring->rx_pending == efx->rxq_entries &&
	    ring->tx_pending == efx->txq_entries)
		/* Nothing to do */
		return 0;

	/* Validate range and rounding of RX queue. */
	rc = efx_check_queue_size(efx, &ring->rx_pending,
				  EFX_RXQ_MIN_ENT, EFX_MAX_DMAQ_SIZE, false);
	if (rc == -ERANGE)
		netif_err(efx, drv, efx->net_dev,
			  "Rx queue length must be between %u and %lu\n",
			  EFX_RXQ_MIN_ENT, EFX_MAX_DMAQ_SIZE);
	else if (rc == -EINVAL)
		netif_err(efx, drv, efx->net_dev,
			  "Rx queue length must be power of two\n");

	if (rc)
		return rc;

	/* Validate range and rounding of TX queue. */
	rc = efx_check_queue_size(efx, &ring->tx_pending,
				  efx->txq_min_entries, EFX_TXQ_MAX_ENT(efx),
				  false);
	if (rc == -ERANGE)
		netif_err(efx, drv, efx->net_dev,
			  "Tx queue length must be between %u and %lu\n",
			  efx->txq_min_entries, EFX_TXQ_MAX_ENT(efx));
	else if (rc == -EINVAL)
		netif_err(efx, drv, efx->net_dev,
			  "Tx queue length must be power of two\n");

	if (rc)
		return rc;

	return efx_realloc_channels(efx, ring->rx_pending, ring->tx_pending);
}

static int efx_ethtool_set_pauseparam(struct net_device *net_dev,
				      struct ethtool_pauseparam *pause)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	u8 wanted_fc, old_fc;
	u32 old_adv;
	int rc = 0;

	mutex_lock(&efx->mac_lock);

	wanted_fc = ((pause->rx_pause ? EFX_FC_RX : 0) |
		     (pause->tx_pause ? EFX_FC_TX : 0) |
		     (pause->autoneg ? EFX_FC_AUTO : 0));

	if ((wanted_fc & EFX_FC_TX) && !(wanted_fc & EFX_FC_RX)) {
		netif_dbg(efx, drv, efx->net_dev,
			  "Flow control unsupported: tx ON rx OFF\n");
		rc = -EINVAL;
		goto out;
	}

	if ((wanted_fc & EFX_FC_AUTO) &&
	    !(efx->link_advertising[0] & ADVERTISED_Autoneg)) {
		netif_dbg(efx, drv, efx->net_dev,
			  "Autonegotiation is disabled\n");
		rc = -EINVAL;
		goto out;
	}

	/* Hook for Falcon bug 11482 workaround */
	if (efx->type->prepare_enable_fc_tx &&
	    (wanted_fc & EFX_FC_TX) && !(efx->wanted_fc & EFX_FC_TX))
		efx->type->prepare_enable_fc_tx(efx);

	old_adv = efx->link_advertising[0];
	old_fc = efx->wanted_fc;
	efx_link_set_wanted_fc(efx, wanted_fc);
	if (efx->link_advertising[0] != old_adv ||
	    (efx->wanted_fc ^ old_fc) & EFX_FC_AUTO) {
		rc = efx->phy_op->reconfigure(efx);
		if (rc) {
			netif_err(efx, drv, efx->net_dev,
				  "Unable to advertise requested flow "
				  "control setting\n");
			efx->link_advertising[0] = old_adv;
			efx->wanted_fc = old_fc;
			goto out;
		}
	}

	/* Reconfigure the MAC. The PHY *may* generate a link state change event
	 * if the user just changed the advertised capabilities, but there's no
	 * harm doing this twice */
	(void)efx_mac_reconfigure(efx, false);

out:
	mutex_unlock(&efx->mac_lock);

	return rc;
}

static void efx_ethtool_get_pauseparam(struct net_device *net_dev,
				       struct ethtool_pauseparam *pause)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	pause->rx_pause = !!(efx->wanted_fc & EFX_FC_RX);
	pause->tx_pause = !!(efx->wanted_fc & EFX_FC_TX);
	pause->autoneg = !!(efx->wanted_fc & EFX_FC_AUTO);
}

static void efx_ethtool_get_wol(struct net_device *net_dev,
				struct ethtool_wolinfo *wol)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	return efx->type->get_wol(efx, wol);
}


static int efx_ethtool_set_wol(struct net_device *net_dev,
			       struct ethtool_wolinfo *wol)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	return efx->type->set_wol(efx, wol->wolopts);
}

#if defined(EFX_USE_KCOMPAT) && !defined(EFX_HAVE_ETHTOOL_RESET)
int efx_ethtool_reset(struct net_device *net_dev, u32 *flags)
#else
static int efx_ethtool_reset(struct net_device *net_dev, u32 *flags)
#endif
{
	struct efx_nic *efx = netdev_priv(net_dev);
	u32 reset_flags = *flags;
	int rc;

	rc = efx->type->map_reset_flags(&reset_flags);
	if (rc >= 0) {
		rc = efx_reset(efx, rc);
		/* Manual resets can be done as often as you like */
		efx->reset_count = 0;
		/* update *flags if reset succeeded */
		if (!rc)
			*flags = reset_flags;
	}

	if (*flags & ETH_RESET_MAC) {
		netif_info(efx, drv, efx->net_dev,
			   "Resetting statistics.\n");
		efx->stats_initialised = false;
		efx->type->pull_stats(efx);
		*flags &= ~ETH_RESET_MAC;
		rc = 0;
	}

	return rc;
}

/* MAC address mask including only I/G bit */
static const u8 mac_addr_ig_mask[ETH_ALEN] __aligned(2) = {0x01, 0, 0, 0, 0, 0};

#define IP4_ADDR_FULL_MASK	((__force __be32)~0)
#define IP_PROTO_FULL_MASK	0xFF
#define PORT_FULL_MASK		((__force __be16)~0)
#define ETHER_TYPE_FULL_MASK	((__force __be16)~0)

static inline void ip6_fill_mask(__be32 *mask)
{
	mask[0] = mask[1] = mask[2] = mask[3] = ~(__be32)0;
}

#ifdef EFX_USE_KCOMPAT
static int efx_ethtool_get_class_rule(struct efx_nic *efx,
				      struct efx_ethtool_rx_flow_spec *rule,
				      u32 *rss_context)
#else
static int efx_ethtool_get_class_rule(struct efx_nic *efx,
				      struct ethtool_rx_flow_spec *rule,
				      u32 *rss_context)
#endif
{
	struct ethtool_tcpip4_spec *ip_entry = &rule->h_u.tcp_ip4_spec;
	struct ethtool_tcpip4_spec *ip_mask = &rule->m_u.tcp_ip4_spec;
	struct ethtool_usrip4_spec *uip_entry = &rule->h_u.usr_ip4_spec;
	struct ethtool_usrip4_spec *uip_mask = &rule->m_u.usr_ip4_spec;
#if defined(EFX_USE_KCOMPAT) && defined(EFX_NEED_IPV6_NFC)
	struct ethtool_tcpip6_spec *ip6_entry = (void *)&rule->h_u;
	struct ethtool_tcpip6_spec *ip6_mask = (void *)&rule->m_u;
	struct ethtool_usrip6_spec *uip6_entry = (void *)&rule->h_u;
	struct ethtool_usrip6_spec *uip6_mask = (void *)&rule->m_u;
#else
	struct ethtool_tcpip6_spec *ip6_entry = &rule->h_u.tcp_ip6_spec;
	struct ethtool_tcpip6_spec *ip6_mask = &rule->m_u.tcp_ip6_spec;
	struct ethtool_usrip6_spec *uip6_entry = &rule->h_u.usr_ip6_spec;
	struct ethtool_usrip6_spec *uip6_mask = &rule->m_u.usr_ip6_spec;
#endif
	struct ethhdr *mac_entry = &rule->h_u.ether_spec;
	struct ethhdr *mac_mask = &rule->m_u.ether_spec;
	struct efx_filter_spec spec;
	int rc;

	rc = efx_filter_get_filter_safe(efx, EFX_FILTER_PRI_MANUAL,
					rule->location, &spec);
	if (rc)
		return rc;

	if (spec.dmaq_id == EFX_FILTER_RX_DMAQ_ID_DROP)
		rule->ring_cookie = RX_CLS_FLOW_DISC;
	else
		rule->ring_cookie = spec.dmaq_id;

	if ((spec.match_flags & EFX_FILTER_MATCH_ETHER_TYPE) &&
	    spec.ether_type == htons(ETH_P_IP) &&
	    (spec.match_flags & EFX_FILTER_MATCH_IP_PROTO) &&
	    (spec.ip_proto == IPPROTO_TCP || spec.ip_proto == IPPROTO_UDP) &&
	    !(spec.match_flags &
	      ~(EFX_FILTER_MATCH_ETHER_TYPE | EFX_FILTER_MATCH_OUTER_VID |
		EFX_FILTER_MATCH_LOC_HOST | EFX_FILTER_MATCH_REM_HOST |
		EFX_FILTER_MATCH_IP_PROTO |
		EFX_FILTER_MATCH_LOC_PORT | EFX_FILTER_MATCH_REM_PORT))) {
		rule->flow_type = ((spec.ip_proto == IPPROTO_TCP) ?
				   TCP_V4_FLOW : UDP_V4_FLOW);
		if (spec.match_flags & EFX_FILTER_MATCH_LOC_HOST) {
			ip_entry->ip4dst = spec.loc_host[0];
			ip_mask->ip4dst = IP4_ADDR_FULL_MASK;
		}
		if (spec.match_flags & EFX_FILTER_MATCH_REM_HOST) {
			ip_entry->ip4src = spec.rem_host[0];
			ip_mask->ip4src = IP4_ADDR_FULL_MASK;
		}
		if (spec.match_flags & EFX_FILTER_MATCH_LOC_PORT) {
			ip_entry->pdst = spec.loc_port;
			ip_mask->pdst = PORT_FULL_MASK;
		}
		if (spec.match_flags & EFX_FILTER_MATCH_REM_PORT) {
			ip_entry->psrc = spec.rem_port;
			ip_mask->psrc = PORT_FULL_MASK;
		}
	} else if ((spec.match_flags & EFX_FILTER_MATCH_ETHER_TYPE) &&
	    spec.ether_type == htons(ETH_P_IPV6) &&
	    (spec.match_flags & EFX_FILTER_MATCH_IP_PROTO) &&
	    (spec.ip_proto == IPPROTO_TCP || spec.ip_proto == IPPROTO_UDP) &&
	    !(spec.match_flags &
	      ~(EFX_FILTER_MATCH_ETHER_TYPE | EFX_FILTER_MATCH_OUTER_VID |
		EFX_FILTER_MATCH_LOC_HOST | EFX_FILTER_MATCH_REM_HOST |
		EFX_FILTER_MATCH_IP_PROTO |
		EFX_FILTER_MATCH_LOC_PORT | EFX_FILTER_MATCH_REM_PORT))) {
		rule->flow_type = ((spec.ip_proto == IPPROTO_TCP) ?
				   TCP_V6_FLOW : UDP_V6_FLOW);
		if (spec.match_flags & EFX_FILTER_MATCH_LOC_HOST) {
			memcpy(ip6_entry->ip6dst, spec.loc_host,
			       sizeof(ip6_entry->ip6dst));
			ip6_fill_mask(ip6_mask->ip6dst);
		}
		if (spec.match_flags & EFX_FILTER_MATCH_REM_HOST) {
			memcpy(ip6_entry->ip6src, spec.rem_host,
			       sizeof(ip6_entry->ip6src));
			ip6_fill_mask(ip6_mask->ip6src);
		}
		if (spec.match_flags & EFX_FILTER_MATCH_LOC_PORT) {
			ip6_entry->pdst = spec.loc_port;
			ip6_mask->pdst = PORT_FULL_MASK;
		}
		if (spec.match_flags & EFX_FILTER_MATCH_REM_PORT) {
			ip6_entry->psrc = spec.rem_port;
			ip6_mask->psrc = PORT_FULL_MASK;
		}
	} else if (!(spec.match_flags &
		     ~(EFX_FILTER_MATCH_LOC_MAC | EFX_FILTER_MATCH_LOC_MAC_IG |
		       EFX_FILTER_MATCH_REM_MAC | EFX_FILTER_MATCH_ETHER_TYPE |
		       EFX_FILTER_MATCH_OUTER_VID))) {
		rule->flow_type = ETHER_FLOW;
		if (spec.match_flags &
		    (EFX_FILTER_MATCH_LOC_MAC | EFX_FILTER_MATCH_LOC_MAC_IG)) {
			ether_addr_copy(mac_entry->h_dest, spec.loc_mac);
			if (spec.match_flags & EFX_FILTER_MATCH_LOC_MAC)
				eth_broadcast_addr(mac_mask->h_dest);
			else
				ether_addr_copy(mac_mask->h_dest, mac_addr_ig_mask);
		}
		if (spec.match_flags & EFX_FILTER_MATCH_REM_MAC) {
			ether_addr_copy(mac_entry->h_source, spec.rem_mac);
			eth_broadcast_addr(mac_mask->h_source);
		}
		if (spec.match_flags & EFX_FILTER_MATCH_ETHER_TYPE) {
			mac_entry->h_proto = spec.ether_type;
			mac_mask->h_proto = ETHER_TYPE_FULL_MASK;
		}
	} else if (spec.match_flags & EFX_FILTER_MATCH_ETHER_TYPE &&
		   spec.ether_type == htons(ETH_P_IP)) {
		rule->flow_type = IP_USER_FLOW;
		uip_entry->ip_ver = ETH_RX_NFC_IP4;
		if (spec.match_flags & EFX_FILTER_MATCH_IP_PROTO) {
			uip_mask->proto = IP_PROTO_FULL_MASK;
			uip_entry->proto = spec.ip_proto;
		}
		if (spec.match_flags & EFX_FILTER_MATCH_LOC_HOST) {
			uip_entry->ip4dst = spec.loc_host[0];
			uip_mask->ip4dst = IP4_ADDR_FULL_MASK;
		}
		if (spec.match_flags & EFX_FILTER_MATCH_REM_HOST) {
			uip_entry->ip4src = spec.rem_host[0];
			uip_mask->ip4src = IP4_ADDR_FULL_MASK;
		}
	} else if (spec.match_flags & EFX_FILTER_MATCH_ETHER_TYPE &&
		   spec.ether_type == htons(ETH_P_IPV6)) {
		rule->flow_type = IPV6_USER_FLOW;
		if (spec.match_flags & EFX_FILTER_MATCH_IP_PROTO) {
			uip6_mask->l4_proto = IP_PROTO_FULL_MASK;
			uip6_entry->l4_proto = spec.ip_proto;
		}
		if (spec.match_flags & EFX_FILTER_MATCH_LOC_HOST) {
			memcpy(uip6_entry->ip6dst, spec.loc_host,
			       sizeof(uip6_entry->ip6dst));
			ip6_fill_mask(uip6_mask->ip6dst);
		}
		if (spec.match_flags & EFX_FILTER_MATCH_REM_HOST) {
			memcpy(uip6_entry->ip6src, spec.rem_host,
			       sizeof(uip6_entry->ip6src));
			ip6_fill_mask(uip6_mask->ip6src);
		}
	} else {
		/* The above should handle all filters that we insert */
		WARN_ON(1);
		return -EINVAL;
	}

	if (spec.match_flags & EFX_FILTER_MATCH_OUTER_VID) {
		rule->flow_type |= FLOW_EXT;
		rule->h_ext.vlan_tci = spec.outer_vid;
		rule->m_ext.vlan_tci = htons(0xfff);
	}

	if (spec.flags & EFX_FILTER_FLAG_RX_RSS) {
		rule->flow_type |= FLOW_RSS;
		*rss_context = spec.rss_context;
	}

	return rc;
}

#ifdef EFX_USE_KCOMPAT
int
efx_ethtool_get_rxnfc(struct net_device *net_dev,
		      struct efx_ethtool_rxnfc *info, u32 *rule_locs)
#else
static int
efx_ethtool_get_rxnfc(struct net_device *net_dev,
		      struct ethtool_rxnfc *info, u32 *rule_locs)
#endif
{
	struct efx_nic *efx = netdev_priv(net_dev);
	u32 rss_context = 0;
	s32 rc = 0;

	switch (info->cmd) {
	case ETHTOOL_GRXRINGS:
		info->data = efx->n_rss_channels;
		return 0;

	case ETHTOOL_GRXFH: {
		struct efx_rss_context *ctx = &efx->rss_context;

		mutex_lock(&efx->rss_lock);
		if (info->flow_type & FLOW_RSS && info->rss_context) {
			ctx = efx_find_rss_context_entry(efx, info->rss_context);
			if (!ctx) {
				rc = -ENOENT;
				goto out_unlock;
			}
		}
		info->data = 0;
		if (!efx_rss_active(ctx)) /* No RSS */
			goto out_unlock;
		if (efx->type->rx_get_rss_flags) {
			int rc;

			rc = efx->type->rx_get_rss_flags(efx, ctx);
			if (rc)
				goto out_unlock;
		}
		if (ctx->flags & RSS_CONTEXT_FLAGS_ADDITIONAL_MASK) {
			int shift;
			u8 mode;

			switch (info->flow_type & ~FLOW_RSS) {
			case TCP_V4_FLOW:
				shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TCP_IPV4_RSS_MODE_LBN;
				break;
			case UDP_V4_FLOW:
				shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_UDP_IPV4_RSS_MODE_LBN;
				break;
			case SCTP_V4_FLOW:
			case AH_ESP_V4_FLOW:
			case IPV4_FLOW:
				shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_OTHER_IPV4_RSS_MODE_LBN;
				break;
			case TCP_V6_FLOW:
				shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TCP_IPV6_RSS_MODE_LBN;
				break;
			case UDP_V6_FLOW:
				shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_UDP_IPV6_RSS_MODE_LBN;
				break;
			case SCTP_V6_FLOW:
			case AH_ESP_V6_FLOW:
			case IPV6_FLOW:
				shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_OTHER_IPV6_RSS_MODE_LBN;
				break;
			default:
				goto out_unlock;
			}
			mode = ctx->flags >> shift;
			if (mode & (1 << RSS_MODE_HASH_SRC_ADDR_LBN))
				info->data |= RXH_IP_SRC;
			if (mode & (1 << RSS_MODE_HASH_DST_ADDR_LBN))
				info->data |= RXH_IP_DST;
			if (mode & (1 << RSS_MODE_HASH_SRC_PORT_LBN))
				info->data |= RXH_L4_B_0_1;
			if (mode & (1 << RSS_MODE_HASH_DST_PORT_LBN))
				info->data |= RXH_L4_B_2_3;
		} else {
			switch (info->flow_type & ~FLOW_RSS) {
			case TCP_V4_FLOW:
				info->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
				/* fall through */
			case UDP_V4_FLOW:
			case SCTP_V4_FLOW:
			case AH_ESP_V4_FLOW:
			case IPV4_FLOW:
				info->data |= RXH_IP_SRC | RXH_IP_DST;
				break;
			case TCP_V6_FLOW:
				info->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
				/* fall through */
			case UDP_V6_FLOW:
			case SCTP_V6_FLOW:
			case AH_ESP_V6_FLOW:
			case IPV6_FLOW:
				info->data |= RXH_IP_SRC | RXH_IP_DST;
				break;
			default:
				break;
			}
		}
out_unlock:
		mutex_unlock(&efx->rss_lock);
		return rc;
	}

	case ETHTOOL_GRXCLSRLCNT:
		info->data = efx_filter_get_rx_id_limit(efx);
		if (info->data == 0)
			return -EOPNOTSUPP;
		info->data |= RX_CLS_LOC_SPECIAL;
		info->rule_cnt =
			efx_filter_count_rx_used(efx, EFX_FILTER_PRI_MANUAL);
		return 0;

	case ETHTOOL_GRXCLSRULE:
		if (efx_filter_get_rx_id_limit(efx) == 0)
			return -EOPNOTSUPP;
		rc = efx_ethtool_get_class_rule(efx, &info->fs, &rss_context);
		if (rc < 0)
			return rc;
		if (info->fs.flow_type & FLOW_RSS)
			info->rss_context = rss_context;
		return 0;

	case ETHTOOL_GRXCLSRLALL:
		info->data = efx_filter_get_rx_id_limit(efx);
		if (info->data == 0)
			return -EOPNOTSUPP;
		rc = efx_filter_get_rx_ids(efx, EFX_FILTER_PRI_MANUAL,
					   rule_locs, info->rule_cnt);
		if (rc < 0)
			return rc;
		info->rule_cnt = rc;
		return 0;

	default:
		return -EOPNOTSUPP;
	}
}

#if defined(EFX_USE_KCOMPAT) && !defined(EFX_HAVE_ETHTOOL_RXFH_CONTEXT)
int efx_sfctool_get_rxnfc(struct efx_nic *efx,
			  struct efx_ethtool_rxnfc *info, u32 *rule_locs)
{
	return efx_ethtool_get_rxnfc(efx->net_dev, info, rule_locs);
}
#endif

#if defined(EFX_USE_KCOMPAT) && defined(EFX_HAVE_ETHTOOL_RXNFC)
static int efx_ethtool_get_rxnfc_wrapper(struct net_device *net_dev,
					 struct ethtool_rxnfc *info,
#ifdef EFX_HAVE_OLD_ETHTOOL_GET_RXNFC
					 void *rules)
#else
					 u32 *rules)
#endif
{
	return efx_ethtool_get_rxnfc(net_dev, (struct efx_ethtool_rxnfc *)info,
				     rules);
}
static int efx_ethtool_set_rxnfc_wrapper(struct net_device *net_dev,
					 struct ethtool_rxnfc *info)
{
	return efx_ethtool_set_rxnfc(net_dev, (struct efx_ethtool_rxnfc *)info);
}
#endif

static inline bool ip6_mask_is_full(__be32 mask[4])
{
	return !~(mask[0] & mask[1] & mask[2] & mask[3]);
}

static inline bool ip6_mask_is_empty(__be32 mask[4])
{
	return !(mask[0] | mask[1] | mask[2] | mask[3]);
}

#ifdef EFX_USE_KCOMPAT
static int efx_ethtool_set_class_rule(struct efx_nic *efx,
				      struct efx_ethtool_rx_flow_spec *rule,
				      u32 rss_context)
#else
static int efx_ethtool_set_class_rule(struct efx_nic *efx,
				      struct ethtool_rx_flow_spec *rule,
				      u32 rss_context)
#endif
{
	struct ethtool_tcpip4_spec *ip_entry = &rule->h_u.tcp_ip4_spec;
	struct ethtool_tcpip4_spec *ip_mask = &rule->m_u.tcp_ip4_spec;
	struct ethtool_usrip4_spec *uip_entry = &rule->h_u.usr_ip4_spec;
	struct ethtool_usrip4_spec *uip_mask = &rule->m_u.usr_ip4_spec;
#if defined(EFX_USE_KCOMPAT) && defined(EFX_NEED_IPV6_NFC)
	struct ethtool_tcpip6_spec *ip6_entry = (void *)&rule->h_u;
	struct ethtool_tcpip6_spec *ip6_mask = (void *)&rule->m_u;
	struct ethtool_usrip6_spec *uip6_entry = (void *)&rule->h_u;
	struct ethtool_usrip6_spec *uip6_mask = (void *)&rule->m_u;
#else
	struct ethtool_tcpip6_spec *ip6_entry = &rule->h_u.tcp_ip6_spec;
	struct ethtool_tcpip6_spec *ip6_mask = &rule->m_u.tcp_ip6_spec;
	struct ethtool_usrip6_spec *uip6_entry = &rule->h_u.usr_ip6_spec;
	struct ethtool_usrip6_spec *uip6_mask = &rule->m_u.usr_ip6_spec;
#endif
	u32 flow_type = rule->flow_type & ~(FLOW_EXT | FLOW_RSS);
	struct ethhdr *mac_entry = &rule->h_u.ether_spec;
	struct ethhdr *mac_mask = &rule->m_u.ether_spec;
	enum efx_filter_flags flags = 0;
	struct efx_filter_spec spec;
	int rc;

	/* Check that user wants us to choose the location */
	if (rule->location != RX_CLS_LOC_ANY)
		return -EINVAL;

	/* Range-check ring_cookie */
	if (rule->ring_cookie >= efx->n_rx_channels &&
	    rule->ring_cookie != RX_CLS_FLOW_DISC)
		return -EINVAL;

	/* Check for unsupported extensions */
	if ((rule->flow_type & FLOW_EXT) &&
	    (rule->m_ext.vlan_etype || rule->m_ext.data[0] ||
	     rule->m_ext.data[1]))
		return -EINVAL;

	if (efx->rx_scatter)
		flags |= EFX_FILTER_FLAG_RX_SCATTER;
	if (rule->flow_type & FLOW_RSS)
		flags |= EFX_FILTER_FLAG_RX_RSS;

	efx_filter_init_rx(&spec, EFX_FILTER_PRI_MANUAL, flags,
			   (rule->ring_cookie == RX_CLS_FLOW_DISC) ?
			   EFX_FILTER_RX_DMAQ_ID_DROP : rule->ring_cookie);

	if (rule->flow_type & FLOW_RSS)
		spec.rss_context = rss_context;

	switch (flow_type) {
	case TCP_V4_FLOW:
	case UDP_V4_FLOW:
		spec.match_flags = (EFX_FILTER_MATCH_ETHER_TYPE |
				    EFX_FILTER_MATCH_IP_PROTO);
		spec.ether_type = htons(ETH_P_IP);
		spec.ip_proto = flow_type == TCP_V4_FLOW ? IPPROTO_TCP
							 : IPPROTO_UDP;
		if (ip_mask->ip4dst) {
			if (ip_mask->ip4dst != IP4_ADDR_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_LOC_HOST;
			spec.loc_host[0] = ip_entry->ip4dst;
		}
		if (ip_mask->ip4src) {
			if (ip_mask->ip4src != IP4_ADDR_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_REM_HOST;
			spec.rem_host[0] = ip_entry->ip4src;
		}
		if (ip_mask->pdst) {
			if (ip_mask->pdst != PORT_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_LOC_PORT;
			spec.loc_port = ip_entry->pdst;
		}
		if (ip_mask->psrc) {
			if (ip_mask->psrc != PORT_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_REM_PORT;
			spec.rem_port = ip_entry->psrc;
		}
		if (ip_mask->tos)
			return -EINVAL;
		break;

	case TCP_V6_FLOW:
	case UDP_V6_FLOW:
		spec.match_flags = (EFX_FILTER_MATCH_ETHER_TYPE |
				    EFX_FILTER_MATCH_IP_PROTO);
		spec.ether_type = htons(ETH_P_IPV6);
		spec.ip_proto = flow_type == TCP_V6_FLOW ? IPPROTO_TCP
							 : IPPROTO_UDP;
		if (!ip6_mask_is_empty(ip6_mask->ip6dst)) {
			if (!ip6_mask_is_full(ip6_mask->ip6dst))
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_LOC_HOST;
			memcpy(spec.loc_host, ip6_entry->ip6dst, sizeof(spec.loc_host));
		}
		if (!ip6_mask_is_empty(ip6_mask->ip6src)) {
			if (!ip6_mask_is_full(ip6_mask->ip6src))
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_REM_HOST;
			memcpy(spec.rem_host, ip6_entry->ip6src, sizeof(spec.rem_host));
		}
		if (ip6_mask->pdst) {
			if (ip6_mask->pdst != PORT_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_LOC_PORT;
			spec.loc_port = ip6_entry->pdst;
		}
		if (ip6_mask->psrc) {
			if (ip6_mask->psrc != PORT_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_REM_PORT;
			spec.rem_port = ip6_entry->psrc;
		}
		if (ip6_mask->tclass)
			return -EINVAL;
		break;

	case IP_USER_FLOW:
		if (uip_mask->l4_4_bytes || uip_mask->tos || uip_mask->ip_ver ||
		    uip_entry->ip_ver != ETH_RX_NFC_IP4)
			return -EINVAL;
		spec.match_flags = EFX_FILTER_MATCH_ETHER_TYPE;
		spec.ether_type = htons(ETH_P_IP);
		if (uip_mask->ip4dst) {
			if (uip_mask->ip4dst != IP4_ADDR_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_LOC_HOST;
			spec.loc_host[0] = uip_entry->ip4dst;
		}
		if (uip_mask->ip4src) {
			if (uip_mask->ip4src != IP4_ADDR_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_REM_HOST;
			spec.rem_host[0] = uip_entry->ip4src;
		}
		if (uip_mask->proto) {
			if (uip_mask->proto != IP_PROTO_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_IP_PROTO;
			spec.ip_proto = uip_entry->proto;
		}
		break;

	case IPV6_USER_FLOW:
		if (uip6_mask->l4_4_bytes || uip6_mask->tclass)
			return -EINVAL;
		spec.match_flags = EFX_FILTER_MATCH_ETHER_TYPE;
		spec.ether_type = htons(ETH_P_IPV6);
		if (!ip6_mask_is_empty(uip6_mask->ip6dst)) {
			if (!ip6_mask_is_full(uip6_mask->ip6dst))
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_LOC_HOST;
			memcpy(spec.loc_host, uip6_entry->ip6dst, sizeof(spec.loc_host));
		}
		if (!ip6_mask_is_empty(uip6_mask->ip6src)) {
			if (!ip6_mask_is_full(uip6_mask->ip6src))
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_REM_HOST;
			memcpy(spec.rem_host, uip6_entry->ip6src, sizeof(spec.rem_host));
		}
		if (uip6_mask->l4_proto) {
			if (uip6_mask->l4_proto != IP_PROTO_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_IP_PROTO;
			spec.ip_proto = uip6_entry->l4_proto;
		}
		break;

	case ETHER_FLOW:
		if (!is_zero_ether_addr(mac_mask->h_dest)) {
			if (ether_addr_equal(mac_mask->h_dest,
					     mac_addr_ig_mask))
				spec.match_flags |= EFX_FILTER_MATCH_LOC_MAC_IG;
			else if (is_broadcast_ether_addr(mac_mask->h_dest))
				spec.match_flags |= EFX_FILTER_MATCH_LOC_MAC;
			else
				return -EINVAL;
			ether_addr_copy(spec.loc_mac, mac_entry->h_dest);
		}
		if (!is_zero_ether_addr(mac_mask->h_source)) {
			if (!is_broadcast_ether_addr(mac_mask->h_source))
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_REM_MAC;
			ether_addr_copy(spec.rem_mac, mac_entry->h_source);
		}
		if (mac_mask->h_proto) {
			if (mac_mask->h_proto != ETHER_TYPE_FULL_MASK)
				return -EINVAL;
			spec.match_flags |= EFX_FILTER_MATCH_ETHER_TYPE;
			spec.ether_type = mac_entry->h_proto;
		}
		break;

	default:
		return -EINVAL;
	}

	if ((rule->flow_type & FLOW_EXT) && rule->m_ext.vlan_tci) {
		if (rule->m_ext.vlan_tci != htons(0xfff))
			return -EINVAL;
		spec.match_flags |= EFX_FILTER_MATCH_OUTER_VID;
		spec.outer_vid = rule->h_ext.vlan_tci;
	}

	rc = efx_filter_insert_filter(efx, &spec, true);
	if (rc < 0)
		return rc;

	rule->location = rc;
	return 0;
}

/* Convert old-style _EN RSS flags into new style _MODE flags */
static u32 efx_ethtool_convert_old_rss_flags(u32 old_flags)
{
	u32 flags = 0;

	if (old_flags & (1 << MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_IPV4_EN_LBN))
		flags |= RSS_MODE_HASH_ADDRS << MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_UDP_IPV4_RSS_MODE_LBN |\
			 RSS_MODE_HASH_ADDRS << MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_OTHER_IPV4_RSS_MODE_LBN;
	if (old_flags & (1 << MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_TCPV4_EN_LBN))
		flags |= RSS_MODE_HASH_4TUPLE << MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TCP_IPV4_RSS_MODE_LBN;
	if (old_flags & (1 << MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_IPV6_EN_LBN))
		flags |= RSS_MODE_HASH_ADDRS << MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_UDP_IPV6_RSS_MODE_LBN |\
			 RSS_MODE_HASH_ADDRS << MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_OTHER_IPV6_RSS_MODE_LBN;
	if (old_flags & (1 << MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_TCPV6_EN_LBN))
		flags |= RSS_MODE_HASH_4TUPLE << MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TCP_IPV6_RSS_MODE_LBN;
	return flags;
}

static int efx_ethtool_set_rss_flags(struct efx_nic *efx,
#ifdef EFX_USE_KCOMPAT
				     struct efx_ethtool_rxnfc *info)
#else
				     struct ethtool_rxnfc *info)
#endif
{
	struct efx_rss_context *ctx = &efx->rss_context;
	u32 flags, mode = 0;
	int shift, rc = 0;

	if (!efx->type->rx_set_rss_flags)
		return -EOPNOTSUPP;
	if (!efx->type->rx_get_rss_flags)
		return -EOPNOTSUPP;
	mutex_lock(&efx->rss_lock);
	if (info->flow_type & FLOW_RSS && info->rss_context) {
		ctx = efx_find_rss_context_entry(efx, info->rss_context);
		if (!ctx) {
			rc = -ENOENT;
			goto out_unlock;
		}
	}
	efx->type->rx_get_rss_flags(efx, ctx);
	flags = ctx->flags;
	if (!(flags & RSS_CONTEXT_FLAGS_ADDITIONAL_MASK))
		flags = efx_ethtool_convert_old_rss_flags(flags);
	/* In case we end up clearing all additional flags (meaning we
	 * want no RSS), make sure the old-style flags are cleared too.
	 */
	flags &= RSS_CONTEXT_FLAGS_ADDITIONAL_MASK;

	switch (info->flow_type & ~FLOW_RSS) {
	case TCP_V4_FLOW:
		shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TCP_IPV4_RSS_MODE_LBN;
		break;
	case UDP_V4_FLOW:
		shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_UDP_IPV4_RSS_MODE_LBN;
		break;
	case SCTP_V4_FLOW:
	case AH_ESP_V4_FLOW:
		/* Can't configure independently of other-IPv4 */
		rc = -EOPNOTSUPP;
		goto out_unlock;
	case IPV4_FLOW:
		shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_OTHER_IPV4_RSS_MODE_LBN;
		break;
	case TCP_V6_FLOW:
		shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TCP_IPV6_RSS_MODE_LBN;
		break;
	case UDP_V6_FLOW:
		shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_UDP_IPV6_RSS_MODE_LBN;
		break;
	case SCTP_V6_FLOW:
	case AH_ESP_V6_FLOW:
		/* Can't configure independently of other-IPv6 */
		rc = -EOPNOTSUPP;
		goto out_unlock;
	case IPV6_FLOW:
		shift = MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_OTHER_IPV6_RSS_MODE_LBN;
		break;
	default:
		rc = -EOPNOTSUPP;
		goto out_unlock;
	}

	/* Clear the old flags for this flow_type */
	BUILD_BUG_ON(MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TCP_IPV4_RSS_MODE_WIDTH != 4);
	flags &= ~(0xf << shift);
	/* Construct new flags */
	if (info->data & RXH_IP_SRC)
		mode |= 1 << RSS_MODE_HASH_SRC_ADDR_LBN;
	if (info->data & RXH_IP_DST)
		mode |= 1 << RSS_MODE_HASH_DST_ADDR_LBN;
	if (info->data & RXH_L4_B_0_1)
		mode |= 1 << RSS_MODE_HASH_SRC_PORT_LBN;
	if (info->data & RXH_L4_B_2_3)
		mode |= 1 << RSS_MODE_HASH_DST_PORT_LBN;
	flags |= mode << shift;
	rc = efx->type->rx_set_rss_flags(efx, ctx, flags);
out_unlock:
	mutex_unlock(&efx->rss_lock);
	return rc;
}

#ifdef EFX_USE_KCOMPAT
int efx_ethtool_set_rxnfc(struct net_device *net_dev,
			  struct efx_ethtool_rxnfc *info)
#else
static int efx_ethtool_set_rxnfc(struct net_device *net_dev,
				 struct ethtool_rxnfc *info)
#endif
{
	struct efx_nic *efx = netdev_priv(net_dev);

	if (efx_filter_get_rx_id_limit(efx) == 0)
		return -EOPNOTSUPP;

	switch (info->cmd) {
	case ETHTOOL_SRXCLSRLINS:
		return efx_ethtool_set_class_rule(efx, &info->fs,
						  info->rss_context);

	case ETHTOOL_SRXCLSRLDEL:
		return efx_filter_remove_id_safe(efx, EFX_FILTER_PRI_MANUAL,
						 info->fs.location);

	case ETHTOOL_SRXFH:
		return efx_ethtool_set_rss_flags(efx, info);

	default:
		return -EOPNOTSUPP;
	}
}

static u32 efx_ethtool_get_rxfh_indir_size(struct net_device *net_dev)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	return ARRAY_SIZE(efx->rss_context.rx_indir_table);
}


static u32 efx_ethtool_get_rxfh_key_size(struct net_device *net_dev)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	return efx->type->rx_hash_key_size;
}

#if defined(EFX_USE_KCOMPAT) && !defined(EFX_HAVE_ETHTOOL_RXFH_CONTEXT)
u32 efx_sfctool_get_rxfh_indir_size(struct efx_nic *efx)
{
	return efx_ethtool_get_rxfh_indir_size(efx->net_dev);
}

u32 efx_sfctool_get_rxfh_key_size(struct efx_nic *efx)
{
	return efx_ethtool_get_rxfh_key_size(efx->net_dev);
}
#endif

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_GET_RXFH) || defined(EFX_HAVE_ETHTOOL_GET_RXFH_INDIR) || !defined(EFX_HAVE_ETHTOOL_RXFH_INDIR)
static int efx_ethtool_get_rxfh(struct net_device *net_dev, u32 *indir, u8 *key,
				u8 *hfunc)
{
	struct efx_nic *efx = netdev_priv(net_dev);
#else
int efx_sfctool_get_rxfh(struct efx_nic *efx, u32 *indir, u8 *key,
			 u8 *hfunc)
{
#endif
	int rc;

	rc = efx->type->rx_pull_rss_config(efx);
	if (rc)
		return rc;

	if (hfunc)
		*hfunc = ETH_RSS_HASH_TOP;
	if (indir)
		memcpy(indir, efx->rss_context.rx_indir_table,
		       sizeof(efx->rss_context.rx_indir_table));
	if (key)
		memcpy(key, efx->rss_context.rx_hash_key,
		       efx->type->rx_hash_key_size);
	return 0;
}

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_GET_RXFH) || defined(EFX_HAVE_ETHTOOL_GET_RXFH_INDIR) || !defined(EFX_HAVE_ETHTOOL_RXFH_INDIR)
static int efx_ethtool_set_rxfh(struct net_device *net_dev,
				const u32 *indir, const u8 *key, const u8 hfunc)
{
	struct efx_nic *efx = netdev_priv(net_dev);

#else
int efx_sfctool_set_rxfh(struct efx_nic *efx,
			 const u32 *indir, const u8 *key, const u8 hfunc)
{
#endif
	/* We do not allow change in unsupported parameters */
	if (hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP)
		return -EOPNOTSUPP;
	if (!indir && !key)
		return 0;

	if (!key)
		key = efx->rss_context.rx_hash_key;
	if (!indir)
		indir = efx->rss_context.rx_indir_table;

	return efx->type->rx_push_rss_config(efx, true, indir, key);
}

#if defined(EFX_USE_KCOMPAT)
#if defined(EFX_HAVE_ETHTOOL_GET_RXFH_INDIR) && !defined(EFX_HAVE_ETHTOOL_GET_RXFH) && !defined(EFX_HAVE_OLD_ETHTOOL_RXFH_INDIR)
/* Wrappers that only set the indirection table, not the key. */
static int efx_ethtool_get_rxfh_indir(struct net_device *net_dev, u32 *indir)
{
	return efx_ethtool_get_rxfh(net_dev, indir, NULL, NULL);
}

static int efx_ethtool_set_rxfh_indir(struct net_device *net_dev,
		const u32 *indir)
{
	return efx_ethtool_set_rxfh(net_dev, indir, NULL,
			ETH_RSS_HASH_NO_CHANGE);
}
#endif

#if defined(EFX_HAVE_ETHTOOL_GET_RXFH) && !defined(EFX_HAVE_CONFIGURABLE_RSS_HASH)
/* Wrappers without hash function getting and setting. */
static int efx_ethtool_get_rxfh_no_hfunc(struct net_device *net_dev, u32 *indir,
		u8 *key)
{
	return efx_ethtool_get_rxfh(net_dev, indir, key, NULL);
}

# if defined(EFX_HAVE_ETHTOOL_SET_RXFH_NOCONST)
/* RH backported version doesn't have const for arguments. */
static int efx_ethtool_set_rxfh_no_hfunc(struct net_device *net_dev,
		u32 *indir, u8 *key)
{
	return efx_ethtool_set_rxfh(net_dev, indir, key,
			ETH_RSS_HASH_NO_CHANGE);
}
# else
static int efx_ethtool_set_rxfh_no_hfunc(struct net_device *net_dev,
		const u32 *indir, const u8 *key)
{
	return efx_ethtool_set_rxfh(net_dev, indir, key,
			ETH_RSS_HASH_NO_CHANGE);
}
# endif
#endif

#if defined(EFX_HAVE_OLD_ETHTOOL_RXFH_INDIR) || !defined(EFX_HAVE_ETHTOOL_RXFH_INDIR)
int efx_ethtool_old_get_rxfh_indir(struct net_device *net_dev,
					  struct ethtool_rxfh_indir *indir)
{
	u32 user_size = indir->size, dev_size;

	dev_size = efx_ethtool_get_rxfh_indir_size(net_dev);
	if (dev_size == 0)
		return -EOPNOTSUPP;

	if (user_size < dev_size) {
		indir->size = dev_size;
		return user_size == 0 ? 0 : -EINVAL;
	}

	return efx_ethtool_get_rxfh(net_dev, indir->ring_index, NULL, NULL);
}

int efx_ethtool_old_set_rxfh_indir(struct net_device *net_dev,
					  const struct ethtool_rxfh_indir *indir)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	u32 user_size = indir->size, dev_size, i;

	dev_size = efx_ethtool_get_rxfh_indir_size(net_dev);
	if (dev_size == 0)
		return -EOPNOTSUPP;

	if (user_size != dev_size)
		return -EINVAL;

	/* Validate ring indices */
	for (i = 0; i < dev_size; i++)
		if (indir->ring_index[i] >= efx->n_rx_channels)
			return -EINVAL;

	return efx_ethtool_set_rxfh(net_dev, indir->ring_index, NULL,
			ETH_RSS_HASH_NO_CHANGE);
}
#endif
#endif

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_RXFH_CONTEXT)
static int efx_ethtool_get_rxfh_context(struct net_device *net_dev, u32 *indir,
					u8 *key, u8 *hfunc, u32 rss_context)
{
	struct efx_nic *efx = netdev_priv(net_dev);
#else
int efx_sfctool_get_rxfh_context(struct efx_nic *efx, u32 *indir,
				 u8 *key, u8 *hfunc, u32 rss_context)
{
#endif
	struct efx_rss_context *ctx;
	int rc = 0;

	if (!efx->type->rx_pull_rss_context_config)
		return -EOPNOTSUPP;

	mutex_lock(&efx->rss_lock);
	ctx = efx_find_rss_context_entry(efx, rss_context);
	if (!ctx) {
		rc = -ENOENT;
		goto out_unlock;
	}
	rc = efx->type->rx_pull_rss_context_config(efx, ctx);
	if (rc)
		goto out_unlock;

	if (hfunc)
		*hfunc = ETH_RSS_HASH_TOP;
	if (indir)
		memcpy(indir, ctx->rx_indir_table, sizeof(ctx->rx_indir_table));
	if (key)
		memcpy(key, ctx->rx_hash_key, efx->type->rx_hash_key_size);
out_unlock:
	mutex_unlock(&efx->rss_lock);
	return rc;
}

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_RXFH_CONTEXT)
static int efx_ethtool_set_rxfh_context(struct net_device *net_dev,
					const u32 *indir, const u8 *key,
					const u8 hfunc, u32 *rss_context,
					bool delete)
{
	struct efx_nic *efx = netdev_priv(net_dev);
#else
int efx_sfctool_set_rxfh_context(struct efx_nic *efx,
				 const u32 *indir, const u8 *key,
				 const u8 hfunc, u32 *rss_context,
				 bool delete)
{
#endif
	struct efx_rss_context *ctx;
	bool allocated = false;
	int rc;

	if (!efx->type->rx_push_rss_context_config)
		return -EOPNOTSUPP;
	/* Hash function is Toeplitz, cannot be changed */
	if (hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP)
		return -EOPNOTSUPP;

	mutex_lock(&efx->rss_lock);

	if (*rss_context == ETH_RXFH_CONTEXT_ALLOC) {
		if (delete) {
			/* alloc + delete == Nothing to do */
			rc = -EINVAL;
			goto out_unlock;
		}
		ctx = efx_alloc_rss_context_entry(efx);
		if (!ctx) {
			rc = -ENOMEM;
			goto out_unlock;
		}
		ctx->context_id = EFX_EF10_RSS_CONTEXT_INVALID;
		/* Initialise indir table and key to defaults */
		efx_set_default_rx_indir_table(efx, ctx);
		netdev_rss_key_fill(ctx->rx_hash_key, sizeof(ctx->rx_hash_key));
		allocated = true;
	} else {
		ctx = efx_find_rss_context_entry(efx, *rss_context);
		if (!ctx) {
			rc = -ENOENT;
			goto out_unlock;
		}
	}

	if (delete) {
		/* delete this context */
		rc = efx->type->rx_push_rss_context_config(efx, ctx, NULL, NULL);
		if (!rc)
			efx_free_rss_context_entry(ctx);
		goto out_unlock;
	}

	if (!key)
		key = ctx->rx_hash_key;
	if (!indir)
		indir = ctx->rx_indir_table;

	rc = efx->type->rx_push_rss_context_config(efx, ctx, indir, key);
	if (rc && allocated)
		efx_free_rss_context_entry(ctx);
	else
		*rss_context = ctx->user_id;
out_unlock:
	mutex_unlock(&efx->rss_lock);
	return rc;
}

#ifdef CONFIG_SFC_DUMP
int efx_ethtool_get_dump_flag(struct net_device *net_dev,
			      struct ethtool_dump *dump)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	return efx_dump_get_flag(efx, dump);
}

int efx_ethtool_get_dump_data(struct net_device *net_dev,
			      struct ethtool_dump *dump, void *buffer)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	return efx_dump_get_data(efx, dump, buffer);
}

int efx_ethtool_set_dump(struct net_device *net_dev, struct ethtool_dump *val)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	return efx_dump_set(efx, val);
}
#endif

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_GET_TS_INFO) || defined(EFX_HAVE_ETHTOOL_EXT_GET_TS_INFO)
static
#endif
int efx_ethtool_get_ts_info(struct net_device *net_dev,
			    struct ethtool_ts_info *ts_info)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	/* Software capabilities */
	ts_info->so_timestamping = (SOF_TIMESTAMPING_RX_SOFTWARE |
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_SKB_TX_TIMESTAMP)
				    SOF_TIMESTAMPING_TX_SOFTWARE |
#endif
				    SOF_TIMESTAMPING_SOFTWARE);
	ts_info->phc_index = -1;

	efx_ptp_get_ts_info(efx, ts_info);
	return 0;
}

#ifdef EFX_USE_KCOMPAT
int efx_ethtool_get_module_eeprom(struct net_device *net_dev,
				  struct ethtool_eeprom *ee,
				  u8 *data)
#else
static int efx_ethtool_get_module_eeprom(struct net_device *net_dev,
					 struct ethtool_eeprom *ee,
					 u8 *data)
#endif
{
	struct efx_nic *efx = netdev_priv(net_dev);
	int ret;

	if (!efx->phy_op || !efx->phy_op->get_module_eeprom)
		return -EOPNOTSUPP;

	mutex_lock(&efx->mac_lock);
	ret = efx->phy_op->get_module_eeprom(efx, ee, data);
	mutex_unlock(&efx->mac_lock);

	return ret;
}

#ifdef EFX_USE_KCOMPAT
int efx_ethtool_get_module_info(struct net_device *net_dev,
				struct ethtool_modinfo *modinfo)
#else
static int efx_ethtool_get_module_info(struct net_device *net_dev,
				       struct ethtool_modinfo *modinfo)
#endif
{
	struct efx_nic *efx = netdev_priv(net_dev);
	int ret;

	if (!efx->phy_op || !efx->phy_op->get_module_info)
		return -EOPNOTSUPP;

	mutex_lock(&efx->mac_lock);
	ret = efx->phy_op->get_module_info(efx, modinfo);
	mutex_unlock(&efx->mac_lock);

	return ret;
}

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_CHANNELS) || defined(EFX_HAVE_ETHTOOL_EXT_CHANNELS)
static void efx_ethtool_get_channels(struct net_device *net_dev,
				     struct ethtool_channels *channels)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	unsigned int i, j;

	channels->max_combined = efx->max_channels;
	channels->max_rx = efx->max_channels;
	channels->max_tx = efx->max_tx_channels;

	channels->rx_count = min(efx->n_rx_channels, efx->tx_channel_offset);
	channels->combined_count = efx->n_rx_channels - channels->rx_count;
	channels->tx_count = efx->n_tx_channels - channels->combined_count;

	/* count up 'other' channels */
	channels->max_other = efx->n_xdp_channels;
	channels->other_count = efx->n_xdp_channels;
	for (i = 0; i < EFX_MAX_EXTRA_CHANNELS; i++) {
		if (!efx->extra_channel_type[i])
			continue;
		channels->max_other++;
		for (j = 0; j < EFX_MAX_EXTRA_CHANNELS; j++) {
			if (j >= efx->n_channels)
				continue;
			if (efx_get_channel(efx, efx->n_channels - j - 1)->type ==
					efx->extra_channel_type[i])
				channels->other_count++;
		}
	}
}
#endif

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_PRIV_FLAGS)
static u32 efx_ethtool_get_priv_flags(struct net_device *net_dev)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	u32 ret_flags = 0;

	if (efx->phy_power_follows_link)
		ret_flags |= EFX_ETHTOOL_PRIV_FLAGS_PHY_POWER;

	return ret_flags;
}

static int efx_ethtool_set_priv_flags(struct net_device *net_dev, u32 flags)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	bool phy_power;

	phy_power = !!(flags & EFX_ETHTOOL_PRIV_FLAGS_PHY_POWER);

	efx->phy_power_follows_link = phy_power;

	return 0;
}
#endif

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_LINKSETTINGS)
static int efx_ethtool_get_link_ksettings(struct net_device *net_dev,
					  struct ethtool_link_ksettings *out)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	if (!efx->phy_op->get_ksettings)
		return -EOPNOTSUPP;

	mutex_lock(&efx->mac_lock);
	efx->phy_op->get_ksettings(efx, out);
	mutex_unlock(&efx->mac_lock);

	return 0;
}

static int efx_ethtool_set_link_ksettings(struct net_device *net_dev,
					  const struct ethtool_link_ksettings *settings)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	int rc;

	if (!efx->phy_op->set_ksettings)
		return -EOPNOTSUPP;

	mutex_lock(&efx->mac_lock);
	rc = efx->phy_op->set_ksettings(efx, settings);
	mutex_unlock(&efx->mac_lock);

	return rc;
}
#endif

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_FECPARAM)
static int efx_ethtool_get_fecparam(struct net_device *net_dev,
				    struct ethtool_fecparam *fecparam)
{
	struct efx_nic *efx = netdev_priv(net_dev);
#else
int efx_sfctool_get_fecparam(struct efx_nic *efx,
			     struct ethtool_fecparam *fecparam)
{
#endif
	int rc;

	if (!efx->phy_op || !efx->phy_op->get_fecparam)
		return -EOPNOTSUPP;
	mutex_lock(&efx->mac_lock);
	rc = efx->phy_op->get_fecparam(efx, fecparam);
	mutex_unlock(&efx->mac_lock);

	return rc;
}

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_FECPARAM)
static int efx_ethtool_set_fecparam(struct net_device *net_dev,
				    struct ethtool_fecparam *fecparam)
{
	struct efx_nic *efx = netdev_priv(net_dev);
#else
int efx_sfctool_set_fecparam(struct efx_nic *efx,
			     struct ethtool_fecparam *fecparam)
{
#endif
	int rc;

	if (!efx->phy_op || !efx->phy_op->get_fecparam)
		return -EOPNOTSUPP;
	mutex_lock(&efx->mac_lock);
	rc = efx->phy_op->set_fecparam(efx, fecparam);
	mutex_unlock(&efx->mac_lock);

	return rc;
}

const struct ethtool_ops efx_ethtool_ops = {
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_COALESCE_PARAMS)
	.supported_coalesce_params = (ETHTOOL_COALESCE_USECS |
				      ETHTOOL_COALESCE_USECS_IRQ |
				      ETHTOOL_COALESCE_STATS_BLOCK_USECS |
				      ETHTOOL_COALESCE_USE_ADAPTIVE_RX),
#endif
#if defined(EFX_USE_KCOMPAT) && !defined(EFX_HAVE_ETHTOOL_LINKSETTINGS) || defined(EFX_HAVE_ETHTOOL_LEGACY)
	.get_settings		= efx_ethtool_get_settings,
	.set_settings		= efx_ethtool_set_settings,
#endif
	.get_drvinfo		= efx_ethtool_get_drvinfo,
	.get_regs_len		= efx_ethtool_get_regs_len,
	.get_regs		= efx_ethtool_get_regs,
	.get_msglevel		= efx_ethtool_get_msglevel,
	.set_msglevel		= efx_ethtool_set_msglevel,
	.nway_reset		= efx_ethtool_nway_reset,
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_USE_ETHTOOL_OP_GET_LINK)
	.get_link		= ethtool_op_get_link,
#else
	.get_link		= efx_ethtool_get_link,
#endif
	.get_coalesce		= efx_ethtool_get_coalesce,
	.set_coalesce		= efx_ethtool_set_coalesce,
	.get_ringparam		= efx_ethtool_get_ringparam,
	.set_ringparam		= efx_ethtool_set_ringparam,
	.get_pauseparam         = efx_ethtool_get_pauseparam,
	.set_pauseparam         = efx_ethtool_set_pauseparam,
#if defined(EFX_USE_KCOMPAT) && !defined(EFX_HAVE_NDO_SET_FEATURES) && !defined(EFX_HAVE_EXT_NDO_SET_FEATURES)
	.get_rx_csum		= efx_ethtool_get_rx_csum,
	.set_rx_csum		= efx_ethtool_set_rx_csum,
	.get_tx_csum		= ethtool_op_get_tx_csum,
	/* Need to enable/disable IPv6 too */
	.set_tx_csum		= efx_ethtool_set_tx_csum,
	.get_sg			= ethtool_op_get_sg,
	.set_sg			= ethtool_op_set_sg,
	.get_tso		= ethtool_op_get_tso,
	/* Need to enable/disable TSO-IPv6 too */
	.set_tso		= efx_ethtool_set_tso,
#if defined(EFX_USE_ETHTOOL_FLAGS)
	.get_flags		= ethtool_op_get_flags,
	.set_flags		= efx_ethtool_set_flags,
#endif
#endif /* EFX_HAVE_NDO_SET_FEATURES */
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_USE_ETHTOOL_GET_SSET_COUNT)
	.get_sset_count		= efx_ethtool_get_sset_count,
#else
	.self_test_count	= efx_ethtool_self_test_count,
	.get_stats_count	= efx_ethtool_get_stats_count,
#endif
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_PRIV_FLAGS)
	.get_priv_flags		= efx_ethtool_get_priv_flags,
	.set_priv_flags		= efx_ethtool_set_priv_flags,
#endif
	.self_test		= efx_ethtool_self_test,
	.get_strings		= efx_ethtool_get_strings,
#if !defined(EFX_USE_KCOMPAT) || (defined(EFX_HAVE_ETHTOOL_SET_PHYS_ID) && !defined(EFX_USE_ETHTOOL_OPS_EXT))
	.set_phys_id		= efx_ethtool_phys_id,
#elif !defined(EFX_USE_ETHTOOL_OPS_EXT)
	.phys_id		= efx_ethtool_phys_id_loop,
#endif
	.get_ethtool_stats	= efx_ethtool_get_stats,
#if defined(EFX_USE_KCOMPAT) && defined(EFX_USE_ETHTOOL_GET_PERM_ADDR)
	.get_perm_addr          = ethtool_op_get_perm_addr,
#endif
	.get_wol                = efx_ethtool_get_wol,
	.set_wol                = efx_ethtool_set_wol,
#if !defined(EFX_USE_KCOMPAT) || (defined(EFX_HAVE_ETHTOOL_RESET) && !defined(EFX_USE_ETHTOOL_OPS_EXT))
	.reset			= efx_ethtool_reset,
#endif
#if !defined(EFX_USE_KCOMPAT)
	.get_rxnfc		= efx_ethtool_get_rxnfc,
	.set_rxnfc		= efx_ethtool_set_rxnfc,
#elif defined(EFX_HAVE_ETHTOOL_RXNFC)
	.get_rxnfc		= efx_ethtool_get_rxnfc_wrapper,
	.set_rxnfc		= efx_ethtool_set_rxnfc_wrapper,
#endif
#if defined(EFX_USE_KCOMPAT) && defined(EFX_USE_ETHTOOL_OPS_EXT)
};
const struct ethtool_ops_ext efx_ethtool_ops_ext = {
	.size			= sizeof(struct ethtool_ops_ext),
	.set_phys_id		= efx_ethtool_phys_id,
	/* Do not set ethtool_ops_ext::reset due to RH BZ 1008678 (SF bug 39031) */
#endif

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_GET_RXFH_INDIR_SIZE)
	.get_rxfh_indir_size	= efx_ethtool_get_rxfh_indir_size,
#endif
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_GET_RXFH_KEY_SIZE)
	.get_rxfh_key_size	= efx_ethtool_get_rxfh_key_size,
#endif
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_CONFIGURABLE_RSS_HASH)
	.get_rxfh		= efx_ethtool_get_rxfh,
	.set_rxfh		= efx_ethtool_set_rxfh,
#elif defined(EFX_HAVE_ETHTOOL_GET_RXFH)
	.get_rxfh		= efx_ethtool_get_rxfh_no_hfunc,
	.set_rxfh		= efx_ethtool_set_rxfh_no_hfunc,
#elif defined(EFX_HAVE_ETHTOOL_GET_RXFH_INDIR)
# if defined(EFX_HAVE_OLD_ETHTOOL_RXFH_INDIR)
	.get_rxfh_indir		= efx_ethtool_old_get_rxfh_indir,
	.set_rxfh_indir		= efx_ethtool_old_set_rxfh_indir,
# else
	.get_rxfh_indir		= efx_ethtool_get_rxfh_indir,
	.set_rxfh_indir		= efx_ethtool_set_rxfh_indir,
# endif
#endif
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_RXFH_CONTEXT)
	.get_rxfh_context	= efx_ethtool_get_rxfh_context,
	.set_rxfh_context	= efx_ethtool_set_rxfh_context,
#endif
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_GET_DUMP_FLAG) || defined(EFX_HAVE_ETHTOOL_GET_DUMP_DATA) || defined(EFX_HAVE_ETHTOOL_SET_DUMP)
#ifdef CONFIG_SFC_DUMP
	.get_dump_flag		= efx_ethtool_get_dump_flag,
	.get_dump_data		= efx_ethtool_get_dump_data,
	.set_dump		= efx_ethtool_set_dump,
#endif
#endif

#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_GET_TS_INFO) || defined(EFX_HAVE_ETHTOOL_EXT_GET_TS_INFO)
	.get_ts_info		= efx_ethtool_get_ts_info,
#endif
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_GMODULEEEPROM)
	.get_module_info	= efx_ethtool_get_module_info,
	.get_module_eeprom	= efx_ethtool_get_module_eeprom,
#endif
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_CHANNELS) || defined(EFX_HAVE_ETHTOOL_EXT_CHANNELS)
	.get_channels		= efx_ethtool_get_channels,
#endif
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_LINKSETTINGS)
	.get_link_ksettings	= efx_ethtool_get_link_ksettings,
	.set_link_ksettings	= efx_ethtool_set_link_ksettings,
#endif
#if !defined(EFX_USE_KCOMPAT) || defined(EFX_HAVE_ETHTOOL_FECPARAM)
	.get_fecparam		= efx_ethtool_get_fecparam,
	.set_fecparam		= efx_ethtool_set_fecparam,
#endif
};
