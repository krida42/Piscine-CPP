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
		CHAR = 0,
		INT   ,
		FLOAT ,
		DOUBLE,
		NOTYPE
	};

	class ImpossibleConversionException : public std::exception {
		private:
			EType const _type;
		public:
		 	ImpossibleConversionException(void);
			ImpossibleConversionException(EType const type);
			~ImpossibleConversionException(void) throw();
			char const *what() const throw();
	};


public:

	static bool verbose;
	
	static std::string strtype(EType type);

	static size_t countof(std::string const & str, std::string const & set);

	static bool isValid(std::string const & str, char);
	static bool isValid(std::string const & str, int);
	static bool	isValid(std::string const & str, float);
	static bool	isValid(std::string const & str, double);

	static bool isConvertibleToInt(double nb);
	static bool isConvertibleToFloat(double nb);

	static bool isSignGood(std::string const & str);

	GodType(std::string const & input);
	GodType(GodType const & src);
	~GodType(void);

	GodType & operator=(GodType const & rhs);

	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;

	void	displayAll(void) const;


	static void initConvertAll(void);
	static void (GodType::* _convertAll[4])(void);

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
