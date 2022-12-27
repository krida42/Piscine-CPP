#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main (void) {

	std::cout << "Creating Animal, Dog and Cat objects...\n\n" << std::endl;

	const Animal* animal = new Animal();
	std::cout << "- - - - - - -" << std::endl;
	
	const Animal* dog = new Dog();
	std::cout << "- - - - - - -" << std::endl;
	
	const Animal* cat = new Cat();
	std::cout << "- - - - - - -\n" << std::endl;

	std::cout << "dog->getType() -> " << dog->getType() << std::endl;
	std::cout << "cat->getType() -> " << cat->getType() << std::endl;
	std::cout << "animal->getType() -> " << animal->getType() << std::endl << std::endl;

	std::cout << "cat->makeSound() -> ";
	cat->makeSound();

	std::cout << "dog->makeSound() -> ";
	dog->makeSound();

	std::cout << "animal->makeSound() -> ";
	animal->makeSound();
	

	std::cout << "\n\nDeleting Animal, Dog and Cat objects...\n" << std::endl;

	delete animal;
	std::cout << "- - - - - - -" << std::endl;

	delete dog;
	std::cout << "- - - - - - -" << std::endl;

	delete cat;
	std::cout << "\n<============================================================>" << std::endl;
	std::cout << "<============================================================>\n\n" << std::endl;

	std::cout << "Creating WrongAnimal and WrongCat objects...\n" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	std::cout << "- - - - - - -" << std::endl;

	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "- - - - - - -\n" << std::endl;

	std::cout << "wrongAnimal->makeSound() -> ";
	wrongAnimal->makeSound();

	std::cout << "wrongCat->makeSound() -> ";
	wrongCat->makeSound();	

	std::cout << "\n\nDeleting WrongAnimal and WrongCat objects...\n" << std::endl;

	delete wrongAnimal;
	std::cout << "- - - - - - -" << std::endl;

	delete wrongCat;
	std::cout << "- - - - - - -\n\n" << std::endl;


	return 0;
}