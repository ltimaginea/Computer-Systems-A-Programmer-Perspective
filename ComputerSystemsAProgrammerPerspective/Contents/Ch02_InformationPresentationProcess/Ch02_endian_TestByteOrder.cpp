// Only test for big and little endian, regardless PDP-11 and the other middle endian.
#include <iostream>
#include <iomanip>

int main()
{
	int32_t a = 0x01234567;

	int8_t start_value = *reinterpret_cast<int8_t*>(&a);

	std::cout << std::showbase << std::hex << static_cast<int32_t>(start_value) << std::noshowbase << std::dec << "\n";
	if (start_value == 0x67)
		std::cout << "host is little-endian\n";
	else if (start_value == 0x01)
		std::cout << "host is big-endian\n";
	else
		std::cout << "host is unknown-endian\n";

	return 0;
}
