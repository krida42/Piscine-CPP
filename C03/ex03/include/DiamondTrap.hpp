#ifndef DIAMONTRAP_HPP
# define DIAMONTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap{
    public:
        DiamondTrap(void);
        DiamondTrap(DiamondTrap const & src);
        DiamondTrap(std::string const & name);
        ~DiamondTrap(void);

        DiamondTrap & operator=(DiamondTrap const & rhs);

        void attack(std::string const &target);
        void whoAmI(void) const;
		std::string getName(void) const;

    private:
        std::string _name;
        void    	_initDefaultAttr(void);
};

#endif