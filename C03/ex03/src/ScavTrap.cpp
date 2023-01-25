#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {

    std::cout << "ScavTrap Default constructor called !" << std::endl;
    this->initDefaultAttr();
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
    std::cout << "ScavTrap Copy constructor called !" << std::endl;
    *this = src;
}

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name) {
    
    std::cout << "ScavTrap Name constructor called !" << std::endl;
    this->initDefaultAttr();
}

ScavTrap::ScavTrap(int) {
    std::cout << "ScavTrap Int constructor called !" << std::endl;
    
    this->_energyPoints = 50;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap Destructor called !" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
    this->_hitPoints = rhs.gethitPoints();
    this->_attackDamage = rhs.getAttackDamage();
    this->_energyPoints = rhs.getEnergyPoints();
    return *this;
}

void    ScavTrap::attack(std::string const & target) {

	if (this->_energyPoints <= 0) { 
		std::cout << "ScavTrap " << this->_name << " can't attack " << target << " because not enough energy points" << std::endl; 
		return ;
	}

	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage! " << std::endl;
	this->_energyPoints--;
}

void    ScavTrap::guardGate(void) const {
    std::cout << "ScavTrap " << this->_name << " entered in Gate keeper mode " << std::endl;
}

void    ScavTrap::initDefaultAttr(void) {
    this->_hitPoints = 100;
    this->_attackDamage = 20;
    this->_energyPoints = 50;
}