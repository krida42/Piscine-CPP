#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void){
    std::cout << "DiamondTrap Default constructor called !" << std::endl;

    this->_initDefaultAttr();
    this->_name = "DiamondTrap_unnamed";
}

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + "_clap_name"), ScavTrap(int()), FragTrap(int()){
    std::cout << "Diamond Name constructor called !" << std::endl;
    this->_initDefaultAttr();
    this->_name = name;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
    std::cout << "DiamondTrap Copy constructor called !" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "Diamond Destructor called !" << std::endl;
}

void    DiamondTrap::attack(std::string const & target) {
    this->ScavTrap::attack(target);
}

void    DiamondTrap::_initDefaultAttr(void) {
    this->_hitPoints = this->FragTrap::_hitPoints;
    this->_energyPoints = this->ScavTrap::_energyPoints;
    this->_attackDamage = this->FragTrap::_attackDamage;
}

void   DiamondTrap::whoAmI(void) const {
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::getName() << std::endl;
}

std::string DiamondTrap::getName(void) const {
    return this->_name;
}
