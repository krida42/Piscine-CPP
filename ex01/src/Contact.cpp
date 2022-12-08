#include "Contact.hpp"

Contact::Contact(void) {
    std::cout << "Contact Default Constructor called ! " << std::endl;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret) : 
				_firstName(firstName), _lastName(lastName), _nickName(nickName),
				_phoneNumber(phoneNumber), _darkestSecret(darkestSecret)
				{
    std::cout << "Contact Param Constructor called ! " << std::endl;
}

Contact::~Contact(void) {
    std::cout << "Contact Destructor called ! " << std::endl;
}

void	Contact::setContact(std::string firstName, std::string lastName, std::string nickName,
            				std::string phoneNumber, std::string darkestSecret) {
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

void	Contact::_printColumn(std::string const str) const {

	for (unsigned int i = 0; i < 10 - str.length(); i++)
		std::cout << " ";
	std::cout <<  str << "|";

}

void 	Contact::displayPreview(std::string index) const {

	std::string firstName = this->_firstName.substr(0, 10);
	if (this->_firstName.length() > 10)
		firstName[9] = '.';

	std::string lastName = this->_lastName.substr(0, 10);
	if (this->_lastName.length() > 10)
		lastName[9] = '.';

	std::string nickName = this->_nickName.substr(0, 10);
	if (this->_nickName.length() > 10)
		nickName[9] = '.';
	_printColumn(index);
	_printColumn(firstName);
	_printColumn(lastName);
	_printColumn(nickName);
	std::cout << std::endl;
}

void	Contact::displayInformations(void) const {
	std::cout << "First Name : " << this->_firstName << "\n";
	std::cout << "Last name : " << this->_lastName << "\n";
	std::cout << "Nickname : " << this->_nickName << "\n";
	std::cout << "Phone number : " << this->_phoneNumber << "\n";
	std::cout << "Darkest Secret : " << this->_darkestSecret << "\n" << std::endl;
}

bool Contact::empty(void) const {
	return this->_firstName.empty();
}