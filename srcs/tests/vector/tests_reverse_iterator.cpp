/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_iterator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:16:14 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/09 15:49:21y dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	tests_relational_r_operators()
{
	std::cout << BCYAN << "### relational operators ###" << END << std::endl << std::endl;
	prefix::vector<int> v;
	prefix::vector<int>::reverse_iterator a, c;
	prefix::vector<int>::reverse_iterator b(a);

	v.push_back(6);
	v.push_back(7);

	a = v.rbegin();
	b = a;
	c = b + 1;
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

void	tests_arithmetic_r_operators()
{
	std::cout << BCYAN << "### arithmetic operators ###" << END << std::endl << std::endl;
	prefix::vector<int> v;
	prefix::vector<int>::reverse_iterator it; // default constructible

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	printVec_rev(v);
	it = v.rbegin();

	std::cout << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*it++\t\t=\t" << *it++ << std::endl;
	std::cout << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*++it\t\t=\t" << *++it << std::endl;

	std::cout << std::endl << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*it--\t\t=\t" << *it-- << std::endl;
	std::cout << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*--it\t\t=\t" << *--it << std::endl;

	it = v.rbegin() + 2;

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
	it = v.rbegin();
	for (size_t i = 0; i < v.size(); i++)
		std::cout << "it[i]\t=\t" << it[i] << std::endl;
	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}

void	tests_constructors_r_iterator()
{
	std::cout << BCYAN << "### constructor ###" << END << std::endl << std::endl;
	prefix::vector<int> v;

	v.push_back(500);
	v.push_back(600);
	v.push_back(700);
	v.push_back(800);

	printVec(v);

	typedef prefix::vector<int>::iterator iter_type;

	iter_type from(v.begin());
	iter_type until(v.end());
	prefix::reverse_iterator<iter_type> rev_until(from);
	prefix::reverse_iterator<iter_type> rev_from(until);

	std::cout << BGREEN << "vec_rev_it = [ ";
	while (rev_from != rev_until)
		std::cout << *rev_from++ << " ";
	std::cout << "]" << std::endl << std::endl << END;

	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}

void	tests_operator_r_iterator()
{
	tests_arithmetic_r_operators();
	tests_relational_r_operators();
}

void	tests_r_iterator()
{
	std::cout << BYELLOW << "*** TEST REV ITERATOR ***" << END << std::endl << std::endl;
	tests_constructors_r_iterator();
	tests_operator_r_iterator();
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}

