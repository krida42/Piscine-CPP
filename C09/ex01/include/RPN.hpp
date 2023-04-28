#ifndef RPN_HPP
# define RPN_HPP
# pragma once

# include <string>
# include <list>
# include <iostream>
# include <exception>
# include <stack>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <cmath>

class RPN
{
public:

    typedef std::list<std::string>	list_type;
    RPN(std::string const &str);
    RPN(RPN const &src);
    ~RPN();

    RPN &operator=(RPN const &rhs);

    std::string	    getStr() const;
    long double		getResult() const;

private:

    RPN();

    std::string _str;
    long double _result;
    
    double      _calculate();
    void		_convert();

    class InvalidExprException : std::exception {
        public: char const * what() const throw();
    };

};

std::ostream & operator<<(std::ostream & o, RPN const & rhs);

#endif