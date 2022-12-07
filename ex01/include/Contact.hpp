#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact {

public:
    Contact(void);
    ~Contact(void);

    void    setContact(std::string firstName, std::string lastName, std::string nickName,
                       std::string phoneNumber, std::string darkestSecret);
    void    displayPreview(void) const;
	void	displayInformations(void) const;

private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string nickName;
    std::string darkestSecret;


	void	printColumn(std::string const str) const;
};

#endif
