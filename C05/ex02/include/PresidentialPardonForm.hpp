#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# pragma once

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

public:

    PresidentialPardonForm(std::string const & target);
    PresidentialPardonForm(PresidentialPardonForm const & src);
    ~PresidentialPardonForm(void);

    std::string const & getTarget(void) const;

    void    execute(Bureaucrat const & executor) const;

private:
    
        static int const _requiredToSign;
        static int const _requiredToExecute;
        static std::string const _formName;


        PresidentialPardonForm(void);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

        std::string const _target;
        
};    



#endif
