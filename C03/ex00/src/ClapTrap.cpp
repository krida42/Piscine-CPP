#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void) : _name("unknown"), _hitPoints(10), _attackDamage(0), _energyPoints(10){}

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hitPoints(10), _attackDamage(0) , _energyPoints(10){
    
	std::cout << "Param constructor called !" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {

	std::cout << "Copy constructore called !" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void) {

	std::cout << "Destructor called !" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	
	std::cout << "Affection operator called !" << std::endl;

	this->_name = rhs.getName();
	this->_hitPoints = rhs.gethitPoints();
	this->_attackDamage = rhs.getAttackDamage();
	this->_energyPoints = rhs.getEnergyPoints();

	return *this;
}


std::string		ClapTrap::getName(void) const {
    return this->_name;
}

unsigned int	ClapTrap::gethitPoints(void) const {
	return this->_hitPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}


void 	ClapTrap::attack(std::string const & target) {

	if (this->_energyPoints <= 0) { 
		std::cout << "ClapTrap " << this->_name << " can't attack " << target << " because not enough energy points" << std::endl; 
		return ;
	}

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage! " << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {

	std::cout << "ClapTrap " << this->_name << " taked " << amount << " of damage" << std::endl;
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " can't repair himself, because not enough energy points" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name << " repair himself of " << amount << " hit points !" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
}


