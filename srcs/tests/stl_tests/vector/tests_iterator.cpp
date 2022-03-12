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

#include "vector.hpp"
#include "utils.hpp"

void	tests_relational_operators()
{
	std::cout << BCYAN << "### relational operators ###" << END << std::endl << std::endl;
	std::vector<int> v;
	std::vector<int>::iterator a, d;
	std::vector<int>::iterator b(a); // copy constr
	std::vector<int>::iterator c = a; // copy assign

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

void	tests_arithmetic_operators()
{
	std::cout << BCYAN << "### arithmetic operators ###" << END << std::endl << std::endl;
	std::vector<int> v;
	std::vector<int>::iterator it; // default constructible

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

/* 	printVec(v);
	it = v.begin();
	std::cout << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*it++\t\t=\t" << *it++ << std::endl;
	std::cout << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*++it\t\t=\t" << *++it << std::endl;

	std::cout << std::endl << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*it--\t\t=\t" << *it-- << std::endl;
	std::cout << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*--it\t\t=\t" << *--it << std::endl; */

	it = v.begin() + 2;

	std::cout << std::endl << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*(it + 1)\t=\t" << *(it + 1) << std::endl;
	//std::cout << "*(1 + it)\t=\t" << *(1 + it) << std::endl;
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
	for (size_t i = 0; i < v.size(); i++)
		std::cout << "it[i]\t=\t" << it[i] << std::endl;
	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}


void	tests_constructors_iterator()
{
	std::cout << BCYAN << "### constructor ###" << END << std::endl << std::endl;
	std::vector<int> v;
	std::vector<int>::iterator it; // default constructible
	std::vector<int>::iterator copy_constr(it); // copy constructible
	std::vector<int>::iterator copy_assign = it; // copy assignable

	v.push_back(500);
	v.push_back(600);
	v.push_back(700);
	v.push_back(800);

	printVec(v);
	it = v.begin() + 2;
	copy_constr = it;
	copy_assign = it;

	std::cout << std::endl << END << "*it\t\t=\t" << *it << std::endl;
	std::cout << "*copy_constr\t=\t" << *copy_constr << std::endl;
	std::cout << "*copy_assign\t=\t" << *copy_assign << std::endl;
	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}

void	tests_operator_iterator()
{
	//tests_arithmetic_operators();
	//tests_relational_operators();
}

void	tests_iterator()
{
	std::cout << BYELLOW << "*** TEST ITERATOR ***" << END << std::endl << std::endl;
	tests_constructors_iterator();
	//tests_operator_iterator();
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}
