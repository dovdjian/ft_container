/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_iterator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:52:05 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/06 15:46:41 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/utils/tests.hpp"

void	tests_relational_operators_map()
{
	std::cout << BCYAN << "### relational operators ###" << END << std::endl << std::endl;
	std::map<char, int> m;
	std::map<char, int>::iterator it1;
	std::map<char, int>::iterator it2(it1); // copy constr
	std::map<char, int>::iterator it3 = it1; // copy assign

	m['a'] = 10;
	m['b'] = 20;
	m['c'] = 30;
	m['d'] = 40;

	it1 = m.begin();
	it2 = it1;
	it3 = it2;
	it3++;

	std::cout << "it1 : " << it1->first << " => " << it1->second << std::endl;
	std::cout << "it2 : " << it2->first << " => " << it2->second << std::endl;
	std::cout << "it3 : " << it3->first << " => " << it3->second << std::endl << std::endl;
	if (it2 != it3)
		std::cout << "it2 != it3" << std::endl;
	if (it1 == it2)
		std::cout << "it1 == it2" << std::endl;
	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}

void	tests_arithmetic_operators_map()
{
	std::cout << BCYAN << "### arithmetic operators ###" << END << std::endl << std::endl;
	std::map<char, int> m;
	std::map<char, int>::iterator it; // default constructible

	m.insert(std::pair<char, int>('w', 600));
	m.insert(std::pair<char, int>('x', 700));
	m.insert(std::pair<char, int>('y', 800));
	m.insert(std::pair<char, int>('z', 900));

	printMap(m);
	it = m.begin();
	it++;
	it++;

	std::cout << "it\t=\t" << it->first << " => " << it->second << std::endl;
	--it; // pre decr
	std::cout << "--it\t=\t" << it->first << " => " << it->second << std::endl;
	++it; // pre incr
	std::cout << "++it\t=\t" << it->first << " => " << it->second  << std::endl;
	it--; // post decr
	std::cout << "it--\t=\t" << it->first << " => " << it->second  << std::endl;
	it++; // post incr
	std::cout << "it++\t=\t" << it->first << " => " << it->second  << std::endl << std::endl;
	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}

void	tests_constructors_iterator_map()
{
	std::cout << BCYAN << "### constructor ###" << END << std::endl << std::endl;
	//prefix::map<char, int> m;
	std::map<char, int> m;
	std::map<char, int>::iterator it; // default constructible
	std::map<char, int>::iterator copy_constr(it); // copy constructible

	m.insert(std::pair<char, int>('a', 10));
	m.insert(std::pair<char, int>('b', 20));
	m.insert(std::pair<char, int>('c', 30));
	m.insert(std::pair<char, int>('d', 40));
	printMap(m);
	it = m.begin();
	copy_constr = it;

	std::cout << "it : " << it->first << " => " << it->second << std::endl;
	std::cout << "copy_constr : " << copy_constr->first << " => " << copy_constr->second << std::endl;

	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}

void	tests_operator_iterator_map()
{
	tests_arithmetic_operators_map();
	tests_relational_operators_map();
}

void	tests_iterator_map()
{
	std::cout << BYELLOW << "*** TEST ITERATOR ***" << END << std::endl << std::endl;
	tests_constructors_iterator_map();
	tests_operator_iterator_map();
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}
