/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bst.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:45:28 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/29 16:02:28 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <functional>
#include <iostream>
#include <string>
#include "../includes/utils/bst.hpp"

int main(void)
{
	typedef int                    Key;
	typedef std::pair<int, std::string>        pair_type;
	typedef std::less< Key >    compare;

	pair_type    pair = std::make_pair(1, "a");
	BST<pair_type, compare> *first_bst = new BST<pair_type, compare>(pair);
	BST<pair_type, compare> *second_bst, *third_bst;

	std::cout << "insert 1" << std::endl << std::endl;
	print_bst(first_bst);

	std::cout << std::endl << "insert 2, 0, 4, 10"
		<< std::endl << std::endl;
	first_bst->insert(std::make_pair(2, "b"));
	first_bst->insert(std::make_pair(0, "c"));
	first_bst->insert(std::make_pair(4, "d"));
	first_bst->insert(std::make_pair(10, "c"));
	//std::cout << "search f bst data = "
		//<< first_bst->search(std::less<43>) << std::endl;
	print_bst(first_bst);
	second_bst = first_bst->_left_child;
	std::cout << std::endl << "second = left_child"
		<< std::endl << std::endl;
	print_bst(second_bst);

	std::cout << std::endl << "third = first->right_child"
		<< std::endl << std::endl;

	third_bst = first_bst->_right_child;
	print_bst(third_bst);

	std::cout << std::endl << "first"
		<< std::endl << std::endl;
	print_bst(first_bst);
}
