#include "GodType.hpp"
#include <limits>

bool 	GodType::verbose = false;

int	const GodType::_errInt = 1;
int	const GodType::_errFloat = 2;


//void (GodType::* _convertAll[4])(void) = {

void (GodType::* GodType::_convertAll[4])(void) = {
	&GodType::_convertAllFromChar,
	&GodType::_convertAllFromInt,
	&GodType::_convertAllFromFloat,
	&GodType::_convertAllFromDouble
};

/*
void GodType::initConvertAll(void) {

	GodType::_convertAll[0] = &GodType::_convertAllFromChar;
	_convertAll[1] = &GodType::_convertAllFromInt;
	_convertAll[2] = &GodType::_convertAllFromFloat;
	_convertAll[3] = &GodType::_convertAllFromDouble;

}
*/


GodType::ImpossibleConversionException::ImpossibleConversionException(void) : _type(NOTYPE) {}

GodType::ImpossibleConversionException::ImpossibleConversionException(EType const type) : _type(type) {}

GodType::ImpossibleConversionException::~ImpossibleConversionException(void) throw() {}

char const * GodType::ImpossibleConversionException::what(void) const throw() {

	if (this->_type == INT)
		return "ImpossibleConversionException from: int";
	else if (this->_type == FLOAT)
		return "ImpossibleConversionException from: float";
	else if (this->_type == DOUBLE)
		return "ImpossibleConversionException from: double";
	else if (this->_type == CHAR)
		return "ImpossibleConversionException from: char";
	else
		return "ImpossibleConversionException from: notype";

}

// -----------------------------------------------------------------------

GodType::GodType(void) {

	if (GodType::verbose)
		std::cout << "GodType constructor default called" << std::endl;

}

GodType::GodType(std::string const & input) : _strT(input), _type(this->_whatType(input)){

	if (GodType::verbose)
		std::cout << "GodType constructor string called" << std::endl;
	
	this->_errCode = 0;
	

	try {
		this->_parse();
		(this->*_convertAll[this->_type])();
	} catch (ImpossibleConversionException & e) {
		std::cout << e.what() << std::endl;
		std::cout << "I can only accept a number or a char" << std::endl;
	}



	//(this->*GodType::_convertAll[this->_type])();


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

std::string GodType::strtype(EType type) {

	switch (type) {
		case GodType::CHAR: return "char";
		case GodType::INT: return "int";
		case GodType::FLOAT: return "float";
		case GodType::DOUBLE: return "double";
		case GodType::NOTYPE: return "notype";
		default: return "unknown";
	}
}

size_t GodType::countof(std::string const &str, std::string const & set) {
	
	size_t count = 0;
	for (size_t i = 0; i < str.length(); i++)
		if (set.find(str[i]) != std::string::npos)
			count++;
	return count;
}

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

void GodType::displayAll(void) const {

	if (this->_type == NOTYPE) {
		std::cout << "Impossible to display all" << std::endl;
		return ;
	}

	// --------------- char ------------------
	std::cout << "char: ";
	if (this->_errCode & GodType::_errInt)
		std::cout << "impossible";
	else if (std::isprint(this->_charT))
		std::cout << "'" << this->_charT << "'";
	else
		std::cout << "Non displayable";	
	std::cout << std::endl;

	// --------------- int ------------------
	std::cout << "int: ";
	if (this->_errCode & GodType::_errInt)
		std::cout << "impossible";
	else
		std::cout << this->_intT;
	std::cout << std::endl;

	// --------------- float ----------------
	std::cout << "float: ";
	if (this->_errCode & GodType::_errFloat)
		std::cout << "impossible";
	else
		std::cout << std::setprecision(1) << std::fixed << this->_floatT << "f";
	std::cout << std::endl;

	// --------------- double ---------------
	std::cout << "double: ";
	std::cout << this->_doubleT;
	std::cout << std::endl;
}

GodType::EType GodType::_whatType(std::string const & str) const {

	if (GodType::isValid(str, float()))
		return GodType::FLOAT;
	else if (GodType::isValid(str, double()))
		return DOUBLE;
	else if (GodType::isValid(str, int()))
		return GodType::INT;
	else if (GodType::isValid(str, char()))
		return GodType::CHAR;
	else
		return NOTYPE;
}

void GodType::_parse(void) {

	if (verbose) {
		std::cout << "Parsing: " << this->_strT << std::endl;
		std::cout << "Type: " << GodType::strtype(this->_type) << std::endl << std::endl;
	}

	if (this->_type == GodType::CHAR)
		this->_charT = this->_strT[0];
	else if (this->_type == GodType::INT)
		this->_intT = atoi(this->_strT.c_str());
	else if (this->_type == GodType::FLOAT)
		this->_floatT = atof(this->_strT.c_str());
	else if (this->_type == GodType::DOUBLE)
		this->_doubleT = atof(this->_strT.c_str());
	else
		throw GodType::ImpossibleConversionException();
}

void GodType::_convertAllFromChar(void) {

	if (verbose)
		std::cout << "GodType::_convertAllFromChar called" << std::endl;

	if (this->_type == GodType::CHAR) {
		this->_intT = static_cast<int>(this->_charT);
		this->_floatT = static_cast<float>(this->_charT);
		this->_doubleT = static_cast<double>(this->_charT);
	}
	else
		throw GodType::ImpossibleConversionException(this->_type);
}

void GodType::_convertAllFromFloat(void) {

	if (verbose)
		std::cout << "GodType::_convertAllFromFloat called" << std::endl;

	if (this->_type == GodType::FLOAT) {
		this->_charT = static_cast<char>(this->_floatT);
		this->_intT = static_cast<int>(this->_floatT);
		this->_doubleT = static_cast<double>(this->_floatT);
	}
	else
		throw GodType::ImpossibleConversionException(this->_type);
	
	
	if (GodType::isConvertibleToInt(this->_floatT) == false)
		this->_errCode += GodType::_errInt;
	
}

void GodType::_convertAllFromDouble(void) {

	if (verbose)
		std::cout << "GodType::_convertAllFromDouble called" << std::endl;

	if (this->_type == GodType::DOUBLE) {
		this->_charT = static_cast<char>(this->_doubleT);
		this->_intT = static_cast<int>(this->_doubleT);
		this->_floatT = static_cast<float>(this->_doubleT);
	}
	else
		throw GodType::ImpossibleConversionException(this->_type);

	if (GodType::isConvertibleToInt(this->_doubleT) == false)
		this->_errCode += GodType::_errInt;
	if (GodType::isConvertibleToFloat(this->_doubleT) == false)
		this->_errCode += GodType::_errFloat;
}

void GodType::_convertAllFromInt(void) {

	if (verbose)
		std::cout << "GodType::_convertAllFromInt called" << std::endl;

	if (this->_type == GodType::INT) {
		this->_charT = static_cast<char>(this->_intT);
		this->_floatT = static_cast<float>(this->_intT);
		this->_doubleT = static_cast<double>(this->_intT);
	}
	else
		throw GodType::ImpossibleConversionException(this->_type);
}

//-                        static functions                         -//
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

bool GodType::isSignGood(std::string const & str) {

	
	if ((str.length() > 1 && countof(str, "+-") == 1 && (str[0] == '-' || str[0] == '+')) ||
			(countof(str, "+-") == 0))
		return true;
	return false;
}

bool GodType::isValid(std::string const &str, float) {

	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;

	if (str.find_first_not_of("-+.0123456789fF") == std::string::npos &&
			isSignGood(str) &&
			GodType::countof(str, "fF") == 1 &&
			GodType::countof(str, ".") == 1 &&
			str.length() > 2 &&
			str.find_first_of("fF") == str.length() - 1) {
		
		return true;
	}

	return false;
}

bool GodType::isValid(std::string const &str, double) {

	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;
 
	if (str.find_first_not_of("-+.0123456789") == std::string::npos &&
			isSignGood(str) &&
			GodType::countof(str, ".") == 1 &&
			str.length() > 1)
			return true;

	return false;
}

bool GodType::isValid(std::string const &str, int) {

	if (str.find_first_not_of("-+0123456789") == std::string::npos &&
			isSignGood(str) &&
			str.length() > 0) {

		return true;
	}
	return false;
}

bool GodType::isValid(std::string const &str, char) {

	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
		return true;
	return false;
}

bool GodType::isConvertibleToFloat(double nb) {
	
	if (nb != std::numeric_limits<double>::infinity() && nb != -std::numeric_limits<double>::infinity())
		if (nb > std::numeric_limits<float>::max() || nb < -std::numeric_limits<float>::max())
			return false;
	return true;
}

bool GodType::isConvertibleToInt(double nb) {

	if (nb > std::numeric_limits<int>::max() ||
			nb < std::numeric_limits<int>::min() ||
			std::isnan(nb) ||
			nb == std::numeric_limits<double>::infinity() ||
			nb == -std::numeric_limits<double>::infinity()) {

		return false;
	}
	return true;
}

// -                 end of static functions                      -//
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

