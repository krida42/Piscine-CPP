# include "Array.hpp"


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
