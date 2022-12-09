#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <sstream>

# define NUM_CONTACTS 8
class PhoneBook {

private:
    Contact     contacts[NUM_CONTACTS];
    void        _displayContacts(void) const;
    void        _promptAddFields(std::string res[]);
    static int  _num_contacts;

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void    execAdd(void);
    void    execSearch(void) const;




};

#endif