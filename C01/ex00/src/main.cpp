#include "Zombie.hpp"

int main(void) {

    Zombie *zombie = newZombie("Ares_Heap");
    zombie->announce();
    delete zombie;

    randomChump("Athena_Stack");
    return 0;
}

