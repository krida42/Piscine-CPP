#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

# define VERBOSE 0

class Fixed {

    public:

        static int verbose;

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
