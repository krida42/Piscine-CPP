#include "RPN.hpp"

int main(void)
{
	RPN rpn("5 5 +-x");
	std::cout << rpn << std::endl;
	return 0;
}
