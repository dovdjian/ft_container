/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:24:40 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/24 16:31:21 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/utils/tests.hpp"

void	tests_pair()
{
	std::cout << BYELLOW << "*** TEST PAIR ***" << END << std::endl << std::endl;
	prefix::pair<std::string, double> product1;                     // default constructor
	prefix::pair<std::string, double> product2("tomatoes", 2.30);   // value init
	prefix::pair<std::string, double> product3(product2);          // copy constructor

	product1 = prefix::make_pair(std::string("pineapple"), 0.99);   // using make_pair (move)
	product2.first = "shoes";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
	std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
	std::cout << "The price of " << product3.first << " is $" << product3.second << std::endl;

	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}

void	tests_bst()
{
	pointer	root = NULL;
	root = new BST[1];
	prefix::pair<std::string, double> product2("tomatoes", 2.30);   // value init

	root->insert(pair);
	display_bst(root);
	//delete root;
}

void	tests_map()
{
	//tests_pair();
	tests_bst();
}
