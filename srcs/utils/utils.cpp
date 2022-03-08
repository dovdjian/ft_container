#include "vector.hpp"

template <typename T>
void	printVector_index(const ft::vector<T> & v)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << BBLUE << "vector[i]\t=\t" << vector[i]
			<< END << std::endl;
	}
}

template <typename T>
void	printVector_it(const ft::vector<T> & v)
{
	std::vector<T, Alloc>::iterator it;

	for (it != v.begin() ; it != v.end() ; ++it)
	{
		std::cout << BRED << "*it\t=\t" << *it
			<< END << std::endl;
	}
}

template <typename T>
void	printVectorStl_index(const std::vector<T> & v)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << BBLUE << "vector[i]\t=\t" << vector[i]
			<< END << std::endl;
	}
}

template <typename T>
void	printVectorStl_it(const std::vector<T> & v)
{
	std::vector<T, Alloc>::iterator it;

	for (it != v.begin() ; it != v.end() ; ++it)
	{
		std::cout << BRED << "*it\t=\t" << *it
			<< END << std::endl;
	}
}
