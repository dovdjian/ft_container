/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:28:18 by dodjian           #+#    #+#             */
/*   Updated: 2021/12/26 17:25 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

void	tests_relational_operators()
{
	std::cout << BCYAN << "### relational operators ###" << END << std::endl << std::endl;
	std::vector<int> v;
	std::vector<int>::iterator a;
	std::vector<int>::iterator b(a); // copy constr
	std::vector<int>::iterator c = a; // copy assign

	v.push_back(6);
	v.push_back(7);

	a = v.begin();
	b = a;
	c = b + 1;
	std::cout << "*a\t=\t" << *a << std::endl;
	std::cout << "*b\t=\t" << *b << std::endl;
	std::cout << "*c\t=\t" << *c << std::endl;
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

	std::cout << "PUSHBACK 10, 20, 30, 40" << std::endl;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	it = v.begin();
	std::cout << "*it\t=\t" << *it << std::endl;
	std::cout << "*it++\t=\t" << *it++ << std::endl;
	std::cout << "*it\t=\t" << *it << std::endl;
	std::cout << "*++it\t=\t" << *++it << std::endl;
	std::cout << "*it\t=\t" << *it << std::endl << std::endl;

	std::cout << "*it--\t=\t" << *it-- << std::endl;
	std::cout << "*it\t=\t" << *it << std::endl;
	std::cout << "*--it\t=\t" << *--it << std::endl;
	std::cout << "*it\t=\t" << *it << std::endl << std::endl;

	it = v.begin() + 2;

	std::cout << "*it\t=\t" << *it << std::endl;
	std::cout << "*(it + 1)\t=\t" << *(it + 1) << std::endl;
	std::cout << "*(1 + it)\t=\t" << *(1 + it) << std::endl;
	std::cout << "*(it - 1)\t=\t" << *(it - 1) << std::endl;
	std::cout << "*(it - 2)\t=\t" << *(it - 2) << std::endl;
	//it += 2;
	//it -= 2;
	//--it; // pre decr
	//it--; // post decr
	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}


void	tests_constructors_iterator()
{
	std::cout << BCYAN << "### constructor ###" << END << std::endl << std::endl;
	std::vector<int> v;
	std::vector<int>::iterator it; // default constructible
	std::vector<int>::iterator copy_constr(it); // copy constructible
	std::vector<int>::iterator copy_assign = it; // copy assignable

	std::cout << "PUSHBACK 10, 20, 30, 40" << std::endl;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	it = v.begin();
	copy_constr = it; // operator =
	//if (it == copy_constr) // operator ==

	std::cout << BRED << "*IT = *COPY_CONSTR" << std::endl;
	while (it != v.end())
	{
		std::cout << *it << " = " <<
			*copy_constr << std::endl; // operator *
		++it; // pre incr
		copy_constr++; // post incre
	}
	it = v.begin();
	it--; // post decr
	copy_assign = it;
	std::cout << BBLUE << "*IT = *COPY_ASSIGN" << std::endl;
	while (it != v.end())
	{
		std::cout << *it << " = " <<
			*copy_assign << std::endl;
		it++;
		++copy_assign;
	}
	*it = 10;
	std::cout << END << "*it after assign to 10\t\t=\t" << *it << std::endl;
	std::cout << "*copy_constr after assign to 10\t=\t" << *copy_constr << std::endl;
	std::cout << "*copy_assign after assign to 10\t=\t" << *copy_assign << std::endl;
	std::cout << std::endl << BCYAN << "### END ###" << END << std::endl << std::endl;
}

void	tests_iterator()
{
	std::cout << BYELLOW << "*** TEST ITERATOR ***" << END << std::endl << std::endl;
	tests_relational_operators();
	tests_arithmetic_operators();
	tests_constructors_iterator();
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}

/* void	test_relational_operators()
{
	std::cout << BRED << "Test relational operator !" << END << std::endl << std::endl;
	//std::vector v;
	std::vector<int> v (3,100);	// three ints with a value of 100
	std::vector<int> v2 (2,200);	// two ints with a value of 200
	std::vector<int> v_stl (3,100);	// three ints with a value of 100
	std::vector<int> v2_stl (2,200);	// two ints with a value of 200

	std::cout << BPURPLE << "my tests:  " << std::endl << std::endl;
	if (v == v2)
		std::cout << "foo and bar are equal" << std::endl;
	//if (v != v2)
		//std::cout << "foo and bar are not equal" << std::endl;
	//if (v < v2)
		//std::cout << "foo is less than bar" << std::endl;
	if (v > v2)
		std::cout << "foo is greater than bar" << std::endl;
	if (v <= v2)
		std::cout << "foo is less than or equal to bar" << std::endl;
	if (v >= v2)
		std::cout << "foo is greater than or equal to bar" << std::endl;
	std::cout << BYELLOW << "stl tests: " << std::endl << std::endl;
	if (v_stl == v2_stl)
		std::cout << "foo and bar are equal" << std::endl;
	if (v_stl != v2_stl)
		std::cout << "foo and bar are not equal" << std::endl;
	if (v_stl < v2_stl)
		std::cout << "foo is less than bar" << std::endl;
	if (v_stl > v2_stl)
		std::cout << "foo is greater than bar" << std::endl;
	if (v_stl <= v2_stl)
		std::cout << "foo is less than or equal to bar" << std::endl;
	if (v_stl >= v2_stl)
		std::cout << "foo is greater than or equal to bar" << std::endl;
} */

void	tests_operator()
{
	std::cout << BRED << "Test all operator !" << END << std::endl << std::endl;
	//test_relational_operators();
}


void	tests_vector()
{
	//tests_operator();
	tests_iterator();
}
