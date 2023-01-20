#ifndef ITER_HPP
# define ITER_HPP
# pragma once

# include <cstddef>
# include <iostream>

template <typename T>

void putcharNl(T const & c) {

	std::cout << c << std::endl;
}

template <typename T>
void iter(T * array, size_t size,  void (*f)(T const & el)) {

	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif
