/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:41:37 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/25 11:36:34 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_DISPLAY_HPP
# define UTILS_DISPLAY_HPP

#include "stl.hpp"

template <typename T>
void printVec(T & vec)
{
	typename T::iterator it;
	typename T::iterator end;

	std::cout << BGREEN << "vec_it     = [ ";
	end = vec.end();
	for (it = vec.begin() ; it != end ; it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl << std::endl << END;
}

template <typename T>
void printVec_index(T & vec)
{
	std::cout << BGREEN << "vec_index  = [ ";
	for (size_t i = 0; i < vec.size() ; i++)
		std::cout << vec[i] << " ";
	std::cout << "]" << std::endl << std::endl << END;
}

template <typename T>
void printVec_rev(T & vec)
{
	typename T::reverse_iterator it;
	typename T::reverse_iterator end;

	std::cout << BGREEN << "vec_rev_it = [ ";
	end = vec.rend();
	for (it = vec.rbegin() ; it != end ; it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl << std::endl << END;
}

template <typename T>
void printStack(T & stack)
{
	if (stack.empty())
		return ;
	int x = stack.top();
	stack.pop();
	std::cout << BGREEN << "stack content =  " << x << std::endl;
	printStack(stack);
	stack.push(x);
}

template <typename T>
void printMap(T & map)
{
	typename T::iterator it;
	typename T::iterator end;

	std::cout << BGREEN << std::endl << "map : " << std::endl;
	end = map.end();
	std::cout << "before for loop printmap" << std::endl;
	for (it = map.begin() ; it != end ; it++)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "after for loop printmap" << std::endl;
	std::cout << std::endl << END;
}


template <typename BST>
void print_bst(const std::string & prefix, const BST* node,
	bool isLeft)
{
	if (node)
	{
		std::cout << prefix;
		std::cout << (isLeft ? "├──" : "└──" );
		// print the value of the node
		std::cout << node->_data.first << std::endl;
		// enter the next tree level - left and right branch
		print_bst(prefix + (isLeft ? "│   " : "    "), node->_left_child, true);
		print_bst(prefix + (isLeft ? "│   " : "    "), node->_right_child, false);
	}
}

template <typename BST>
void print_bst(const BST* node)
{
	print_bst("", node, false);
}

#endif
