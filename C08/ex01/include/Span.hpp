#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <sstream>
# include <iomanip>

class Span {
public:

	static bool verbose;

	Span(unsigned int N);
	Span(Span const & src);
	~Span(void);

	Span & operator=(Span const & rhs);

	void addNumber(int nb);
	int shortestSpan(void) const;
	int longestSpan(void) const;

	std::string toString(void) const;

private:

	std::vector<int>	_vec;
	unsigned int const	_N;
	
	Span(void);
};


#endif