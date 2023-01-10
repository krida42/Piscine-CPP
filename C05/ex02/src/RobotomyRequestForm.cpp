#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int const RobotomyRequestForm::_requiredToSign = 72;
int const RobotomyRequestForm::_requiredToExecute = 45;
std::string const RobotomyRequestForm::_formName = "RobotomyRequestForm";


RobotomyRequestForm::RobotomyRequestForm(void) : 
	AForm(RobotomyRequestForm::_formName, RobotomyRequestForm::_requiredToSign, RobotomyRequestForm::_requiredToExecute),
	_target("default")
{
	std::cout << "RobotomyRequestForm default constructor called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : 
	AForm(RobotomyRequestForm::_formName, RobotomyRequestForm::_requiredToSign, RobotomyRequestForm::_requiredToExecute),
	_target(target)
{
	std::cout << "RobotomyRequestForm param constructor called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	AForm(src), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called !" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor called !" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	(void) rhs;
	std::cout << "Can't use assignement operator nothing to copy !" << std::endl;
	return *this;
}

std::string const & RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	
	std::cout << "* drilling noises *" << std::endl;
	srand(time(NULL));
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully !" << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed !" << std::endl;
}