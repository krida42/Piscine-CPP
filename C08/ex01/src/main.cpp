#include "Span.hpp"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	std::vector<int> vec;

	vec.push_back(55);
	vec.push_back(22);
	vec.push_back(44);
	vec.push_back(66);
	vec.push_back(77);
	vec.push_back(33);
	vec.push_back(88);
	vec.push_back(99);
	vec.push_back(11);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";

	std::cout << "\n- - - - -\n";

	sort(vec.begin(), vec.end());
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	
	std::cout << std::endl;


	std::cout << "+ 1: " << *(vec.begin() + 1) << std::endl;
	std::cout << "+ 3: " << *(vec.begin() + 3) << std::endl;
	std::cout << "- 1: " << *(vec.end() - 1) << std::endl;

	std::cout << "begin : " << *(vec.begin()) << std::endl;
	std::cout << "end : " << *(vec.end()) << std::endl << std::endl << std::endl;

	std::cout << "- - - - - My tests- - - - - -" << std::endl;
	
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try {
		sp.addNumber(1);
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	

	std::cout << "\nshortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	std::cout << "\n- - - - - -" << std::endl;

	Span sp2 = Span(20);
	sp2.addNumber(4242);
	sp2.addIterator(vec.begin(), vec.end());
	sp2.addIterator(vec.begin(), vec.end());
	
	try {
		sp2.addIterator(vec.begin(), vec.end());
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << sp2.toString() << std::endl;


	return 0;
}
