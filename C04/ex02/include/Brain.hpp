#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

# define MAX_IDEAS 100

class Brain {

public:

	Brain(void);
	Brain(Brain const & src);
	
	virtual ~Brain(void);

	Brain & operator=(Brain const & rhs);
	
	std::string ideas[MAX_IDEAS];

};


#endif