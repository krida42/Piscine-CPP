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

	std::cout << "- - - - CREATING TEST\n\n" << std::endl;
	Dog dog = Dog();

	std::cout << "\n\n- - - - MESS ttttests\n" << std::endl;
	//Dog dog2 = dog;
	Dog dog2 = Dog();

	std::cout << "\n\n--- destructor called ---\n\n" << std::endl;


	return 0;
}