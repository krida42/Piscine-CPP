#include "Span.hpp"

bool Span::verbose = true;

Span::Span(void) : _N(0){

    if (verbose)
        std::cout << "Span Default constructor called !" << std::endl;
}

Span::Span(unsigned int N):  _N(N) {

    if (Span::verbose)
        std::cout << "Span N parameter constructor called !" << std::endl;
}

Span::Span(Span const & src) : _N(src._N) {

	if (verbose)
		std::cout << "Span Copy constructor called !" << std::endl;
	*this = src;
}

Span & Span::operator=(Span const & rhs) {

	if (this != &rhs) {
		if (verbose)
			std::cout << "Span Assignation operator called !" << std::endl;
		this->_vec = rhs._vec;
	}
	return *this;
}

Span::~Span(void) {

    if (verbose)
        std::cout << "Span Destructor called !" << std::endl;
}

void Span::addNumber(int nb) {
    
    if (this->_vec.size() ==  this->_N)
        throw std::out_of_range("addNumber(int nb) - Cannot add more number to vector");

    if (verbose)
        std::cout << "Number: " << std::setw(3) << nb << "  added to vector ! " << std::endl;
    this->_vec.push_back(nb);
}

void Span::addIterator(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last) {

	if (distance(first, last) + this->_vec.size() > this->_N)
		throw std::out_of_range("addIterator(first, last) - Too much number to add to vector");
	
	if (verbose)
		std::cout << "Range of " << distance(first, last) << " number added to vector !" << std::endl;
	copy(first, last, back_inserter(this->_vec));
}

int Span::shortestSpan(void) const {

    if (this->_vec.size() < 2)
        throw std::out_of_range("shortestSpan(void) - Vector size is less than 2");
   
    std::vector<int> vec = this->_vec;
    sort(vec.begin(), vec.end());
    int shortest = vec[1] - vec[0];

    for (std::vector<int>::const_iterator it = vec.begin() + 1; it != vec.end(); ++it)
        if (shortest > *it - *(it - 1))
            shortest = *it - *(it - 1);
    
    return shortest;
}

int Span::longestSpan(void) const {

    if (this->_vec.size() < 2)
        throw std::out_of_range("longestSpan(void) - Vector size is less than 2");

    std::vector<int> vec = this->_vec;
    sort(vec.begin(), vec.end());
    return vec[vec.size() - 1] - vec[0];
}



std::string Span::toString(void) const {

    std::stringstream  ss;
    ss << "Vector: [";


    for (std::vector<int>::const_iterator it = this->_vec.begin(); it != this->_vec.end(); ++it) {
        ss << *it;
        if (it != this->_vec.end() - 1)
            ss << ", ";
    }
    ss << "]";

    return ss.str();
}