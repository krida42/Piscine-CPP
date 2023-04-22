#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# pragma once

# include <map>
# include <fstream>    
# include <string>
# include <iostream>
# include <stdexcept>
# include <sstream>




class BitcoinExchange {
public:
    typedef std::map<long, double> map_type;

    static std::string nb_to_date_string(long nb);

    BitcoinExchange(std::string const & filename);
    ~BitcoinExchange();


    void add_price(std::string const & data);
    map_type const & get_price_history() const;
    

private:
    map_type _price_history;

    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & src);
    BitcoinExchange & operator=(BitcoinExchange const & rhs);

};

std::ostream & operator<<(std::ostream & o, BitcoinExchange const & rhs);
#endif