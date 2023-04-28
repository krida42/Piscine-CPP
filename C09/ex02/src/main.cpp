#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::srand(std::time(0));

	std::vector<uint> unsorted;
	for (size_t i = 0; i < 5; i++)
	{
		int random_number = (std::rand() % 10) + 1; // Génère un nombre aléatoire entre 1 et 100
		unsorted.push_back(random_number);
	}
	
	std::cout << "is sorted ? " << PmergeMe::is_sorted(unsorted) << " : ";
	for (size_t i = 0; i < unsorted.size(); i++){
		std::cout << unsorted[i] << " ";
	}

	std::cout << std::endl;

	std::vector<uint> sorted = PmergeMe::insert_sort(unsorted);
	std::cout << "is sorted ? " << PmergeMe::is_sorted(sorted) << " : ";
	for(size_t i = 0; i < sorted.size(); i++) {
		std::cout << sorted[i] << " ";
	}
	std::cout << std::endl;
	

	return 0;
}
