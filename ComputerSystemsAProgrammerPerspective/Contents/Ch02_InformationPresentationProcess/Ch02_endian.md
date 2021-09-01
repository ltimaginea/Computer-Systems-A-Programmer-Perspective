# Endian

## 寻址

多字节对象被存储为连续的字节序列，对象的地址为所使用字节中最小的地址。

例如，假设一个类型为 int 的变量 a 的地址为 0x100，也就是说，地址表达式 &a 的值为 0x100。那么，（假设数据类型 int 为32位表示） a 的 4 个字节将被存储在内存的 0x100、0x101、0x102 和 0x103 位置。

## 字节顺序

最低有效字节存储在起始地址，这称为**小端**（Little Endian）字节序；最高有效字节存储在起始地址，这称为**大端**（Big Endian）字节序。

术语“小端”和“大端”表示多字节值的哪一端（小端或大端）存储在该值的起始地址。

大多数 Intel 兼容机都只用小端模式。另一方面，IBM 和 Oracle 的大多数机器则是按大端模式操作。

在下图中，我们标明内存地址增长的方向为从左到右。我们还标明**最高有效位**（Most Significant Bit，MSB）是这个32位值最左边一位，**最低有效位**（Least Significant Bit，LSB）是这个32位值最右边一位。 **最高有效字节**（Most Significant Byte）是 Byte3=0x01，**最低有效字节**（Least Significant Byte）是 Byte0=0x67 。



![](https://github.com/ltimaginea/Computer-Systems-A-Programmer-Perspective/blob/main/ComputerSystemsAProgrammerPerspective/Images/Ch02_InformationPresentationProcess/endian0.png)

![](https://github.com/ltimaginea/Computer-Systems-A-Programmer-Perspective/blob/main/ComputerSystemsAProgrammerPerspective/Images/Ch02_InformationPresentationProcess/endian1.png)



## Endian Conversion Functions

## Linux



```cpp
// converts host byte order and network byte order
#include <arpa/inet.h>
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);
```



```cpp
// These  functions convert the byte encoding of integer values from the byte order that the current CPU (the "host") uses, 
// to and from little-endian and big-endian byte order.
#include <endian.h>
uint16_t htobe16(uint16_t host_16bits);
uint16_t htole16(uint16_t host_16bits);
uint16_t be16toh(uint16_t big_endian_16bits);
uint16_t le16toh(uint16_t little_endian_16bits);

uint32_t htobe32(uint32_t host_32bits);
uint32_t htole32(uint32_t host_32bits);
uint32_t be32toh(uint32_t big_endian_32bits);
uint32_t le32toh(uint32_t little_endian_32bits);

uint64_t htobe64(uint64_t host_64bits);
uint64_t htole64(uint64_t host_64bits);
uint64_t be64toh(uint64_t big_endian_64bits);
uint64_t le64toh(uint64_t little_endian_64bits);
```



## Boost





> ## *References*
>
> [endian(3) - Linux manual page (man7.org)](https://man7.org/linux/man-pages/man3/endian.3.html)
>
> [Boost.Endian: The Boost Endian Library - 1.77.0](https://www.boost.org/doc/libs/1_77_0/libs/endian/doc/html/endian.html)
>
> 
