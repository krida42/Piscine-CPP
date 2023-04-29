#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# pragma once

# include <map>
# include <fstream>    
# include <string>
# include <iostream>
# include <stdexcept>
# include <sstream>
# include <iomanip>
# include <cstdlib>




class BitcoinExchange {
public:
    typedef std::map<long, double> map_type;

    static std::string nb_to_date_string(long nb, bool french_format = false);
    static long date_string_to_nb(std::string const & date);



    BitcoinExchange(std::string const & filename);
    ~BitcoinExchange();


    void add_price(std::string const & data);
    map_type const & get_price_history() const;
    long get_first_date() const;
    long get_last_date() const;
    

private:
    map_type _price_history;
    long _first_date;
    long _last_date;


    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & src);
    BitcoinExchange & operator=(BitcoinExchange const & rhs);

};

std::ostream & operator<<(std::ostream & o, BitcoinExchange const & rhs);
#endif