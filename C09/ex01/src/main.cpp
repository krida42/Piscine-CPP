#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Need one argument" << std::endl;
		return 1;
	}
	RPN rpn(argv[1]);
	if (isnan(rpn.getResult()))
		std::cout << "Error" << std::endl;
	else
		std::cout << rpn.getResult() << std::endl;
	return 0;
}
