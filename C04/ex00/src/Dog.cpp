#include "Dog.hpp"

Dog::Dog(void) {

    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(Dog const & src) : Animal(src){

    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog::~Dog(void) {

    std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs) {

    std::cout << "Dog assignation operator called" << std::endl;

    this->_type = rhs.getType();
    return *this;
}

void    Dog::makeSound() const {

    std::cout << "Woof" << std::endl;
}