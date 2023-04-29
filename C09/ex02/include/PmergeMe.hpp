#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# pragma once

# include <iostream>
# include <string>
# include <sys/types.h>
# include <vector>
# include <deque>

class PmergeMe {
public:
    typedef std::vector<uint> vector_type;
    typedef std::deque<uint> deque_type;

    static vector_type insert_sort(vector_type const & arr);
    static vector_type merge_sort(vector_type const & arr);
    static vector_type merge_insert_sort(vector_type const & arr);
    
    static deque_type insert_sort(deque_type const & arr);
    static deque_type merge_sort(deque_type const & arr);
    static deque_type merge_insert_sort(deque_type const & arr);

    static bool is_sorted(vector_type const & arr);
    static bool is_sorted(deque_type const & arr);
    ~PmergeMe();

private:
    PmergeMe(void);
    PmergeMe(PmergeMe const & src);
    PmergeMe & operator=(PmergeMe const & rhs);

public:
    class InvalidCharacterException : public std::exception {
        public: char const * what() const throw();
    };

};


#endif