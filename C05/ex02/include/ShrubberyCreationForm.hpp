#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# pragma once

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

public:

    ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(ShrubberyCreationForm const & src);
    ~ShrubberyCreationForm(void);

    std::string const & getTarget(void) const;

    void    execute(Bureaucrat const & executor) const;

private:
    
        static int const _requiredToSign;
        static int const _requiredToExecute;
        static std::string const _formName;

        static void _writeAsciiTree(std::ofstream & ofs);

        ShrubberyCreationForm(void);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

        std::string const _target;
        
};    



#endif
