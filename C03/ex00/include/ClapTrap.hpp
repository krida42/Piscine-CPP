#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {

public:

	ClapTrap(void);
	ClapTrap(std::string const & name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);

	ClapTrap & operator=(ClapTrap const & rhs);

	void 	attack(std::string const &target);
	void 	beRepaired(unsigned int amount);
	void 	takeDamage(unsigned int amount);

	std::string 	getName(void) const;
	unsigned int	gethitPoints(void) const;
	unsigned int	getAttackDamage(void) const;
	unsigned int	getEnergyPoints(void) const;


private:

	std::string 	_name;
	unsigned int	_hitPoints;
	unsigned int 	_attackDamage;
	unsigned int 	_energyPoints;

};

#endif