#ifndef GODTYPE_HPP
# define GODTYPE_HPP
# pragma once


# include <string>
# include <iostream>

class GodType {

private:

	enum EType {
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
	
	static size_t countof(std::string const & str, std::string const & set);

	static bool isValid(std::string const & str, char);
	static bool isValid(std::string const & str, int);
	static bool	isValid(std::string const & str, float);
	static bool	isValid(std::string const & str, double);

	GodType(std::string const & input);
	GodType(GodType const & src);
	~GodType();

	GodType & operator=(GodType const & rhs);

	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;

	EType	getType() const;
	



private:

	GodType();

	std::string const _strT;

	char 	_charT;
	int 	_intT;
	float	_floatT;
	double	_doubleT;



};

#endif
