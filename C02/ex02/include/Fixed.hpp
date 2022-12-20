#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

# define VERBOSE 0

class Fixed {

    public:

        static int verbose;


        static int    getNbFractional_bits(void);

        static Fixed &          min(Fixed & a, Fixed & b);
        static const Fixed &    min(Fixed const & a, Fixed const & b);

        static  Fixed &         max(Fixed  & a, Fixed  & b);
        static const Fixed &    max(Fixed const & a, Fixed const & b);

        Fixed(void);
        Fixed(Fixed const & src);
        Fixed(int const nb);
        Fixed(float const nb);
        ~Fixed();

        Fixed & operator=(Fixed const & rhs);

        bool operator==(Fixed const & rhs) const;
        bool operator!=(Fixed const & rhs) const;
        bool operator<(Fixed const & rhs) const;
        bool operator>(Fixed const & rhs) const;
        bool operator<=(Fixed const & rhs) const;
        bool operator>=(Fixed const & rhs) const;
        
        Fixed operator+(Fixed const & rhs) const;
        Fixed operator-(Fixed const & rhs) const;
        Fixed operator*(Fixed const & rhs) const;
        Fixed operator/(Fixed const & rhs) const;
        
        Fixed & operator++(void);
        Fixed operator++(int);
        
        Fixed & operator--(void);
        Fixed operator--(int);


        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;


    private:

        static int  const _nb_fractional_bits;

        int _raw;


};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
#endif
