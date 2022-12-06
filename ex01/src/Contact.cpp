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

void	Contact::printColumn(std::string const str) const {

	for (unsigned int i = 0; i < 10 - str.length(); i++)
		std::cout << " ";
	std::cout <<  str << "|";

}

void 	Contact::show(void) const {

	std::string firstName = this->firstName.substr(0, 10);
	if (this->firstName.length() > 10)
		firstName[9] = '.';

	std::string lastName = this->lastName.substr(0, 10);
	if (this->lastName.length() > 10)
		lastName[9] = '.';

	std::string nickName = this->nickName.substr(0, 10);
	if (this->nickName.length() > 10)
		nickName[9] = '.';
/*
	std::string phoneNumber = this->phoneNumber.substr(0, 10);
	if (this->phoneNumber.length() > 10)
		phoneNumber[9] = '.';

	std::string darkestSecret = this->darkestSecret.substr(0, 10);
	if (this->darkestSecret.length() > 10)
		darkestSecret[9] = '.';
*/
	printColumn(firstName);
	printColumn(lastName);
	printColumn(nickName);
	//printColumn(phoneNumber);
	//printColumn(darkestSecret);
	std::cout << std::endl;
}
