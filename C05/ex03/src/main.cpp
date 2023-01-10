#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <exception>

int	main(void)
{

	std::cout << "Creating Intern..." << std::endl;

	Intern randomMan;


	std::cout << "Creating Form With Inter..." << std::endl;

	AForm *shrub = randomMan.makeForm("shrubbery creation", "tar_shushu");
	AForm *robot = randomMan.makeForm("robotomy request", "tar_roro");
	AForm *president = randomMan.makeForm("presidential pardon", "tar_pipo");
	AForm *unknown = randomMan.makeForm("unknown", "tar_unknown");



	std::cout << std::endl;

	try {
		std::cout << "Displaying form infos..." << std::endl;
		std::cout << "shrub -> " << "name: " << shrub->getName() <<  std::endl;
		std::cout << "robot -> " << "name: " << robot->getName() << std::endl;
		std::cout << "president -> " << "name: " << president->getName() << std::endl;
		std::cout << "unknown -> " << unknown << std::endl;


	} catch (std::exception & err) {

		std::cout << "\n- - - - - - -I guess there is some problem with grades or signing - - - - - -\n";
		std::cout << err.what();
	}
	std::cout << std::endl;




	std::cout << std::endl << std::endl;
	std::cout << "- - - - - - - Destructor calling - - - - - - -" << std::endl;
	
	delete shrub;
	delete robot;
	delete president;
	delete unknown;

	return (0);
}
