# endian

## 寻址

多字节对象被存储为连续的字节序列，对象的地址为所使用字节中最小的地址。

例如，

## 字节顺序

最高有效位，最低有效位

最高有效字节，最低有效字节

![](https://github.com/ltimaginea/Computer-Systems-A-Programmer-Perspective/blob/main/ComputerSystemsAProgrammerPerspective/Images/Ch02_InformationPresentationProcess/endian0.png)

![](https://github.com/ltimaginea/Computer-Systems-A-Programmer-Perspective/blob/main/ComputerSystemsAProgrammerPerspective/Images/Ch02_InformationPresentationProcess/endian1.png)



## Endian Conversion Functions

## Linux



```cpp
uint32_t htonl(uint32_t hostlong);

uint16_t htons(uint16_t hostshort);

uint32_t ntohl(uint32_t netlong);

uint16_t ntohs(uint16_t netshort);
```



## Boost



