#include "Cat.hpp"
#include <new>

Cat::Cat(void) {

    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(Cat const & src) : Animal(src){

    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = new Brain();
    *this = src;
}

Cat::~Cat(void) {

    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

Cat & Cat::operator=(Cat const & rhs) {

    std::cout << "Cat assignation operator called" << std::endl;

    this->_type = rhs.getType();
    for(int i = 0; i < MAX_IDEAS; i++)
        this->_brain->ideas[i] = rhs.getBrain()->ideas[i];
    return *this;
}

void    Cat::makeSound() const {

    std::cout << "Meow" << std::endl;
}

const Brain * Cat::getBrain(void) const {
    return this->_brain;
}