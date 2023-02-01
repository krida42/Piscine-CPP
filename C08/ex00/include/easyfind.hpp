#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# pragma once

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T & cnt, int toFind) {
    return std::find(cnt.begin(), cnt.end(), toFind);
}
#endif