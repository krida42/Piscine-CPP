#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# pragma once

# include <stack>

template<typename T>

class MutantStack : public std::stack<T> {

public:
    MutantStack(void);
    MutantStack(MutantStack const & src);
    ~MutantStack(void);

    MutantStack<T> & operator=(MutantStack const & rhs);

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin(void);
    iterator end(void);

};

#endif

template <typename T>
MutantStack<T>::MutantStack(void) {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & src) {
    *this = src;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & rhs) {
    (void) rhs;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
    return this->c.end();
}