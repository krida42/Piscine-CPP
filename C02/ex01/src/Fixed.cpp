#include "Fixed.hpp"


int const Fixed::_nb_fractional_bits = 8;

Fixed::Fixed(void) : _raw(0) {
	std::cout << "Default construtor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {

	std::cout << "Copy constructore called " << std::endl;
	*this = src;
}

Fixed::Fixed(int const nb) {
	std::cout << "Constant integer constructore called" << std::endl;
	this->_raw = nb << Fixed::_nb_fractional_bits;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}


Fixed & Fixed::operator=(Fixed const & rhs) {

	std::cout << "Copy assignement operator called" << std::endl;
	this->_raw = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _raw;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}

