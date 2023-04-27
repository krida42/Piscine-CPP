#ifndef RPN_HPP
# define RPN_HPP
# pragma once

# include <string>
# include <list>
# include <iostream>
# include <exception>

class RPN
{
public:

    typedef std::list<std::string>	list_type;
    RPN(std::string const &str);
    RPN(RPN const &src);
    ~RPN();

    RPN &operator=(RPN const &rhs);

    std::string	getStr() const;
    list_type       getRpn() const;
    double		getResult() const;

private:

    RPN();

    std::string _str;
    list_type	    _rpn;
    
    void		_calculate();
    void		_convert();

    class InvalidTokenException : std::exception {
        public: char const * what() const throw();
    };

};

std::ostream & operator<<(std::ostream & o, RPN const & rhs);

#endif