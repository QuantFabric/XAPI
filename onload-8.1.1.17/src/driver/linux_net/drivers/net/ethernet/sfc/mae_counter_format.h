/****************************************************************************
 * Driver for Solarflare network controllers and boards
 * Copyright 2020 Xilinx, Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, incorporated herein by reference.
 */

/* Format of counter packets (version 2) from the ef100 Match-Action Engine */

#ifndef EFX_MAE_COUNTER_FORMAT_H
#define EFX_MAE_COUNTER_FORMAT_H


/*------------------------------------------------------------*/
/*
 * ER_RX_SL_PACKETISER_HEADER_WORD(160bit):
 * 
 */
#define ER_RX_SL_PACKETISER_HEADER_WORD_SIZE 20
#define ER_RX_SL_PACKETISER_HEADER_WORD_WIDTH 160

#define ERF_SC_PACKETISER_HEADER_VERSION_LBN 0
#define ERF_SC_PACKETISER_HEADER_VERSION_WIDTH 8
#define ERF_SC_PACKETISER_HEADER_VERSION_VALUE 2
#define ERF_SC_PACKETISER_HEADER_IDENTIFIER_LBN 8
#define ERF_SC_PACKETISER_HEADER_IDENTIFIER_WIDTH 8
#define ERF_SC_PACKETISER_HEADER_IDENTIFIER_AR 0
#define ERF_SC_PACKETISER_HEADER_IDENTIFIER_CT 1
#define ERF_SC_PACKETISER_HEADER_IDENTIFIER_OR 2
#define ERF_SC_PACKETISER_HEADER_HEADER_OFFSET_LBN 16
#define ERF_SC_PACKETISER_HEADER_HEADER_OFFSET_WIDTH 8
#define ERF_SC_PACKETISER_HEADER_HEADER_OFFSET_DEFAULT 0x4
#define ERF_SC_PACKETISER_HEADER_PAYLOAD_OFFSET_LBN 24
#define ERF_SC_PACKETISER_HEADER_PAYLOAD_OFFSET_WIDTH 8
#define ERF_SC_PACKETISER_HEADER_PAYLOAD_OFFSET_DEFAULT 0x14
#define ERF_SC_PACKETISER_HEADER_INDEX_LBN 32
#define ERF_SC_PACKETISER_HEADER_INDEX_WIDTH 16
#define ERF_SC_PACKETISER_HEADER_COUNT_LBN 48
#define ERF_SC_PACKETISER_HEADER_COUNT_WIDTH 16
#define ERF_SC_PACKETISER_HEADER_RESERVED_0_LBN 64
#define ERF_SC_PACKETISER_HEADER_RESERVED_0_WIDTH 32
#define ERF_SC_PACKETISER_HEADER_RESERVED_1_LBN 96
#define ERF_SC_PACKETISER_HEADER_RESERVED_1_WIDTH 32
#define ERF_SC_PACKETISER_HEADER_RESERVED_2_LBN 128
#define ERF_SC_PACKETISER_HEADER_RESERVED_2_WIDTH 32


/*------------------------------------------------------------*/
/*
 * ER_RX_SL_PACKETISER_PAYLOAD_WORD(128bit):
 * 
 */
#define ER_RX_SL_PACKETISER_PAYLOAD_WORD_SIZE 16
#define ER_RX_SL_PACKETISER_PAYLOAD_WORD_WIDTH 128

#define ERF_SC_PACKETISER_PAYLOAD_COUNTER_INDEX_LBN 0
#define ERF_SC_PACKETISER_PAYLOAD_COUNTER_INDEX_WIDTH 24
#define ERF_SC_PACKETISER_PAYLOAD_RESERVED_LBN 24
#define ERF_SC_PACKETISER_PAYLOAD_RESERVED_WIDTH 8
#define ERF_SC_PACKETISER_PAYLOAD_PACKET_COUNT_OFST 4
#define ERF_SC_PACKETISER_PAYLOAD_PACKET_COUNT_SIZE 6
#define ERF_SC_PACKETISER_PAYLOAD_PACKET_COUNT_LBN 32
#define ERF_SC_PACKETISER_PAYLOAD_PACKET_COUNT_WIDTH 48
#define ERF_SC_PACKETISER_PAYLOAD_BYTE_COUNT_OFST 10
#define ERF_SC_PACKETISER_PAYLOAD_BYTE_COUNT_SIZE 6
#define ERF_SC_PACKETISER_PAYLOAD_BYTE_COUNT_LBN 80
#define ERF_SC_PACKETISER_PAYLOAD_BYTE_COUNT_WIDTH 48


#endif /* EFX_MAE_COUNTER_FORMAT_H */
