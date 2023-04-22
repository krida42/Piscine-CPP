#include "BitcoinExchange.hpp"

int main(void) {
	
	BitcoinExchange btc_exch("./data.csv");
	std::cout << btc_exch << std::endl;
	return 0;
}