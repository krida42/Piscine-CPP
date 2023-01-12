#include <iostream>
#include "GodType.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "I need exactly 2 arguments" << std::endl;
		return 1;
	}
	
	GodType god(argv[1]);
	return (0);
}



