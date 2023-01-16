#include "BaseABC.hpp"

int main(void) {


    Base  * a =  new A();
    Base  * b =  new B();
    Base  * c =  new C();

    Base * p = generate();
    
    identify(a);
    identify(b);
    identify(c);
    identify(p);

    delete a;
    delete b;
    delete c;
    delete p;


    return 0;
}