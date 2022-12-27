#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:
    
    FragTrap(void);
    FragTrap(FragTrap const & src);
    FragTrap(std::string const & name);
    ~FragTrap(void);

    FragTrap & operator=(FragTrap const & rhs);

    void    attack(std::string const &target);
    void	highFivesGuys(void); 

private:

    void    initDefaultAttr(void);
        
};


#endif