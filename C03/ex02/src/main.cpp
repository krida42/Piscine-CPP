#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void) {



	FragTrap frag("Franckkk");
	frag.attack("cocorico");
	std::cout << "frag life : " << frag.gethitPoints() << std::endl;
	frag.takeDamage(10);
	std::cout << "frag life : " << frag.gethitPoints() << std::endl;
	frag.highFivesGuys();
	frag.beRepaired(10);
	std::cout << "frag life : " << frag.gethitPoints() << std::endl;

	return 0;
}