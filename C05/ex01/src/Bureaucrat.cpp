#include "Bureaucrat.hpp"
#include <ostream>

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {

	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : 
	_name(name), _grade(grade) {

	std::cout << "Bureaucrat param constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()) {

	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat() {

	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {

	std::cout << "Bureaucrat assignation operator called" << std::endl;

	this->_grade = rhs.getGrade();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}


std::string const &	Bureaucrat::getName(void) const {

	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	
	return this->_grade;
}

void Bureaucrat::upgrade(void) {

	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::downgrade(void) {

	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form & form) const {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	} catch (std::exception & e) {
		std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

// - - - - - Exception - - - - -
//
// - - - - - - - - - - - - - - -

char const * Bureaucrat::GradeTooHighException::what(void) const throw() {
	
	return "Error: Grade too high !";
}

char const * Bureaucrat::GradeTooLowException::what(void) const throw() {

	return "Error: Grade too low !!";
}
