#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <exception>
# pragma once

# include <cstddef>
# include <iostream>
# include <stdexcept>
# include <sstream>

template <typename T>

class Array {

public:

	static bool verbose;

	Array(void) : _array(NULL), _size(0) {

		if (verbose)
			std::cout << "Default Array Constructor called !" << std::endl;
	}
	
	Array(unsigned int n) : _array(new T[n]), _size(n) {

		if (verbose)
			std::cout << "Size param Array Constructor called !" << std::endl;
	}

	Array(Array const & src) : _array(NULL), _size(0){

		if (verbose)
			std::cout << "Copy Constuctor Array called !" << std::endl;
		*this = src;
	}

	~Array(void) {

		if (verbose)
			std::cout << "Destructor Array called !" << std::endl;
		
		//if (this->_array)
		delete [] this->_array;
	}

	Array<T> &	operator=(Array<T> const & rhs) {

		if (verbose)
			std::cout << "Operator = Array called !" << std::endl;

		//if (this->_array)
		delete [] this->_array;

		this->_size = rhs.size();
		this->_array = new T[this->_size];
		for (size_t i = 0; i < this->_size; i++)
			this->_array[i] = (rhs.array())[i];
		return *this;
	}

	T & 		operator[](int index) const {

		if (verbose)
			std::cout << "Operator [] Array called !" << std::endl;

		if (index < 0 || static_cast<size_t>(index) >= this->_size) {
			std::stringstream ss("Array size: ");
			ss << this->_size << ", index: " << index;
			throw std::out_of_range(ss.str());
		}

		return this->_array[index];
	}
	
	
	size_t	size(void) const { return this->_size; }

	T *		array(void) const { return this->_array; }

private:

	T *		_array;
	size_t	_size;

};

template <typename T>
bool Array<T>::verbose = false;

template<typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & rhs) {

	T const * arr_tmp = rhs.array();
	std::stringstream ss;
	
	ss << "{\n";

	for (size_t i = 0; i < rhs.size(); i++)
		ss << "\t" << arr_tmp[i] << "\n";

	ss << "}\n";

	o << ss.str();
	return o;
}

#endif
