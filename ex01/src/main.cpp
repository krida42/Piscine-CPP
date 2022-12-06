#include <iostream>
#include "Contact.hpp"
int main(void)
{

    Contact contact("Stan", "LeVent", "Wax", "06 78 94 12 54", "Que je suis un groslard");
    std::cout << "\n";
    contact.describe();
    std::cout << "\n";
    return 0;
}
