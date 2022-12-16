#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {

    public:

        Fixed(void);
        Fixed(Fixed const & src);
        Fixed(int const nb);
        ~Fixed();

        Fixed & operator=(Fixed const & rhs);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:

        static int  const _nb_fractional_bits;

        int _raw;


};
#endif
