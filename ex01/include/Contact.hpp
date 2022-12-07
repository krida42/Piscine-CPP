#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact {

public:
    Contact(void);
    Contact(std::string firstName, std::string lastName, std::string nickName,
            std::string phoneNumber, std::string darkestSecret);
    ~Contact(void);

    void    setContact(std::string firstName, std::string lastName, std::string nickName,
                       std::string phoneNumber, std::string darkestSecret);
    void    displayPreview(void) const;
	void	displayInformations(void) const;

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;


	void	_printColumn(std::string const str) const;
};

#endif
