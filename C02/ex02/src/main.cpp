#include "Fixed.hpp"


/*
int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}
*/


/*
// Unit Tests
# include "Fixed.class.hpp"
# include <cassert>

int main() {

    // getNbFractional_bits
    assert(Fixed::getNbFractional_bits() == 8);

    // min
    Fixed a(42.42f);
    Fixed b(44.44f);
    Fixed const & min1 = Fixed::min(a, b);
    assert(min1.toFloat() == 42.42f);
    Fixed & min2 = Fixed::min(a, b);
    assert(min2.toFloat() == 42.42f);
    Fixed c(min1);
    Fixed const & min3 = Fixed::min(a, c);
    assert(min3.toFloat() == 42.42f);
    Fixed & min4 = Fixed::min(a, c);
    assert(min4.toFloat() == 42.42f);

    // max
    Fixed const & max1 = Fixed::max(a, b);
    assert(max1.toFloat() == 44.44f);
    Fixed & max2 = Fixed::max(a, b);
    assert(max2.toFloat() == 44.44f);
    Fixed d(max1);
    Fixed const & max3 = Fixed::max(a, d);
    assert(max3.toFloat() == 44.44f);
    Fixed & max4 = Fixed::max(a, d);
    assert(max4.toFloat() == 44.44f);

    // constructor
    Fixed e;
    assert(e.toFloat() == 0.0f);
    Fixed f(42);
    assert(f.toFloat() == 42.0f);
    Fixed g(42.42f);
    assert(g.toFloat() == 42.42f);

    // copy constructor
    Fixed h(g);
    assert(h.toFloat() == 42.42f);

    // operator =
    e = h;
    assert(e.toFloat() == 42.42f);

    // operator ==
    assert(h == g);

    // operator !=
    assert(h != e);

    // operator <
    assert(e < h);

    // operator >
    assert(h > e);

    // operator <=
    assert(e <= h);

    // operator >=
    assert(h >= e);

    // operator +
    Fixed i(42);
    Fixed j(10);
    assert((i + j).toFloat() == 52.0f);

    // operator -
    assert((i - j).toFloat() == 32.0f);

    // operator *
    assert((i * j).toFloat() == 420.0f);

    // operator /
    assert((i / j).toFloat() == 4.2f);

    // operator ++
    Fixed k(42);
    assert((++k).toFloat() == 43.0f);
    Fixed l(42);
    assert((l++).toFloat() == 42.0f);

    // operator --
    Fixed m(42);
    assert((--m).toFloat() == 41.0f);
    Fixed n(42);
    assert((n--).toFloat() == 42.0f);

    // getRawBits
    assert(e.getRawBits() == 70368744177664);

    // setRawBits
    e.setRawBits(0);
    assert(e.getRawBits() == 0);

    // toFloat
    assert(f.toFloat() == 42.0f);

    // toInt
    assert(i.toInt() == 42);

    // ostream
    std::ostringstream oss;
    oss << h;
    assert(oss.str() == "42.42f");

    return 0;
}
*/

/*
// Unit test
int main()
{
    Fixed a, b;
    a = 1;
    b = 3;

    //operator=
    Fixed c;
    c = a;
    if (c.getRawBits() == a.getRawBits())
        std::cout << "operator= works correctly" << std::endl;

    //operator==
    if (a == c)
        std::cout << "operator== works correctly" << std::endl;

    //operator!=
    if (a != b)
        std::cout << "operator!= works correctly" << std::endl;

    //operator<
    if (a < b)
        std::cout << "operator< works correctly" << std::endl;

    //operator>
    if (b > a)
        std::cout << "operator> works correctly" << std::endl;

    //operator<=
    if (a <= b)
        std::cout << "operator<= works correctly" << std::endl;

    //operator>=
    if (b >= a)
        std::cout << "operator>= works correctly" << std::endl;

    //operator+
    if ((a + b).getRawBits() == (c+b).getRawBits())
        std::cout << "operator+ works correctly" << std::endl;

    //operator-
    if ((b - a).getRawBits() == (b-c).getRawBits())
        std::cout << "operator- works correctly" << std::endl;

    //operator*
    if ((a * b).getRawBits() == (c*b).getRawBits())
        std::cout << "operator* works correctly" << std::endl;

    //operator/
    if (fabs((b / a).getRawBits() - (b/c).getRawBits()) < 1)
        std::cout << "operator/ works correctly" << std::endl;

    //operator++
    if ((++a).getRawBits() == (c++).getRawBits())
        std::cout << "operator++ works correctly" << std::endl;

    //operator--
    if ((--b).getRawBits() == (b--).getRawBits())
        std::cout << "operator-- works correctly" << std::endl;

    return 0;
}
*/

// Unit Tests
:

int main(void)
{
    std::cout << "Assert equal ";
    Fixed a(2);
    Fixed b(2);
    assert_equal(a, b);

    std::cout << "Assert not equal ";
    Fixed c(4);
    assert_not_equal(a, c);

    std::cout << "Assert less ";
    assert_less(a, c);

    std::cout << "Assert greater ";
    assert_greater(c, a);

    std::cout << "Assert less equal ";
    assert_less_equal(a, c);

    std::cout << "Assert greater equal ";
    assert_greater_equal(a, b);

    std::cout << "Assert addition ";
    assert_addition(a, b, c);

    std::cout << "Assert subtraction ";
    assert_subtraction(c, b, a);

    std::cout << "Assert multiplication ";
    Fixed d(8);
    assert_multiplication(c, b, d);

    std::cout << "Assert division ";
    assert_division(d, b, c);

    std::cout << "Assert increment ";
    assert_increment(a, c);

    std::cout << "Assert decrement ";
    assert_decrement(c, a);

    return 0;
}