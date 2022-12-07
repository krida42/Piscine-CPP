#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    std::cout << "Constructor PhoneBook called !" << std::endl;

    for (int i = 0; i < NUM_CONTACTS; i++)
        this->contacts[i].setContact("", "", "", "", "");
}

PhoneBook::~PhoneBook (void) {
    std::cout << "Destructor PhoneBook called !" << std::endl;
}

void    PhoneBook::execAdd(void) {
    int         count = 0;
    std::string input = "";
    std::string res[5];
    std::string questions[5] = {
        "Firstname : ",
        "Lastname : ",
        "Nickname : ",
        "Phone number : ",
        "Your darkest secret : "
    };

    std::cout << "Creating a new user...\n";
    while (input == "" || count < 5) {
        
        std::cout << questions[count];
        if (!std::getline(std::cin, input))
             std::exit(1);
        if (input == "")
            continue ;
        res[count] = input;
        count++;
    }

    Contact contact_tmp1 = this->contacts[0];
    Contact contact_tmp2;
    for (int i = 1; i < NUM_CONTACTS; i++) {
        contact_tmp2 = this->contacts[i];
        this->contacts[i] = contact_tmp1;
        contact_tmp1 = contact_tmp2; 
    }
    this->contacts[0] = Contact(res[0], res[1], res[2], res[3], res[4]);
    
}

void PhoneBook::displayContacts(void) const {
    for (int i = 0; i < NUM_CONTACTS; i++)
        this->contacts[i].displayPreview();
    
}