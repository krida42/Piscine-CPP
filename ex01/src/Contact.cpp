#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName, std::string nickName,
                std::string phoneNumber, std::string darkestSecret) : 
                firstName(firstName), lastName(lastName), nickName(nickName),
                phoneNumber(phoneNumber), darkestSecret(darkestSecret) {
    std::cout << "Contact Constructor called ! " << std::endl;
}

Contact::~Contact(void) {
    std::cout << "Contact Destructor called ! " << std::endl;
}

void Contact::show(void) const {
    std::string firstName = this->firstName.substr(0, 10);
    std::string lastName = this->firstName.substr(0, 10);
    std::string nickName = this->firstName.substr(0, 10);
    std::string phoneNumber = this->firstName.substr(0, 10);
    std::string darkestSecret = this->firstName.substr(0, 10);

}