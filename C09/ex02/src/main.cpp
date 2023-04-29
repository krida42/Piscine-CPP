#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <sys/time.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	timeval	time;

	gettimeofday(&time, NULL);
	// std::srand(std::time(0));
	std::srand(time.tv_usec);

	std::vector<uint> unsorted;
	for (size_t i = 0; i < 200; i++)
	{
		int random_number = (std::rand() % 500) + 1; // Génère un nombre aléatoire entre 1 et 100
		unsorted.push_back(random_number);
	}
	
	// unsorted.push_back(10);
	// unsorted.push_back(6);
	// unsorted.push_back(8);
	// unsorted.push_back(2);
	// unsorted.push_back(4);
	// unsorted.push_back(1);
	std::cout << "is sorted ? " << PmergeMe::is_sorted(unsorted) << " : " << std::endl;
	for (size_t i = 0; i < unsorted.size(); i++){
		std::cout << unsorted[i] << " ";
	}

	std::cout << std::endl;

	std::vector<uint> sorted = PmergeMe::merge_insert_sort(unsorted);
	std::cout << "is sorted ? " << PmergeMe::is_sorted(sorted) << " : " << std::endl;
	for(size_t i = 0; i < sorted.size(); i++) {
		std::cout << sorted[i] << " ";
	}
	std::cout << std::endl;
	

	return 0;
}
