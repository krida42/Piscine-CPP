#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:
    
    ScavTrap(void);
    ScavTrap(ScavTrap const & src);
    ScavTrap(std::string const & name);
    ScavTrap(int);
    ~ScavTrap(void);

    ScavTrap & operator=(ScavTrap const & rhs);

    void attack(std::string const &target);
    void    guardGate(void) const;

private:

    void    initDefaultAttr(void);
        
};


#endif