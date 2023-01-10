#ifndef AFORM_HPP
# define AFORM_HPP
# pragma once

# include <exception>
# include <string>
# include <ostream>
# include <iostream>
# include "Bureaucrat.hpp"


class Bureaucrat;

class AForm {

public:

	AForm(void);
	AForm(std::string const & name, int const gradeToSign, int const gradeToExecute);
	AForm(AForm const & src);
    virtual ~AForm(void) = 0;

	AForm & operator=(AForm const & rhs);

	std::string const & getName(void) const;
	int		getGradeToSign(void) const;
	int		getGradeToExecute(void) const;
	bool	getSigned(void) const;

	void			beSigned(Bureaucrat const & bureaucrat);
	virtual void	execute(Bureaucrat const & executor) const = 0;

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

	class FormNotSignedException: public std::exception {
	public:
		char const * what(void) const throw();
	};



};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);
#endif
