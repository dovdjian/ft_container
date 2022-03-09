/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:44:37 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/09 14:47:37 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

template <typename T>
void	printVector_index(const ft::vector<T> & v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << BBLUE << "v[i]\t=\t" << v[i]
			<< END << std::endl;
	}
}

template <typename T, typename Alloc>
void	printVector_it(const ft::vector<T> & v)
{
	ft::vector<T, Alloc>::iterator it;

	for (it != v.begin() ; it != v.end() ; ++it)
	{
		std::cout << BRED << "*it\t=\t" << *it
			<< END << std::endl;
	}
}

template <typename T>
void	printVectorStl_index(const std::vector<T> & v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << BBLUE << "v[i]\t=\t" << v[i]
			<< END << std::endl;
	}
}

template <typename T, typename Alloc>
void	printVectorStl_it(const std::vector<T> & v)
{
	std::vector<T, Alloc>::iterator it;

	for (it != v.begin() ; it != v.end() ; ++it)
	{
		std::cout << BRED << "*it\t=\t" << *it
			<< END << std::endl;
	}
}
