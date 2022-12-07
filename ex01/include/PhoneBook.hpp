#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>

# define NUM_CONTACTS 8
class PhoneBook {

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void    execAdd(void);
    void    execSearch(void);
    void    displayContacts(void) const;

private:
    Contact contacts[NUM_CONTACTS];


};

#endif