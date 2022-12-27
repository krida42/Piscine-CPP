#include "Cat.hpp"

Cat::Cat(void) {

    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(Cat const & src) : Animal(src){

    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat(void) {

    std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs) {

    std::cout << "Cat assignation operator called" << std::endl;

    this->_type = rhs.getType();
    return *this;
}

void    Cat::makeSound() const {

    std::cout << "Meow" << std::endl;
}
