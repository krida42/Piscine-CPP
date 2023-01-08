#ifndef FORM_HPP
# define FORM_HPP
# pragma once

# include <exception>
# include <string>
# include <ostream>
# include <iostream>
# include "Bureaucrat.hpp"


class Bureaucrat;

class Form {

public:

	Form(void);
	Form(std::string const & name, int const gradeToSign, int const gradeToExecute);
	Form(Form const & src);
	~Form(void);

	Form & operator=(Form const & rhs);

	std::string const & getName(void) const;
	int		getGradeToSign(void) const;
	int		getGradeToExecute(void) const;
	bool	getSigned(void) const;

	void	beSigned(Bureaucrat const & bureaucrat);

private:

	static int const _lowestGrade;
	static int const _highestGrade;

	std::string const _name;
	int const	_gradeToSign;
	int const	_gradeToExecute;
	bool		_signed;

public:

	class GradeTooHighException : public std::exception {
	public:
		char const * what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		char const * what(void) const throw();
	};



};

std::ostream & operator<<(std::ostream & o, Form const & rhs);
#endif
