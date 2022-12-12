#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return (std::cout << "Not the good amount of arguments\n", 1);
	
	Harl harl;
	harl.complain(argv[1]);
	return 0;
}
