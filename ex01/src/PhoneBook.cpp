#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    std::cout << "Constructor PhoneBook called !" << std::endl;

    for (int i = 0; i < NUM_CONTACTS; i++) {
        this->contacts[i].setContact("", "", "", "", "");
    }
}

PhoneBook::~PhoneBook (void) {
    std::cout << "Destructor PhoneBook called !" << std::endl;
}

void    PhoneBook::execAdd(void) {

}