#include "Bureaucrat.hpp"
#include <exception>

int	main(void)
{
	std::cout << "Creating a bureaucrats" << std::endl;
	Bureaucrat damien;
	Bureaucrat deniz("Deniz", 1);
	Bureaucrat josh("Josh", 20);
	Bureaucrat jef("Jeff", 1);
	Form form("Formulaire 1", 1, 1);
	Form form2("Formulaire 2", 150, 150);
	//Form form3("Form3", 1500, 15); // should throw an exception
	


	std::cout << std::endl;

	try {

		std::cout << "damien: "  << damien << std::endl;
		std::cout << "deniz: "  << deniz << std::endl;

		deniz = damien;

		std::cout << "deniz: " << deniz << std::endl;

		Bureaucrat deniz2(josh);

		std::cout << "deniz2: " << deniz2 << std::endl << std::endl;

		josh.upgrade();
		std::cout << "josh: " << josh << std::endl;
		josh.downgrade();
		std::cout << "josh: " << josh << std::endl;
		//damien.downgrade(); // should throw an exception
		//jef.upgrade(); // should throw an exception
		damien.signForm(form2);
		damien.signForm(form); //cannot sign form

		std::cout << "Form 1: " << form << std::endl;
		jef.signForm(form);
		std::cout << "Form 1: " << form << std::endl;

	} catch (Bureaucrat::GradeTooLowException & err) {

		std::cout << "\nI guess grade is too low...\n";
		std::cout << err.what();

	} catch (Bureaucrat::GradeTooHighException & err) {

		std::cout << "\nI guess grade is too high...\n";
		std::cout << err.what();
	} catch (std::exception & err) {

		std::cout << "\nI dont know what is the problem\n";
		std::cout << err.what();
	}
	std::cout << std::endl;




	std::cout << std::endl << std::endl;
	return (0);
}
