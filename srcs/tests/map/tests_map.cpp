/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:24:40 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/28 11:40:18 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/utils/tests.hpp"

void	tests_pair()
{
	std::cout << BYELLOW << "*** TEST PAIR ***" << END << std::endl << std::endl;
	prefix::pair<std::string, double> product1;						// default constructor
	prefix::pair<std::string, double> product2("tomatoes", 2.30);	// value init
	prefix::pair<std::string, double> product3(product2);			// copy constructor

	product1 = prefix::make_pair(std::string("pineapple"), 0.99);
	product2.first = "shoes";
	product2.second = 39.90;

	std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
	std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
	std::cout << "The price of " << product3.first << " is $" << product3.second << std::endl;
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}

bool	isFt(ft::map<char, int> x)
{
	static_cast<void>(x);
	return true;
}

bool	isFt(std::map<char, int> x)
{
	static_cast<void>(x);
	return false;
}

void	tests_map()
{
	clock_t		t;
	t = clock();

	tests_pair();
	tests_iterator_map();
	tests_methods_map();

	t = clock() - t;
	prefix::map<char, int> new_map;
	std::cerr << "time for "
		<< (isFt(new_map) ? "ft::" : "std::")
		<< "map: [" << BBLUE
		<< (static_cast<double>(t) / CLOCKS_PER_SEC)
		<< END << "]" << std::endl;
}
