#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){}

Zombie::Zombie(void) {}

Zombie::~Zombie(void) {
    std::cout << this->name << " has died !" << std::endl;
}

void    Zombie::setName(std::string name) {
    this->name = name;
}

void    Zombie::announce(void) {
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}