#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int const PresidentialPardonForm::_requiredToSign = 25;
int const PresidentialPardonForm::_requiredToExecute = 5;
std::string const PresidentialPardonForm::_formName = "PresidentialPardonForm";


PresidentialPardonForm::PresidentialPardonForm(void) : 
	AForm(PresidentialPardonForm::_formName, PresidentialPardonForm::_requiredToSign, PresidentialPardonForm::_requiredToExecute),
	_target("default")
{
	std::cout << "PresidentialPardonForm default constructor called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : 
	AForm(PresidentialPardonForm::_formName, PresidentialPardonForm::_requiredToSign, PresidentialPardonForm::_requiredToExecute),
	_target(target)
{
	std::cout << "PresidentialPardonForm param constructor called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
	AForm(src), _target(src.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called !" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor called !" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	(void) rhs;
	std::cout << "Can't use assignement operator nothing to copy !" << std::endl;
	return *this;
}

std::string const & PresidentialPardonForm::getTarget(void) const {
	return this->_target;
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}