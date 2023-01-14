#include <iostream>
#include "GodType.hpp"
#include <string>
#include <fstream>


int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "I need exactly 2 arguments" << std::endl;
		return 1;
	}
	(void)argv;
	//GodType god(argv[1]);

	std::ifstream ifs ("Makefile");
	std::string str;
	std::getline(ifs, str, '\0');
	std::cout << str << std::endl;
	return (0);
}



