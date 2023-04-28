# include "PmergeMe.hpp"

bool PmergeMe::is_sorted(vector_type const & arr) {
    if (arr.size() < 2)
        return true;

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

PmergeMe::vector_type PmergeMe::insert_sort(vector_type const & arr) {
    vector_type sorted(arr);

    if (sorted.size() < 2)
        return sorted;
    
    vector_type::iterator it = sorted.begin() + 1;
    size_t sz_sorted = 1;

    while (it != sorted.end()) {

        vector_type::iterator prev = it - 1;

        while (prev != sorted.begin() - 1 && *prev > *it) {
            --prev;
        }
        if (prev + 1 != it) {
            uint val = *it;
            sorted.erase(it);
            sorted.insert(prev + 1, val);
            it = sorted.begin() + sz_sorted;
        }
        ++it;
        ++sz_sorted;
    }

    return sorted;
}


PmergeMe::vector_type PmergeMe::merge_sort(vector_type const & arr) {
    
}


PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const & src) {
    *this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
    (void) rhs;
    return *this;
}


