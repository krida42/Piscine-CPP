#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact {

public:
    Contact(std::string firstName, std::string lastName,
            std::string nickName, std::string phoneNumber,
            std::string darkestSecret);
    ~Contact(void);

    void    show(void) const;


private:
    std::string const firstName;
    std::string const lastName;
    std::string const nickName;
    std::string const phoneNumber;
    std::string const darkestSecret;
};

#endif