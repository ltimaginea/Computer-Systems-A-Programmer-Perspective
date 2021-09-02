#include <iostream>

#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	struct sockaddr_in addr1;
	addr1.sin_family = AF_INET;
	addr1.sin_addr.s_addr = htonl(0xcdbc9217);
	char buf1[INET_ADDRSTRLEN] = { 0 };
	if (inet_ntop(addr1.sin_family, &addr1.sin_addr.s_addr, buf1, INET_ADDRSTRLEN) != NULL)
		std::cout << buf1 << "\n";

	struct sockaddr_in addr2;
	addr2.sin_family = AF_INET;
	char buf2[INET_ADDRSTRLEN] = { "64.12.149.13" };
	if (inet_pton(addr2.sin_family, buf2, &addr2.sin_addr.s_addr) == 1)
		std::cout << std::showbase << std::hex << ntohl(addr2.sin_addr.s_addr) << std::noshowbase << std::dec << "\n";

	return 0;
}

// Tips:
//	1. IPv4地址和TCP或UDP端口号在套接字地址结构中总是以网络字节序来存储
//	2. 应该优先使用inet_pton和inet_ntop，避免使用这3个函数：inet_aton和inet_ntoa已过时，inet_addr存在缺陷

/* Possible outputs:
205.188.146.23
0x400c950d
*/
