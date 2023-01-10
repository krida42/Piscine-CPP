#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

int	main(void)
{
	std::cout << "Creating a bureaucrats" << std::endl;
	Bureaucrat deniz("Denizzdd", 1);
	Bureaucrat jamal("Jamal", 150);
	ShrubberyCreationForm shrubbery("randomfilecopy.txt");
	ShrubberyCreationForm shrubbery_copy(shrubbery);
	RobotomyRequestForm robotomy("Elie");
	PresidentialPardonForm pardon("CuicuiPresident");



	


	std::cout << std::endl;

	try {

		std::cout << "Name of shrubbery form: " << shrubbery_copy.getName() << std::endl;
		std::cout << "Target of shrubbery form: " << shrubbery_copy.getTarget() << std::endl;
		std::cout << "Required grade to sign: " << shrubbery_copy.getGradeToSign() << std::endl;
		std::cout << "Required grade to execute: " << shrubbery_copy.getGradeToExecute() << std::endl;

		deniz.signForm(shrubbery_copy);
		deniz.executeForm(shrubbery_copy);
		deniz.signForm(robotomy);
		deniz.executeForm(robotomy);
		deniz.signForm(pardon);
		deniz.executeForm(pardon);

	} catch (std::exception & err) {

		std::cout << "\n- - - - - - -I guess there is some problem with grades or signing - - - - - -\n";
		std::cout << err.what();
	}
	std::cout << std::endl;




	std::cout << std::endl << std::endl;
	std::cout << "- - - - - - - Destructor calling - - - - - - -" << std::endl;
	return (0);
}
