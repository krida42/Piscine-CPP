#include "Fixed.hpp"

int main()
{
	/*
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
*/
	std::cout << "sizeof fixed : " << sizeof(Fixed) << std::endl;
	std::cout << "sizeof int : " << sizeof(int) << std::endl;
	return 0;
}
