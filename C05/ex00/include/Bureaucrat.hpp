#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include <exception>
# include <ostream>
# include <string>
# include <iostream>

class Bureaucrat {

public:

	Bureaucrat(void);
	Bureaucrat(std::string const & name, int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);

	Bureaucrat & operator=(Bureaucrat const & rhs);


	void	upgrade(void);
	void	downgrade(void);

	std::string const &	getName(void) const;
	int	getGrade(void) const;

private:
	
	std::string const _name;
	int			_grade;

public:

	class GradeTooHighException : public std::exception {
	
	public:
		char const * what(void) const throw();
	};

	class GradeTooLowException : public std::exception {

	public:
		char const *what(void) const throw();
	};

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);


#endif
