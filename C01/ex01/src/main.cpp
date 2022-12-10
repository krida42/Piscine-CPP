#include "Zombie.hpp"

int main(void) {

    int n = 5;

    Zombie *zombies = zombieHorde(n, "Zeus");
    for (int i = 0; i < n; i++)
        zombies[i].announce();
    delete[] zombies;
    return 0;
}

