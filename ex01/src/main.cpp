#include <iostream>
#include "Contact.hpp"
int main(void)
{

    Contact contact("StanLeglagandodo", "LeVent", "Wax", "06 78 94 12 54", "Que je suis un groslard");
    std::cout << "\n";
    contact.displayPreview();
	std::cout << std::endl;
	contact.displayInformations();
    std::cout << "\n";
    return 0;
}
