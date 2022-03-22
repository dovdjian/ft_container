/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_methods.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:27:50 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/22 18:28:33 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stack

#include "tests.hpp"

void	tests_methods()
{
	std::cout << BYELLOW << "*** TEST METHODS ***" << END << std::endl << std::endl;
		std::endl << std::endl;
	prefix::stack<int> v;

	printStack(v);
	std::cout << "v.empty()\t=\t" << v.empty() << std::endl;

	v.push(2);
	v.push(3);
	v.push(5);
	v.push(8);

	printStack(v);
	std::cout << "POP" << std::endl;
	v.pop();
	printStack(v);
	std::cout << "v.empty()\t=\t" << v.empty() << std::endl;
	std::cout << "v.size()\t=\t" << v.size() << std::endl;

	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}

void	tests_constructor()
{
	std::cout << BYELLOW << "*** TEST CONSTRUCTORS ***" << END << std::endl << std::endl;
	prefix::stack<int> s;                                // empty stack of ints
	prefix::vector<int> v;                                // empty vec of ints
	printVec(v);
	printStack(first);
	for (int i = 0; i < 10; i++)
		s.push(i);
	for (i = 0; i < 10; i++)
		first.push_back(i * 10);
	prefix::stack<int> s2;                                // empty stack of ints
	std::cout << "v" << std::endl;
	printVec(v);

	std::cout << "s" << std::endl;
	printStack(s);
	std::cout << "s2" << std::endl;
	printStack(s2);
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}
