#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# pragma once

# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

public:

    RobotomyRequestForm(std::string const & target);
    RobotomyRequestForm(RobotomyRequestForm const & src);
    ~RobotomyRequestForm(void);

    std::string const & getTarget(void) const;

    void    execute(Bureaucrat const & executor) const;

private:
    
        static int const _requiredToSign;
        static int const _requiredToExecute;
        static std::string const _formName;


        RobotomyRequestForm(void);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

        std::string const _target;
        
};    



#endif
