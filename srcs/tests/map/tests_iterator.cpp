/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_iterator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:52:05 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/05 18:54:38 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/utils/tests.hpp"

/* void	tests_relational_operators_map()
{
	std::cout << BCYAN << "### relational operators ###" << END << std::endl << std::endl;
	prefix::map<char, int> v;
	prefix::map<char, int>::iterator a, d;
	prefix::map<char, int>::iterator b(a); // copy constr
	prefix::map<char, int>::iterator c = a; // copy assign

	v.push_back(6);
	v.push_back(7);

	a = v.begin();
	b = a;
	c = b + 1;
	d = c - 1;
	std::cout << "*a\t=\t" << *a << std::endl;
	std::cout << "*b\t=\t" << *b << std::endl;
	std::cout << "*c\t=\t" << *c << std::endl << std::endl;
	if (b != c)
		std::cout << "b != c" << std::endl;
	if (a == b)
		std::cout << "a == b" << std::endl;
	if (b < c)
		std::cout << "b < c" << std::endl;
	if (c > b)
		std::cout << "c > b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (c >= b)
		std::cout << "c >= b" << std::endl;
	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}

void	tests_arithmetic_operators_map()
{
	std::cout << BCYAN << "### arithmetic operators ###" << END << std::endl << std::endl;
	prefix::map<char, int> v;
	prefix::map<char, int>::iterator it; // default constructible

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	printVec(v);
	it = v.begin();
	std::cout << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*it++\t\t=\t" << *it++ << std::endl;
	std::cout << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*++it\t\t=\t" << *++it << std::endl;

	std::cout << std::endl << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*it--\t\t=\t" << *it-- << std::endl;
	std::cout << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*--it\t\t=\t" << *--it << std::endl;

	it = v.begin() + 2;

	std::cout << std::endl << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*(it + 1)\t=\t" << *(it + 1) << std::endl;
	std::cout << "*(1 + it)\t=\t" << *(1 + it) << std::endl;
	std::cout << "*(it - 1)\t=\t" << *(it - 1) << std::endl;

	std::cout << std::endl << "*it\t\t=\t" << *it << std::endl;
	it -= 2;
	std::cout << "it -= 2\t\t=\t" << *it << std::endl;
	it += 2;
	std::cout << "it += 2\t\t=\t" << *it << std::endl;

	std::cout << std::endl << "*it\t\t=\t" << *it << std::endl;
	--it; // pre decr
	std::cout << "--it\t\t=\t" << *it << std::endl;
	++it; // pre incr
	std::cout << "++it\t\t=\t" << *it << std::endl;
	it--; // post decr
	std::cout << "it--\t\t=\t" << *it << std::endl;
	it++; // post incr
	std::cout << "it++\t\t=\t" << *it << std::endl << std::endl;
	it = v.begin();
	for (size_t i = 0; i < v.size(); i++)
		std::cout << "it[i]\t=\t" << it[i] << std::endl;
	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}
*/
void	tests_constructors_iterator_map()
{
	std::cout << BCYAN << "### constructor ###" << END << std::endl << std::endl;
	//prefix::map<char, int> m;
	std::map<char, int> m;
	//prefix::map<char, int>::iterator it; // default constructible
	//prefix::map<char, int>::iterator copy_constr(it); // copy constructible

	//m['a'] = 10;
	//m['b'] = 20;
	//m['c'] = 30;
	//m['d'] = 40;

	m.insert(std::pair<char, int>('a', 10));
	m.insert(std::pair<char, int>('b', 20));
	m.insert(std::pair<char, int>('c', 30));
	m.insert(std::pair<char, int>('d', 40));
	//printMap(m);
	/* it = m.begin();
	copy_constr = it;

	std::cout << std::endl << END << "it : " << it->first << " => " << it->second << std::endl;
	std::cout << "copy_constr : " << copy_constr->first << " => " << copy_constr->second << std::endl;

	prefix::map<char, int>::const_iterator it_c; // default constructible

	it_c = it;
	if (it_c != it)
		std::cout << "false" << std::endl;
	std::cout << std::endl << END << "it_c : " << it_c->first << " => " << it_c->second << std::endl; */
	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}

void	tests_operator_iterator_map()
{
	//tests_arithmetic_operators_map();
	//tests_relational_operators_map();
}

void	tests_iterator_map()
{
	std::cout << BYELLOW << "*** TEST ITERATOR ***" << END << std::endl << std::endl;
	tests_constructors_iterator_map();
	//tests_operator_iterator_map();
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}
