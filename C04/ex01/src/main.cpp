#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void) {

	std::cout << "Creating Dog and Cat objects...\n\n" << std::endl;

	Animal *animals[] = {
		new Dog(),
		new Cat()
	};

	std::cout << "\n\nLooping...\n" << std::endl;

	for (int i = 0; i < 2; i++) {
		std::cout << "Animal " << i << " says: ";
		animals[i]->makeSound();
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << "- - - -  -TEST\n\n" << std::endl;
	Dog dog = Dog();
	std::cout << "\n--- dog created ---\n\n" << std::endl;


	Cat cat = Cat();
	std::cout << "\n--- cat created ---\n\n" << std::endl;


	Dog dog2(dog);
	std::cout << "\n--- dog2 created ---\n\n" << std::endl;

	Cat cat2(cat);
	std::cout << "\n--- cat2 created ---\n\n" << std::endl;

	std::cout << "\n--- destructor called ---\n\n" << std::endl;


	return 0;
}