#ifndef GODTYPE_HPP
# define GODTYPE_HPP
# pragma once


# include <string>
# include <iomanip>
# include <iostream>
# include <limits>
# include <cmath>

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
		private:
			std::string const _msg;
		public:
		 	ImpossibleConversionException(void);
			ImpossibleConversionException(std::string const &msg);
			~ImpossibleConversionException(void) throw();
			char const *what() const throw();
	};


public:

	static bool verbose;
	
	static size_t countof(std::string const & str, std::string const & set);

	static bool isValid(std::string const & str, char);
	static bool isValid(std::string const & str, int);
	static bool	isValid(std::string const & str, float);
	static bool	isValid(std::string const & str, double);

	static bool isConvertibleToInt(double nb);
	static bool isConvertibleToFloat(double nb);

	GodType(std::string const & input);
	GodType(GodType const & src);
	~GodType(void);

	GodType & operator=(GodType const & rhs);

	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;

	void	displayAll(void) const;
	



private:

	static int const _errInt;
	static int const _errFloat;

	std::string const _strT;
	char 	_charT;
	int 	_intT;
	float	_floatT;
	double	_doubleT;

	EType	_type;
	int		_errCode;

	
	GodType(void);

	EType	_whatType(std::string const & str) const;
	void	_parse(void);

	void	_convertAllFromChar(void);
	void	_convertAllFromInt(void);
	void	_convertAllFromFloat(void);
	void	_convertAllFromDouble(void);


};

#endif
