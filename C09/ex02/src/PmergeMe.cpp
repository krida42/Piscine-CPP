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

    size_t const sz = arr.size();
    
    if (sz < 2)
        return arr;

    vector_type::const_iterator first = arr.begin();
    vector_type::const_iterator mid = first + (sz / 2);
    vector_type::const_iterator last = arr.end();

    vector_type const left_sorted = merge_sort(vector_type(first, mid));
    vector_type const right_sorted = merge_sort(vector_type(mid, last));

    size_t left_size = left_sorted.size();
    size_t right_size = right_sorted.size();

    vector_type merged;

    size_t i = 0;
    size_t j = 0;

    while (i < left_size && j < right_size)
        if (left_sorted[i] < right_sorted[j])
            merged.push_back(left_sorted[i++]);
        else
            merged.push_back(right_sorted[j++]);
    
    while (i < left_size)
        merged.push_back(left_sorted[i++]);
    while (j < right_size)
        merged.push_back(right_sorted[j++]);

    return merged;
}

PmergeMe::vector_type PmergeMe::merge_insert_sort(vector_type const & arr) {
    size_t const sz = arr.size();
    
    if (sz < 2)
        return arr;
    else if (sz <= 42)
        return insert_sort(arr);

    vector_type::const_iterator first = arr.begin();
    vector_type::const_iterator mid = first + (sz / 2);
    vector_type::const_iterator last = arr.end();

    vector_type const left_sorted = merge_sort(vector_type(first, mid));
    vector_type const right_sorted = merge_sort(vector_type(mid, last));

    size_t left_size = left_sorted.size();
    size_t right_size = right_sorted.size();

    vector_type merged;

    size_t i = 0;
    size_t j = 0;

    while (i < left_size && j < right_size)
        if (left_sorted[i] < right_sorted[j])
            merged.push_back(left_sorted[i++]);
        else
            merged.push_back(right_sorted[j++]);

    while (i < left_size)
        merged.push_back(left_sorted[i++]);
    while (j < right_size)
        merged.push_back(right_sorted[j++]);

    return merged;
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


