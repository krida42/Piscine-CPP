#include "ClapTrap.hpp"

int main (void) {
	ClapTrap clap("Clap");
	std::cout << std::endl;
	ClapTrap clap2(clap);
	ClapTrap clap3 = clap;
	clap3 = clap2;
	std::cout << "\n" << std::endl;

	clap.attack("target");
	std::cout << "clap health: " << clap.gethitPoints() << std::endl;
	clap.takeDamage(5);
	std::cout << "clap health: " << clap.gethitPoints() << std::endl;

	clap.beRepaired(25);
	std::cout << "clap health: " << clap.gethitPoints() << std::endl;
	return 0;
}