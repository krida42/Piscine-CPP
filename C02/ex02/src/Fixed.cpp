#include "Fixed.hpp"


int Fixed::verbose = 0;

int const Fixed::_nb_fractional_bits = 8;

int Fixed::getNbFractional_bits(void) {
	return Fixed::_nb_fractional_bits;
}

Fixed &	Fixed::min(Fixed & a, Fixed & b) {
	if (a < b)
		return a;
	return b;
}

const Fixed & Fixed::min(Fixed const & a, Fixed const & b) {
	if (a < b)
		return a;
	return b;
}


Fixed &	Fixed::max(Fixed & a, Fixed & b) {
	if (a > b)
		return a;
	return b;
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b) {
	if (a > b)
		return a;
	return b;
}

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

bool Fixed::operator==(Fixed const & rhs) const { 
	return  this->getRawBits() == rhs.getRawBits();
}


bool Fixed::operator!=(Fixed const & rhs) const { 
	return !(*this == rhs);
}

bool Fixed::operator<(Fixed const & rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}


bool Fixed::operator>(Fixed const & rhs) const {
	return rhs < *this;
}


bool Fixed::operator<=(Fixed const & rhs) const {
	return !(*this > rhs);
}

bool Fixed::operator>=(Fixed const & rhs) const {
	return !(*this < rhs);
}

Fixed Fixed::operator+(Fixed const &rhs) const {
	
	Fixed res;

	res.setRawBits(this->getRawBits() + rhs.getRawBits());
	return res;
}

Fixed Fixed::operator-(Fixed const &rhs) const {
	
	Fixed res;
	
	res.setRawBits(this->getRawBits() - rhs.getRawBits());
	return res;
}

Fixed Fixed::operator*(Fixed const &rhs) const {
	
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const {
	
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &	Fixed::operator++(void) {
	
	this->_raw++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	
	Fixed prev(*this);
	
	++*this;
	return prev;
}

Fixed &	Fixed::operator--(void) {
	
	this->_raw--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	
	Fixed prev(*this);
	
	--*this;
	return prev;
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