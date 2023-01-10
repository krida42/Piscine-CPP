#ifndef INTERN_HPP
# define INTERN_HPP
# pragma once

# include <string>
# include <iostream>
# include <exception>

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {

public:

	Intern(void);
	Intern(Intern const & src);
	~Intern(void);

	Intern & operator=(Intern const & rhs);

	AForm * makeForm(std::string const & formName, std::string const & target);

private:
	struct FormMap {
		std::string name;
		AForm	*form;
	};
};


#endif
