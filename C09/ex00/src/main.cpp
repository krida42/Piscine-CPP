#include "BitcoinExchange.hpp"
#include <limits>
#include <cstdio>
#include <cstdlib>

int is_err_date(std::string const & dateP) {
	std::string date = dateP.substr(0, dateP.find_last_not_of(' '));

	int y = 0;
	int m = 0;
	int d = 0;
	int count = 0;
	if((count = sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d)) != 3 && printf("Error: bad date\n")) {
		std::cout << count << std::endl;
		return 1;
	}
	if (m > 12 && printf("Error: bad month\n"))
		return 1;
	if (d > 31 && printf("Error: bad day\n"))
		return 1;
	return 0;
}

std::string get_err_money(std::string const & moneyP) {
	size_t begin = moneyP.find_first_not_of(' ');
	if (begin == std::string::npos)
		return std::string("Error: no number");
	std::string money = moneyP.substr(begin, moneyP.find_last_not_of(' '));

	if (money.length() > 12)
		return std::string("Error: too many digits/character");

	double mon_d = 0;
	if (sscanf(money.c_str(), "%lf", &mon_d) != 1)
		return std::string("Error: bad number");
	if (mon_d < 0)
		return std::string("Error: not a positive number");
	if (mon_d > std::numeric_limits<int>::max() || mon_d > 1000)
		return std::string("Error: too large a number");

	return std::string("OK");
}

int print_err(std::string const & line) {

	if (line.find_first_not_of("0123456789-|. ") != std::string::npos) {
		std::cout << "Error: bad input => " << line << std::endl;
		return 1;
	}

	size_t sep = line.find('|');
	if (sep == std::string::npos) {
		std::cout << "Error: bad input => " << line << std::endl;
		return 1;
	}
	std::string date = line.substr(0, sep);
	if (is_err_date(date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return 1;
	}
	std::string money_error = get_err_money(line.substr(sep + 1));
	if (money_error != "OK") {
		std::cout << money_error << std::endl;
		return 1;
	}
	return 0;
}

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Input file is missing !" << std::endl;
		return 1;
	}
	
	BitcoinExchange btc_exch("./data.csv");
	//std::cout << btc_exch << std::endl;

	std::ifstream ifs;
	ifs.open(argv[1]);
	if (!ifs.is_open()) {
		std::cout << "Cannot open input file" << std::endl;
		perror(argv[1]);
		return 1;
	}

	std::string line;
	while (std::getline(ifs, line)) {
		if (print_err(line))
			continue;
		std::string date = line.substr(0, line.find('|'));
		date = date.substr(0, date.find_last_not_of(' ') + 1);
		std::string money = line.substr(line.find('|') + 1);
		money = money.substr(money.find_first_not_of(' '));
		money = money.substr(0, line.find_last_not_of(' ') + 1);

	
		long date_nb = BitcoinExchange::date_string_to_nb(date);
		double money_nb = atof(money.c_str());

		long date_nb_tmp = date_nb;

		long last_date = btc_exch.get_last_date();
		if (date_nb < btc_exch.get_first_date()) {
			std::cout << BitcoinExchange::nb_to_date_string(date_nb) << " => " << money_nb << " = " << '0' <<  std::endl;
		} else if (date_nb > last_date) {
			std::cout << BitcoinExchange::nb_to_date_string(date_nb) << " => " << money_nb << " = " << btc_exch.get_price_history().at(last_date) <<  std::endl;
		} else {
			while (btc_exch.get_price_history().find(date_nb_tmp) == btc_exch.get_price_history().end())
				date_nb_tmp--;
			std::cout << BitcoinExchange::nb_to_date_string(date_nb) << " => " << money_nb << " = " << btc_exch.get_price_history().at(date_nb_tmp) * money_nb <<  std::endl;
		}


	}

	return 0;
}