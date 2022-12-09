#include "PhoneBook.hpp"

int PhoneBook::_num_contacts = 0;

PhoneBook::PhoneBook(void) {
	//std::cout << "Constructor PhoneBook called !" << std::endl;

	for (int i = 0; i < NUM_CONTACTS; i++)
		this->contacts[i].setContact("", "", "", "", "");
}

PhoneBook::~PhoneBook (void) {
	//std::cout << "Destructor PhoneBook called !" << std::endl;
}

void PhoneBook::_promptAddFields(std::string res[])
{

	int isprintable = 1;
	int count = 0;
	std::string input = "";
	size_t start;
	size_t stop;
	std::string whitespaces(" \t\f\v\n\r");

	std::string::const_iterator it;

	std::string questions[5] = {
		"Firstname : ",
		"Lastname : ",
		"Nickname : ",
		"Phone number : ",
		"Your darkest secret : "};

	while (input == "" || count < 5)
	{

		std::cout << questions[count];
		if (!std::getline(std::cin, input))
			std::exit(1);

		it = input.begin();
		while (it != input.end() && (isprintable = std::isprint(*it)))
			it++;
		start = input.find_first_not_of(whitespaces);
		stop = input.find_last_not_of(whitespaces);
		input = start == std::string::npos ? "" : input.substr(start, stop + 1);
		if (input.empty() || !isprintable)
			continue;

		res[count] = input;
		count++;
	}
}

void    PhoneBook::execAdd(void) {
	std::string res[5];


	std::cout << "Creating a new user...\n";

	_promptAddFields(res);


	Contact contact_tmp1 = this->contacts[0];
	Contact contact_tmp2;
	for (int i = 1; i < NUM_CONTACTS; i++) {
		contact_tmp2 = this->contacts[i];
		this->contacts[i] = contact_tmp1;
		contact_tmp1 = contact_tmp2; 
	}
	this->contacts[0] = Contact(res[0], res[1], res[2], res[3], res[4]);
	if (PhoneBook::_num_contacts < NUM_CONTACTS)
		PhoneBook::_num_contacts++;
	std::cout << "\nUser " << res[0] << " " << res[1] << " created !" << std::endl;
	
}

void	PhoneBook::execSearch(void) const {
	std::string 		input= "";
	int					ok = 0;
	_displayContacts();
	if (this->contacts[0].empty())
		return ;
	while (!ok) {
		std::cout << "\nSearch by index: ";
		if (!std::getline(std::cin, input))
			std::exit(1);
		if (input.empty())
			std::cout << "Please enter a number" << std::endl;
		else if (input.find_first_not_of("0123456789") != std::string::npos)
			std::cout << "Index not numeric or negative!" << std::endl;
		else if (input.length() > 6 || atoi(input.c_str()) >= PhoneBook::_num_contacts)
			std::cout << "Index out of range !" << std::endl;
		else
			ok = 1;
	}
	this->contacts[atoi(input.c_str())].displayInformations();
}

void	PhoneBook::_displayContacts(void) const {
	std::stringstream	stream;
	Contact				columnNames("First name", "Last name", "Nickname", "nil", "nil");
	
	if (!this->contacts[0].empty())
		columnNames.displayPreview("Index");
	
	for (int i = 0; i < NUM_CONTACTS; i++) {
		if (this->contacts[i].empty())
			continue;
		stream.str("");
		stream << i;
		this->contacts[i].displayPreview(stream.str());
	}
	if (this->contacts[0].empty())
		std::cout << "NO CONTACT AT ALL. You can use ADD to make a new contact" << std::endl;
}
