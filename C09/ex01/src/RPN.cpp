#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(std::string const & str) {
    this->_str = str;
    this->_convert();
}

RPN::RPN(RPN const & src) {
    *this = src;
}

RPN & RPN::operator=(RPN const & rhs) {
    if (this != &rhs) {
        this->_str = rhs._str;
        this->_rpn = rhs._rpn;
    }
    return *this;
}

std::string RPN::getStr() const {
    return this->_str;
}

RPN::list_type RPN::getRpn() const {
    return this->_rpn;
}

void RPN::_convert() {

    if (_str.find_first_not_of("0123456789+-/* ") != std::string::npos)
        throw InvalidTokenException();

    std::string nb = "";
    std::string::const_iterator it;
    for (it = _str.cbegin(); it != _str.cend(); ++it) {
        if (!isdigit(*it) && !nb.empty()) {
            _rpn.push_back(nb);
            nb.clear();
        }
        if (*it == ' ')
            continue;
        if (isdigit(*it))
            nb += *it;
        else
            _rpn.push_back(std::string(1, *it));
    }
}

char const * RPN::InvalidTokenException::what(void) const throw() {
    return "Invalid token in string";
}

std::ostream & operator<<(std::ostream & o, RPN const & rhs) {
    RPN::list_type tmp = rhs.getRpn();
    std::cout << "RPN: |";
    for (RPN::list_type::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
        std::cout << *it << "|";
    return o;
}