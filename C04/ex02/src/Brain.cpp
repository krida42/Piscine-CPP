#include "Brain.hpp"

Brain::Brain(void) {

    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const & src) {

    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain::~Brain(void) {

    std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs) {

    std::cout << "Brain assignation operator called" << std::endl;
    for (int i = 0; i < MAX_IDEAS; i++)
        this->ideas[i] = rhs.ideas[i];
    return *this;
}

