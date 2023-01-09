#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int const ShrubberyCreationForm::_requiredToSign = 145;
int const ShrubberyCreationForm::_requiredToExecute = 137;
std::string const ShrubberyCreationForm::_formName = "ShrubberyCreationForm";

void ShrubberyCreationForm::_writeAsciiTree(std::ofstream & ofs) {
	ofs << "          .     .  .      +     .      .          ." << std::endl;
	ofs << "     .       .      .     #       .           ." << std::endl;
	ofs << "        .      .         ###            .      .      ." << std::endl;
	ofs << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
	ofs << "          .      . \"####\"###\"####\"  ." << std::endl;
	ofs << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
	ofs << "  .             \"#########\"#########\"        .        ." << std::endl;
	ofs << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
	ofs << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
	ofs << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
	ofs << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
	ofs << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
	ofs << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
	ofs << "            .     \"      000      \"    .     ." << std::endl;
	ofs << "       .         .   .   000     .        .       ." << std::endl;
	ofs << ".. .. ..................O000O........................ ...... ..." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : 
	AForm(ShrubberyCreationForm::_formName, ShrubberyCreationForm::_requiredToSign, ShrubberyCreationForm::_requiredToExecute),
	_target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : 
	AForm(ShrubberyCreationForm::_formName, ShrubberyCreationForm::_requiredToSign, ShrubberyCreationForm::_requiredToExecute),
	_target(target)
{
	std::cout << "ShrubberyCreationForm param constructor called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	AForm(src), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called !" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor called !" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	(void) rhs;
	std::cout << "Can't use assignement operator nothing to copy !" << std::endl;
	return *this;
}

std::string const & ShrubberyCreationForm::getTarget(void) const {
	return this->_target;
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() == false)
		throw ShrubberyCreationForm::FormNotSignedException();
	else if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	
	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream ofs(fileName.c_str());

	if (!ofs.is_open())
		return ;

	ShrubberyCreationForm::_writeAsciiTree(ofs);
	ofs.close();
}

