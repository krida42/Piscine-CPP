#include "Form.hpp"
#include <exception>

int const Form::_lowestGrade = 150;
int const Form::_highestGrade = 1;

Form::Form(void) : _name("default"), _gradeToSign(Form::_lowestGrade),
					_gradeToExecute(Form::_lowestGrade), _signed(false){

	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const & name, int const gradeToSign,
			int const gradeToExecute) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
	_signed(false) {

	std::cout << "Form param constructor called" << std::endl;
	if (gradeToSign < Form::_highestGrade || gradeToExecute < Form::_highestGrade)
		throw Form::GradeTooHighException();
	else if (gradeToSign > Form::_lowestGrade || gradeToExecute > Form::_lowestGrade)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src.getName()),
							_gradeToSign(src.getGradeToSign()),
							_gradeToExecute(src.getGradeToExecute()) {

	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form & Form::operator=(Form const & rhs) {

	std::cout << "Form assignation operator called" << std::endl;
	this->_signed = rhs.getSigned();
	return *this;
}

Form::~Form(void) {

	std::cout << "Form destructor called" << std::endl;
}

std::string const & Form::getName(void) const {

	return this->_name;
}

int Form::getGradeToSign(void) const {

	return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const {

	return this->_gradeToExecute;
}

bool Form::getSigned(void) const {

	return this->_signed;
}

void Form::beSigned(Bureaucrat const & bureaucrat) {

	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream & operator<<(std::ostream& o, Form const & rhs) {
	
	std::cout	<< "Form name: " << rhs.getName()
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

char const * Form::GradeTooHighException::what(void) const throw() {
	return "Error: Grade is too high";
}

char const * Form::GradeTooLowException::what(void) const throw() {
	return "Error: Grade is too low";
}




