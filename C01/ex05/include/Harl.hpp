#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>



class Harl {

    public:
        void complain(std::string level);

    private:
        static std::string levels[];

        void    debug(void) const ;
        void    info(void) const;
        void    warning(void) const;
        void    error(void) const;
};

#endif
