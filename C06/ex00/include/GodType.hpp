#ifndef GODTYPE_HPP
# define GODTYPE_HPP
# pragma once


# include <string>
# include <iostream>

class GodType {

private:

	enum Type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		NOTYPE
	};

	class ImpossibleConversionException : public std::exception {
		public: char const * what() const throw();
	};


public:

	static bool verbose;

	GodType(std::string const & input);
	GodType(GodType const & src);
	~GodType();

	GodType & operator=(GodType const & rhs);

	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;

	Type	getType() const;


private:

	GodType();

	std::string const _strT;

	char 	_charT;
	int 	_intT;
	float	_floatT;
	double	_doubleT;



};

#endif
