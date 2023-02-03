#include <iostream>
# include <vector>
#include "MutantStack.hpp"

#if 0
int main(void)
{


	MutantStack<int> stouck;




	stouck.push(111);
	stouck.push(22);
	stouck.push(33);
	stouck.push(44);
	stouck.push(55);
	stouck.push(66);
	stouck.push(77);
	stouck.push(88);
	stouck.push(999);

	MutantStack<int> stick(stouck);

	for (MutantStack<int>::iterator it = stouck.begin(); it != stouck.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
	

	for (MutantStack<int>::iterator it1 = stick.begin(); it1 != stick.end(); ++it1)
		std::cout << *it1 << " ";

	return 0;
}
#else
int test1()
{
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(17);
	std::cout << *(vec.end() - 1) << std::endl;
	vec.pop_back();
	std::cout << vec.size() << std::endl;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	//[...]
	vec.push_back(0);
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::vector<int> s(vec);
	return 0;
}
int test2()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

int main(void) {	
	test1();
	std::cout << std::endl << std::endl;;
	test2();
}

#endif