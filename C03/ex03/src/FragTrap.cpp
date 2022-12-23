#include "FragTrap.hpp"

FragTrap::FragTrap(void) {

    std::cout << "FragTrap Default constructor called !" << std::endl;
    this->initDefaultAttr();
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
    std::cout << "FragTrap Copy constructor called !" << std::endl;
    *this = src;
}

FragTrap::FragTrap(std::string const & name) : ClapTrap(name) {
    std::cout << "FragTrap Name constructor called !" << std::endl;
    this->initDefaultAttr();
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap Destructor called !" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
    this->_hitPoints = rhs.gethitPoints();
    this->_attackDamage = rhs.getAttackDamage();
    this->_energyPoints = rhs.getEnergyPoints();
    return *this;
}

void    FragTrap::initDefaultAttr(void) {
    this->_hitPoints = 100;
    this->_attackDamage = 30;
    this->_energyPoints = 100;
}

void    FragTrap::attack(std::string const & target) {

	if (this->_energyPoints <= 0) { 
		std::cout << "FragTrap " << this->_name << " can't attack " << target << " because not enough energy points" << std::endl; 
		return ;
	}

	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage! " << std::endl;
	this->_energyPoints--;
}

void    FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name << " give a high five" << std::endl;
}