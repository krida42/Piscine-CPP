#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# pragma once

# include <iostream>
# include <string>
# include <sys/types.h>
# include <vector>

class PmergeMe {
public:
    typedef std::vector<uint> vector_type;

    static vector_type insert_sort(vector_type const & arr);
    static vector_type merge_sort(vector_type const & arr);
    static bool is_sorted(vector_type const & arr);
    ~PmergeMe();

private:
    PmergeMe(void);
    PmergeMe(PmergeMe const & src);
    PmergeMe & operator=(PmergeMe const & rhs);

};


#endif