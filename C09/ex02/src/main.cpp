#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cerrno>

bool is_positive_integer(const char *str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isdigit(str[i]))
            return false;
    }

    errno = 0;
    unsigned long long number = strtoul(str, NULL, 10);
    if (errno == ERANGE || number > UINT_MAX)
        return false;

    return true;
}

std::vector<unsigned int> convert_argv_to_uint_vector(int argc, char **argv) {
    std::vector<unsigned int> uint_vector;

    for (int i = 1; i < argc; ++i) {
        if (is_positive_integer(argv[i])) {
            unsigned int number = static_cast<unsigned int>(strtoul(argv[i], NULL, 10));
            uint_vector.push_back(number);
        } else {
            throw PmergeMe::InvalidCharacterException();
        }
    }

    return uint_vector;
}


unsigned long long get_time(void) {
	timeval	time;
	gettimeofday(&time, NULL);
	return time.tv_sec * 1000000 + time.tv_usec;
}



void display_time_to_process(size_t nb_el, unsigned long long vec_usec, unsigned long long deq_usec) {
	unsigned long long min_time = std::min(vec_usec, deq_usec);

	long double min_time_msec = min_time / 1000.0;
	long double min_time_sec = min_time_msec / 1000.0;

	long double vec_msec = vec_usec / 1000.0;
	long double vec_sec = vec_msec / 1000.0;

	long double deq_msec = deq_usec / 1000.0;
	long double deq_sec = deq_msec / 1000.0;

	std::stringstream vec_ss;
	std::stringstream deq_ss;
	vec_ss << "Time to process a range of\t" << nb_el << " elements with std::vector<uint> : ";
	deq_ss << "Time to process a range of\t" << nb_el << " elements with std::deque<uint>  : ";

	if (min_time_sec > 0.09) {
		vec_ss << std::fixed << std::setprecision(3) << vec_sec << " s";
		deq_ss << std::fixed << std::setprecision(3) << deq_sec << " s";
	} else if (min_time_msec > 0.09) {
		vec_ss << vec_msec << " ms";
		deq_ss << deq_msec << " ms";
	} else {
		vec_ss << vec_usec << " us";
		deq_ss << deq_usec << " us";
	}

	std::cout << vec_ss.str() << std::endl;
	std::cout << deq_ss.str() << std::endl;
}



int main(int argc, char **argv)
{
	std::vector<uint> unsorted;

	try {
		unsorted = convert_argv_to_uint_vector(argc, argv);
	}
	catch(const PmergeMe::InvalidCharacterException & e) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	
	std::deque<uint> unsorted_deque(unsorted.begin(), unsorted.end());


	
	// std::cout << "is input sorted ? " << PmergeMe::is_sorted(unsorted) << std::endl;
	std::cout << "Before:\t";
	for (size_t i = 0; i < unsorted.size(); i++) {
		if (i >= 11) {
			std::cout << "[...]";
			break;
		}
		std::cout << unsorted[i] << " ";
	}
	std::cout << std::endl;


	// VECTOR SORT---------------------------------------------------------------------------------------------

	unsigned long long start = get_time();
	std::vector<uint> sorted = PmergeMe::merge_insert_sort(unsorted);
	unsigned long long vec_usec = get_time() - start;
	// std::cout << "is vector sorted ? " << PmergeMe::is_sorted(sorted) << std::endl;



	// DEQUE SORT---------------------------------------------------------------------------------------------

	start = get_time();
	std::deque<uint> sorted_deque = PmergeMe::merge_insert_sort(unsorted_deque);
	unsigned long long deq_usec = get_time() - start;
	// std::cout << "is deque sorted ? " << PmergeMe::is_sorted(sorted_deque) << std::endl;

	std::cout << "After:\t";
	for (size_t i = 0; i < sorted.size(); i++) {
		if (i >= 11) {
			std::cout << "[...]";
			break;
		}
		std::cout << sorted[i] << " ";
	}
	std::cout << std::endl;

	display_time_to_process(unsorted.size(), vec_usec, deq_usec);


	return 0;
}
