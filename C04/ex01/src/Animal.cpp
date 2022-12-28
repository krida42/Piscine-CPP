#include "Animal.hpp"

Animal::Animal(void) {

    std::cout << "Animal constructor called" << std::endl;
    this->_type = "Animal_unknown";
}

Animal::Animal(Animal const & src) {

    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal::~Animal(void) {

    std::cout << "Animal destructor called" << std::endl;
}

Animal & Animal::operator=(Animal const & rhs) {

    std::cout << "Animal assignation operator called" << std::endl;

    this->_type = rhs.getType();
    return *this;
}

void    Animal::makeSound() const {

    std::cout << "Trying to make some random sound..." << std::endl;
}

const std::string & Animal::getType() const {
    
    return this->_type;
}