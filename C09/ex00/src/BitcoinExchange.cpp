#include "BitcoinExchange.hpp"


std::string BitcoinExchange::nb_to_date_string(long nb) {
    int year = nb / 10000;
    int month = (nb / 100) % 100;
    int day = nb % 100;
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << day << " / " << std::setfill('0') << std::setw(2) << month << " / " << year;
    return ss.str();
}


BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) { (void)src;}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
    (void)rhs;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::string const & filename) {
    std::ifstream ifs;

    ifs.open(filename);
    if (!ifs.is_open()) {
        std::cout << "Le fichier data.csv n'a pas pu etre ouvert" << std::endl;
        perror(filename.c_str());
    }
    
    std::string buf;
    while (std::getline(ifs, buf))
        this->add_price(buf);
}

void BitcoinExchange::add_price(std::string const & data) {
    size_t comma_i = data.find(',');
    if (comma_i == std::string::npos)
        throw std::runtime_error("No comma separator found in the line");
    
    std::string date_s = data.substr(0, comma_i);
    long nb = 0;
    for (size_t i = 0; i < date_s.length(); i++) {
        if (date_s[i] == '-')
            continue;
        nb *= 10;
        nb += date_s[i] - '0';
    }
    
    std::string price = data.substr(comma_i + 1, std::string::npos);
    _price_history[nb] = atof(price.c_str());
    // std::cout << date_s << std::endl;
    // std::cout << nb << std::endl << std::endl;
}

BitcoinExchange::map_type const & BitcoinExchange::get_price_history(void) const {
    return this->_price_history;
}

std::ostream & operator<<(std::ostream & o, BitcoinExchange const & rhs) {
    BitcoinExchange::map_type price_history = rhs.get_price_history();

    BitcoinExchange::map_type::const_iterator it;
    size_t i = 0;
    for (it = price_history.cbegin(); it != price_history.cend(); ++it) {
        o << std::setw(20) << it->first << std::endl;
        o << std::setw(20)  << std::right << BitcoinExchange::nb_to_date_string(it->first);
        o << " : " << it->second << std::endl << std::endl;
        if (i > 300)
            break;
        ++i;
    }
    return o;
}