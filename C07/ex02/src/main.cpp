# include "Array.hpp"
#include <iostream>
#include <cstdlib>


int	main(void)
{

	Array<int> arr00;
	Array<int> arr(4);

	for (size_t i = 0; i < arr.size(); i++)
		arr[i] = 11;

	Array<int> arr_cpy(arr);

	for (size_t i = 0; i < arr_cpy.size(); i++)
		arr_cpy[i] = 22;

	Array<int> arr_eq(2);
	arr_eq = arr;

	for (size_t i = 0; i < arr_eq.size(); i++)
		arr_eq[i] = 33;

	//std::cout << "arr[i] = " << arr[0] << std::endl;
	std::cout << "arr = " << arr << std::endl;
	std::cout << "arr_cpy = " << arr_cpy << std::endl;
	std::cout << "arr_eq = " << arr_eq << std::endl;
	return (0);
}

/*
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/
