#include "easyfind.hpp"
#include <iostream>
#include <list>

int main()
{
	int my_ints[] = {3, 7, 5, 1, 49};

	//INITIALIZE by giving first pointer and last pointer
	std::list<int> v(my_ints, my_ints + sizeof(my_ints) / sizeof(int));

	// std::vector<int> v;
	// v.push_back(3);
	// v.push_back(7);
	// v.push_back(5);
	// v.push_back(1);
	// v.push_back(49);

	try
	{
		std::cout << *(easyfind(v, 49)) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << *(easyfind(v, 48));
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
