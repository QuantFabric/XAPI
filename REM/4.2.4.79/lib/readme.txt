linux版本的super_api使用需知

1、gcc版本4.8.5或更新，且安装了solarflare网卡，型号8522 plus或更新，并安装了onload-201811或更新版本(比如onload7.x、onload8.x)
满足上述条件下，替换so文件和头文件，重新编译客户端程序。

2、efvi加速，自动识别网卡配置，不再需要手动配置。

3、若要使用获取网卡时间戳功能进行性能测试，必须先同步软硬件时间戳，可使用solarflare提供的sfptd工具。

4、使用获取网卡时间戳功能将导致下单函数调用耗时增加，仅做测试使用，不建议实盘使用。

5、本api非线程安全，开发者需自行维护数据安全性，当下单函数和加热单函数在多线程中无锁调用时，有几率导致错单发出。

6、如果程序非root权限启动，请赋予sudo命令权限
 
7、如果安装了onload8.x，需要单独安装8.x的tcpdirect, 一般onload 8.0.x的onload和8.0.x的tcpdirect匹配，onload 8.1.x的onload和8.1.x的tcpdirect匹配

8、建议安装的onload版本和api提供的onload版本相匹配，api发单速度会有少量的提升。
