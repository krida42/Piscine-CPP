#include "AForm.hpp"
#include <exception>

int const AForm::_lowestGrade = 150;
int const AForm::_highestGrade = 1;

AForm::AForm(void) : _name("default"), _gradeToSign(AForm::_lowestGrade),
					_gradeToExecute(AForm::_lowestGrade), _signed(false){

	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const & name, int const gradeToSign,
			int const gradeToExecute) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
	_signed(false) {

	std::cout << "AForm param constructor called" << std::endl;
	if (gradeToSign < AForm::_highestGrade || gradeToExecute < AForm::_highestGrade)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > AForm::_lowestGrade || gradeToExecute > AForm::_lowestGrade)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src.getName()),
							_gradeToSign(src.getGradeToSign()),
							_gradeToExecute(src.getGradeToExecute()) {

	std::cout << "AForm copy constructor called" << std::endl;
	*this = src;
}

AForm & AForm::operator=(AForm const & rhs) {

	std::cout << "AForm assignation operator called" << std::endl;
	this->_signed = rhs.getSigned();
	return *this;
}

AForm::~AForm(void) {

	std::cout << "AForm destructor called" << std::endl;
}

std::string const & AForm::getName(void) const {

	return this->_name;
}

int AForm::getGradeToSign(void) const {

	return this->_gradeToSign;
}

int AForm::getGradeToExecute(void) const {

	return this->_gradeToExecute;
}

bool AForm::getSigned(void) const {

	return this->_signed;
}

void AForm::beSigned(Bureaucrat const & bureaucrat) {

	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream & operator<<(std::ostream& o, AForm const & rhs) {
	
	std::cout	<< "AForm name: " << rhs.getName()
				<< ", grade to sign: " << rhs.getGradeToSign() 
				<< ", grade to execute: " << rhs.getGradeToExecute()
				<< ", signed: " << rhs.getSigned();
	return o;
}

// - - - - - Exceptions - - - - -  //
//           - - - - -             //
//           - - - - -             //
//           - - - - -             //
// - - - - - Exceptions - - - - -  //

char const * AForm::GradeTooHighException::what(void) const throw() {
	return "Error: Grade is too high";
}

char const * AForm::GradeTooLowException::what(void) const throw() {
	return "Error: Grade is too low";
}

char const * AForm::FormNotSignedException::what(void) const throw() {
	return "Error: Form is not signed";
}




