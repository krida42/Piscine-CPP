#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main (void) {

	DiamondTrap diamond("Eliott");
	std::cout << std::endl;

	std::cout << "FragTrap hit points: " << diamond.FragTrap::gethitPoints() << std::endl;
	std::cout << "ScavTrap hit points: " << diamond.ScavTrap::gethitPoints() << std::endl << std::endl;


	

	std::cout << std::endl;

	diamond.attack("KIRIKOU");
	diamond.ClapTrap::attack("KIRIKOU");
	diamond.ScavTrap::attack("KIRIKOU");
	diamond.FragTrap::attack("KIRIKOU");

	std::cout << std::endl;
	diamond.whoAmI();
	std::cout << std::endl;

	return 0;
}