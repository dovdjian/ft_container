/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_methods.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:27:50 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/23 15:05:11 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tests.hpp"

void	tests_methods_stack()
{
	std::cout << BYELLOW << "*** TEST METHODS ***" << END << std::endl << std::endl;
	prefix::stack<int> s;

	printStack(s);
	std::cout << "s.empty()\t=\t" << s.empty() << std::endl;

	s.push(2);
	s.push(3);
	s.push(5);
	s.push(8);

	printStack(s);
	std::cout << "POP" << std::endl;
	s.pop();
	printStack(s);
	std::cout << "s.empty()\t=\t" << s.empty() << std::endl;
	std::cout << "s.size()\t=\t" << s.size() << std::endl;

	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}

void	tests_constructor_stack()
{
	std::cout << BYELLOW << "*** TEST CONSTRUCTORS ***" << END << std::endl << std::endl;
	prefix::stack<int> s;                                // empty stack of ints
	prefix::vector<int> v;                                // empty vec of ints
	printVec(v);
	printStack(s);
	for (int i = 0; i < 10; i++)
		s.push(i);
	for (int i = 0; i < 10; i++)
		v.push_back(i * 10);
	prefix::stack<int> s2;                                // empty stack of ints
	std::cout << "v" << std::endl;
	printVec(v);

	std::cout << "s" << std::endl;
	printStack(s);
	std::cout << "s2" << std::endl;
	printStack(s2);
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}
