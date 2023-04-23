#include "BitcoinExchange.hpp"


std::string BitcoinExchange::nb_to_date_string(long nb, bool french_fornat/* = false*/) {
    int year = nb / 10000;
    int month = (nb / 100) % 100;
    int day = nb % 100;
    std::stringstream ss;
    if (french_fornat)
        ss << std::setfill('0') << std::setw(2) << day << " / " << std::setw(2) << month << " / " << year;
    else
        ss << std::setw(4) << year << "-" << std::setfill('0') << std::setw(2) << month << "-" << std::setw(2) << day;
    return ss.str();
}

long BitcoinExchange::date_string_to_nb(std::string const & date) {
    long nb = 0;
    for (size_t i = 0; i < date.length(); i++) {
        if (date[i] == '-')
            continue;
        nb *= 10;
        nb += date[i] - '0';
    }
    return nb;
}


BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) { (void)src;}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
    (void)rhs;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::string const & filename) {
    _first_date = 0;
    _last_date = 0;
    std::ifstream ifs;

    ifs.open(filename);
    if (!ifs.is_open()) {
        std::cout << "Le fichier data.csv n'a pas pu etre ouvert" << std::endl;
        perror(filename.c_str());
    }
    
    std::string buf;
    while (std::getline(ifs, buf))
        if (buf.find_first_not_of("0123456789-,.") == std::string::npos)
            this->add_price(buf);
}

void BitcoinExchange::add_price(std::string const & data) {
    size_t comma_i = data.find(',');
    if (comma_i == std::string::npos)
        throw std::runtime_error("No comma separator found in the line");
    
    std::string date_s = data.substr(0, comma_i);
    long nb = BitcoinExchange::date_string_to_nb(date_s);
    
    std::string price = data.substr(comma_i + 1, std::string::npos);
    _price_history[nb] = atof(price.c_str());
    
    if (_first_date == 0)
        _first_date = nb;
    _last_date = nb;
    
    // std::cout << date_s << std::endl;
    // std::cout << nb << std::endl << std::endl;
}

BitcoinExchange::map_type const & BitcoinExchange::get_price_history(void) const {
    return this->_price_history;
}

long BitcoinExchange::get_first_date(void) const {
    return this->_first_date;
}

long BitcoinExchange::get_last_date(void) const {
    return this->_last_date;
}

std::ostream & operator<<(std::ostream & o, BitcoinExchange const & rhs) {
    BitcoinExchange::map_type price_history = rhs.get_price_history();

    BitcoinExchange::map_type::const_iterator it;
    size_t i = 0;
    for (it = price_history.cbegin(); it != price_history.cend(); ++it) {
        //o << std::setw(20) << it->first << std::endl;
        o << std::setw(20)  << std::right << BitcoinExchange::nb_to_date_string(it->first);
        o << " : " << it->second << std::endl;
        if (i == 9999999)
            break;
        ++i;
    }
    return o;
}