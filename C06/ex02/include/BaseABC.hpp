#ifndef BASEABC_HPP
# define BASEABC_HPP
# pragma once

# include <iostream>
# include <cstdlib>
# include <ctime>

class Base {
public:
    virtual ~Base(void);
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base * generate(void);
void 	identify(Base *p);
void 	identify(Base &p);





#endif
