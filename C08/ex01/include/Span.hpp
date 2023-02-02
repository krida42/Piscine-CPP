#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <sstream>
# include <iomanip>
# include <iterator>

class Span {
public:

	static bool verbose;

	Span(unsigned int N);
	Span(Span const & src);
	~Span(void);

	Span & operator=(Span const & rhs);

	void addNumber(int nb);
	void addIterator(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);
	int shortestSpan(void) const;
	int longestSpan(void) const;

	std::string toString(void) const;

private:

	std::vector<int>	_vec;
	unsigned int const	_N;
	
	Span(void);
};


#endif