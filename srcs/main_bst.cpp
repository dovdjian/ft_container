/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bst.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:45:28 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/24 17:38:20 by dodjian          ###   ########.fr       */
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
	typedef std::pair<int, int>        pair_type;
	typedef std::less< Key >    compare;

	pair_type    pair = std::make_pair(1, 69);
	BST<pair_type, compare> *first = new BST<pair_type, compare>(pair);
	BST<pair_type, compare> *second;

	std::cout << first->_elem.first << std::endl;
	std::cout << first->_elem.second << std::endl;

	first->insert(std::make_pair(2, 18));
	first->insert(std::make_pair(0, -42));

	second = first->_left_child;

	std::cout << second->_elem.first << std::endl;
	std::cout << second->_elem.second << std::endl;

	first = first->_right_child;

	std::cout << first->_elem.first << std::endl;
	std::cout << first->_elem.second << std::endl;
}
