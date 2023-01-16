#include "BaseABC.hpp"
#include <cstdlib>

Base::~Base(void) {

    std::cout << "Base destructor called !" << std::endl;
}

Base * generate(void) {

    srand(time(NULL));
    
    int choosen = rand() % 3;
    switch (choosen) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return new A();
}

void identify(Base & p) {

    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception & e) {}

    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    } catch(std::exception & e) {}

    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    } catch(std::exception & e) {}
}

void identify(Base * p) {

	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}