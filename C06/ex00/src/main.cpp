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
	
	std::string const arg = argv[1];

	GodType god(arg);
	god.displayAll();
	return (0);
}



