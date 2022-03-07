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

void	test_constructor_and_iterator()
{
	std::cout << BRED << "Create obj with all constructor !" << END << std::endl << std::endl;

	ft::vector<int> first;				// empty ft::vector of ints
	ft::vector<int> second(4,100);		// four ints with value 100
	//ft::vector<int> third(second.begin(), second.end());  // iterating through second
	//ft::vector<int> fourth(third); // copy
	first.push_back(10);
	first.push_back(20);
	first.pop_back();
	first.push_back(30);
	//first.insert(8);
	first.push_back(40);
	first.push_back(50);
	std::cout << "first.size()\t=\t" << first.size() << std::endl;
	for (size_t i = 0; i < first.size(); i++)
		std::cout << "first[i]\t=\t" << first[i] << std::endl;

	std::cout << std::endl << " --------------- TEST ITERATORS --------------- " << std::endl << std::endl;

	ft::vector<int>::iterator it;
	for (it = first.begin() ; it != first.end() ; ++it)
		std::cout << "*it\t=\t" << *it << std::endl;
	//first.pop_back();
	std::cout << "*after pop back\t=\t" << *it << std::endl;

	std::cout << BYELLOW << "The contents of second(4, 100) are:" << std::endl << BBLUE;
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << "*it\t=\t" << *it << std::endl;
	//std::cout << std::endl;
	//std::cout << BYELLOW << "The contents of third(second.begin, second.end) are:" << BBLUE;
	/* for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << BYELLOW << "The contents of fourth(third) are:" << BBLUE;
	for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it; */
	//std::cout << std::endl;

	// the iterator constructor can also be used to construct from arrays:
	/* int myints[] = {16,2,77,29};
	std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << BYELLOW << "The contents of fifth are:" << BBLUE;
	for std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << BYELLOW << "The contents of fifth in reverse are:" << BBLUE;
	for (std::vector<int>::reverse_iterator it = fifth.rbegin(); it != fifth.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl << std::endl << END; */
}

/* void	test_relational_operators()
{
	std::cout << BRED << "Test relational operator !" << END << std::endl << std::endl;
	//ft::vector v;
	ft::vector<int> v (3,100);	// three ints with a value of 100
	ft::vector<int> v2 (2,200);	// two ints with a value of 200
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

void	test_operator()
{
	std::cout << BRED << "Test all operator !" << END << std::endl << std::endl;
	//test_relational_operators();
	test_constructor_and_iterator();
}


void	test_vector()
{
	test_operator();
}
