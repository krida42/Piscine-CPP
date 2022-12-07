#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
int main(void)
{


    Contact contact;
    contact.setContact("StanLeglagandodo", "LeVent", "Wax", "06 78 94 12 54", "Que je suis un groslard");
    contact.setContact("Thomas", "LeVent", "Wax", "06 78 94 12 54", "Que je suis un groslard");

    PhoneBook phonebook;
    std::string input;
    while (std::getline(std::cin, input)) {
        std::cout << "\nstr from cin : " << input << std::endl;
        if (input == "ADD")
            phonebook.execAdd();
        else if (input == "SEARCH")
            phonebook.displayContacts();
        else if (input == "EXIT")
            break;
    }

/*
    std::cout << "\n";
    contact.displayPreview();
	std::cout << std::endl;
	contact.displayInformations();
*/

    std::cout << std::endl;
    return 0;
}
