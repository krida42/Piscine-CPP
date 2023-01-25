#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main (void) {

	DiamondTrap diamond("Eliott");
	std::cout << std::endl;

	

	std::cout << "DiamondTrap hit points: " << diamond.gethitPoints() << std::endl;
	std::cout << "DiamondTrap attack damage: " << diamond.getAttackDamage() << std::endl;
	std::cout << "DiamondTrap energy points: " << diamond.getEnergyPoints() << std::endl;
	diamond.attack("KIRIKOU");

	std::cout << std::endl;
	diamond.whoAmI();
	std::cout << std::endl;

	return 0;
}