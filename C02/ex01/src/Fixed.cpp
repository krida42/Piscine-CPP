#include "Fixed.hpp"


int Fixed::verbose = 1;

int const Fixed::_nb_fractional_bits = 8;

Fixed::Fixed(void) : _raw(0) {
	if (Fixed::verbose)
		std::cout << "Default construtor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {

	if (Fixed::verbose)
		std::cout << "Copy constructore called " << std::endl;
	*this = src;
}

Fixed::Fixed(int const nb) {

	if (Fixed::verbose)
		std::cout << "Int constructor called" << std::endl;
	this->_raw = nb << Fixed::_nb_fractional_bits;
}

Fixed::Fixed(float const nb) {

	if (Fixed::verbose)
		std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(nb * (1 << Fixed::_nb_fractional_bits));
}

Fixed::~Fixed(void) {

	if (Fixed::verbose)
		std::cout << "Destructor called" << std::endl;
}


Fixed & Fixed::operator=(Fixed const & rhs) {

	if (Fixed::verbose)
		std::cout << "Copy assignement operator called" << std::endl;
	this->_raw = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const {

	//if (Fixed::verbose)
		//std::cout << "getRawBits member function called" << std::endl;
	return _raw;
}

void	Fixed::setRawBits(int const raw) {

	//if (Fixed::verbose)
		//std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}

float	Fixed::toFloat(void) const {
	return (float)this->_raw / (1 << Fixed::_nb_fractional_bits);
}

int		Fixed::toInt(void) const {
	return this->_raw >> Fixed::_nb_fractional_bits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
};