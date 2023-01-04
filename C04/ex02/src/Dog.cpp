#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) {

    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(Dog const & src) : Animal(src){

    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain();
    *this = src;
}

Dog::~Dog(void) {

    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

Dog & Dog::operator=(Dog const & rhs) {

    std::cout << "Dog assignation operator called" << std::endl;

    this->_type = rhs.getType();
    for(int i = 0; i < MAX_IDEAS; i++)
        this->_brain->ideas[i] = rhs.getBrain()->ideas[i];
    return *this;
}

void    Dog::makeSound() const {

    std::cout << "Woof" << std::endl;
}

const Brain * Dog::getBrain(void) const {
    return this->_brain;
}