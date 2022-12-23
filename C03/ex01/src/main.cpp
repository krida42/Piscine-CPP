#include "ScavTrap.hpp"

int main (void) {

	ScavTrap trap("Henry");
	ClapTrap clap;

	trap.attack("cocorico");
	std::cout << "trap life : " << trap.gethitPoints() << std::endl;
	trap.takeDamage(10);
	std::cout << "trap life : " << trap.gethitPoints() << std::endl << std::endl;

	ScavTrap trap2(trap);

	trap2.attack("cocorico");
	std::cout << "trap2 life : " << trap2.gethitPoints() << std::endl;
	trap2.takeDamage(10);
	std::cout << "trap2 life : " << trap2.gethitPoints() << std::endl;

	clap = trap;
	//trap = clap; error, you cant
	return 0;
}