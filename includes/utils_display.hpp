/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:41:37 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/23 14:12:13 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "vector.hpp"

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
	std::cout << BGREEN << "x =  " << x << std::endl;
	printStack(stack);
	stack.push(x);
}

#endif
