#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(std::string const & str) {
    this->_str = str;
    try {
        this->_result = this->_calculate();
    }
    catch(const InvalidExprException& e) {
        this->_result = std::numeric_limits<double>::quiet_NaN();
        // std::cerr << e.what() << '\n';
    }
    
}

RPN::RPN(RPN const & src) {
    *this = src;
}

RPN & RPN::operator=(RPN const & rhs) {
    if (this != &rhs) {
        this->_str = rhs._str;
        this->_result = rhs._result;
    }
    return *this;
}

std::string RPN::getStr() const {
    return this->_str;
}

long double RPN::getResult() const {
    return this->_result;
}

double RPN::_calculate() {

    if (_str.find_first_not_of("0123456789+-/* ") != std::string::npos)
        throw InvalidExprException();

    std::stack<double> pile;
    std::istringstream iss(this->_str);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (pile.size() < 2) {
                throw InvalidExprException();
            }
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();

            if (token == "+") {
                pile.push(a + b);
            } else if (token == "-") {
                pile.push(a - b);
            } else if (token == "*") {
                pile.push(a * b);
            } else if (token == "/") {
                pile.push(a / b);
            }
        } else {
            // std::cout << "token: |" << token << "|" << std::endl;
            pile.push(atof(token.c_str()));
        }
    }

    if (pile.size() != 1) {
        throw InvalidExprException();
    }

    return pile.top();
}

char const * RPN::InvalidExprException::what() const throw() {
    return "Invalid expression in string";
}

std::ostream & operator<<(std::ostream & o, RPN const & rhs) {
    o << rhs.getStr() << " = " << rhs.getResult();
    return o;

}