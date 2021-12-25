/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:28:18 by dodjian           #+#    #+#             */
/*   Updated: 2021/12/25 01:39:38 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

int main(void)
{
	std::cout << GREEN << "std::vector |" << RED << " ft::vector" << std::endl << std::endl;
	std::vector<int> std_vector;
	ft::vector<int> my_vector;
	for (int i = 0; i < 5; i++)
		std_vector.push_back(i);
	//std::cout << "std::vector contains: ";
	//for (std::vector<int>::iterator it = std_vector.begin() ; it != std_vector.end(); ++it)
		//std::cout << GREEN << *it << ' ';
	//std::cout << std::endl << END;

	/* ft::vector<int> my_vector;
	for (int i = 0; i < 5; i++)
		my_vector.push_back(i);
	std::cout << "my_vector contains:";
	for (iterator it = my_vector.begin() ; it != my_vector.end(); ++it)
		std::cout << RED << *it << ' ';
	std::cout << std::endl << END; */


	std::cout << GREEN << "std::vector::empty = " << std_vector.empty() << std::endl;
	std::cout << RED << "ft::vector::empty = " << my_vector.empty() << std::endl << END;
	return (0);
}
