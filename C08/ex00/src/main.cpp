#include <vector>
#include <iostream>
#include "easyfind.hpp"


int main(int argc, char const *argv[])
{
	(void) argc;
	(void)argv;

	std::vector<int> v;
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.push_back(44);
	v.push_back(55);
	v.push_back(66);
	v.push_back(77);
	v.push_back(88);
	v.push_back(99);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;

	std::vector<int>::iterator it = easyfind(v, 45);
	if (it != v.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;

	std::cout << (*easyfind(v, 58)) << std::endl;
	std::cout << (*easyfind(v, 11)) << std::endl;

	return 0;
}
