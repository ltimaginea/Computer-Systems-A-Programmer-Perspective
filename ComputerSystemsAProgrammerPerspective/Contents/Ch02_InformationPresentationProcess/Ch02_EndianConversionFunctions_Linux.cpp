#include <iostream>
#include <iomanip>

#include <arpa/inet.h>
#include <endian.h>

int main()
{
	int32_t a = 0x12345678;

	std::cout << std::showbase << std::hex;

	std::cout << a << "\n";
	std::cout << htole32(a) << "\n";
	std::cout << htobe32(a) << "\n";
	std::cout << htonl(a) << "\n";

	std::cout << std::noshowbase << std::dec;

	return 0;
}
