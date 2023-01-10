#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Constructor default Intern called !" << std::endl;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Constructor copy Intern called !" << std::endl;
	*this = src;
}

Intern & Intern::operator=(Intern const & src)
{
	std::cout << "Operator = Intern called !" << std::endl;
	(void)src;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Destructor Intern called !" << std::endl;
}

AForm * Intern::makeForm(std::string const & formName, std::string const & target) {

	AForm *choosenForm = NULL;
	FormMap forms[] = {
		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)},
		{"shrubbery creation", new ShrubberyCreationForm(target)}
	};

	for (int i = 0; i < 3; i++) {

		if (forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			choosenForm = forms[i].form;
		}
		else delete forms[i].form;

	}

	if (!choosenForm) {
		std::cout	<< "Intern can't create " << formName
					<< " because it doesn't exist" << std::endl;
	}
	return choosenForm;
}

