/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:28:18 by dodjian           #+#    #+#             */
/*   Updated: 2021/12/26 17:25:07by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

void	tests_iterator()
{
	std::cout << BYELLOW << "*** TEST ITERATOR ***" << END << std::endl << std::endl;
	std::vector<int> v;
	std::vector<int>::iterator it; // default constructible
	std::vector<int>::iterator copy_constr(it); // copy constructible
	std::vector<int>::iterator copy_assign = it; // copy assignable

	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	v.push_back(3);

	it = v.begin();
	--it; // pre decr
	copy_constr = it; // operator =
	//if (it == copy_constr) // operator ==

	std::cout << "*IT = *COPY_CONSTR" << std::endl;
	while (it != v.end())
	{
		std::cout << BRED <<
			*it << " = " << *copy_constr << END << std::endl; // operator *
		++it; // pre incr
		copy_constr++; // post incre
	}
	std::cout << "*IT = *COPY_ASSIGN" << std::endl;
	it = v.begin();
	it--; // post decr
	copy_assign = it;
	while (it != v.end())
	{
		std::cout << BBLUE <<
			*it << " = " << *copy_assign << END << std::endl;
		it++;
		++copy_assign;
	}
	*it = 10;
	std::cout << "*it after assign to 10\t=\t" << *it << std::endl;
	std::cout << "*it after assign to 10\t=\t" << *copy_assign << std::endl;
	std::cout << "*it after assign to 10\t=\t" << *copy_constr << std::endl;
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