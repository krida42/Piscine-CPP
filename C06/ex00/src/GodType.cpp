#include "GodType.hpp"

bool GodType::verbose = true;

char const * GodType::ImpossibleConversionException::what(void) const throw() {
	return "ImpossibleConversionException";
}

// -----------------------------------------------------------------------

GodType::GodType(void) {

	if (GodType::verbose)
		std::cout << "GodType constructor default called" << std::endl;

	this->getType();
}

GodType::GodType(std::string const & input) : _strT(input) {

}

GodType::GodType(GodType const & src) {

	if (GodType::verbose)
		std::cout << "GodType constructor copy called" << std::endl;
	*this = src;
}

GodType::~GodType(void) {

	if (GodType::verbose)
		std::cout << "GodType destructor called" << std::endl;
}

GodType & GodType::operator=(GodType const & rhs) {

	if (GodType::verbose)
		std::cout << "GodType operator= called" << std::endl;
	if (this != &rhs)
	{
		this->_charT = rhs.getChar();
		this->_intT = rhs.getInt();
		this->_floatT = rhs.getFloat();
		this->_doubleT = rhs.getDouble();
	}
	return *this;
}

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

char GodType::getChar(void) const { return this->_charT; }

int GodType::getInt(void) const { return this->_intT; }

float GodType::getFloat(void) const { return this->_floatT; }

double GodType::getDouble(void) const { return this->_doubleT; }

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

GodType::EType GodType::getType(void) const {

	if (this->_strT.length() == 1 && isprint(this->_strT[0]) && !isdigit(this->_strT[0]))
		return CHAR;
	else if (this->_strT.find_first_not_of("0123456789fF") == std::string::npos)
		if (this->_strT.find_first_of("fF") != std::string::npos)
			return GodType::FLOAT;
		else if (this->_strT.find('.') != std::string::npos)
			return GodType::DOUBLE;
		else
			return GodType::INT;
	return NOTYPE;
}

bool GodType::isValid(std::string const &str, float) {

	float f;
	if (str.find_first_not_of("0123456789fF") == std::string::npos)
		if (str.find_first_of("fF") != std::string::npos)
			if (GodType::countof(str, "fF") == 1)
				if (sscanf(str.c_str(), "%f", &f) == 1)
					return true;
			return true;
}

size_t GodType::countof(std::string const &str, std::string const & set) {
	
	size_t count = 0;
	for (size_t i = 0; i < str.length(); i++)
		if (set.find(str[i]) != std::string::npos)
			count++;
	return count;
}