#include <iostream>

#include <boost/endian/conversion.hpp>

int main()
{
	using namespace boost::endian;

	if (order::native == order::little)
		std::cout << "native_order:\tlittle endian" << std::endl;
	else if (order::native == order::big)
		std::cout << "native_order:\tbig endian" << std::endl;
	else
		std::cout << "native_order:\tunknown endian" << std::endl;

	int32_t data = 0x12345678;
	std::cout << std::showbase << std::hex;
	std::cout << "native_data:\t" << data << std::endl;
	std::cout << "native_to_big:\t" << native_to_big(data) << std::endl;
	std::cout << "native_to_lit:\t" << native_to_little(data) << std::endl;
	std::cout << std::noshowbase << std::dec;
	return 0;
}
