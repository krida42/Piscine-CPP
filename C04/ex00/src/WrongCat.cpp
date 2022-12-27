#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat(void) {

    std::cout << "WrongCat constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src){

    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

WrongCat::~WrongCat(void) {

    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs) {

    std::cout << "WrongCat assignation operator called" << std::endl;

    this->_type = rhs.getType();
    return *this;
}

void    WrongCat::makeSound() const {

    std::cout << "Meow" << std::endl;
}
