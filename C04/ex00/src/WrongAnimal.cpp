#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {

    std::cout << "WrongAnimal constructor called" << std::endl;
    this->_type = "WrongAnimal_unknown";
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {

    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal(void) {

    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs) {

    std::cout << "WrongAnimal assignation operator called" << std::endl;

    this->_type = rhs.getType();
    return *this;
}

void    WrongAnimal::makeSound() const {

    std::cout << "Trying to make some random sound..." << std::endl;
}

const std::string & WrongAnimal::getType() const {
    
    return this->_type;
}