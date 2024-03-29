/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_methods.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:27:50 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/26 17:02:26 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/utils/tests.hpp"

void	tests_capacity()
{
	std::cout << BCYAN << "### capacity ###" << END <<
		std::endl << std::endl;
	prefix::vector<int> v;

	printVec(v);
	std::cout << "v.empty()\t=\t" << v.empty() << std::endl;

	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(8);

	printVec(v);
	std::cout << "v.empty()\t=\t" << v.empty() << std::endl;
	std::cout << "v.size()\t=\t" << v.size() << std::endl;
	std::cout << "v.max_size()\t=\t" << v.max_size() << std::endl;
	v.resize(2);

	std::cout << std::endl << BPURPLE << "V RESIZED TO 2"
		<< std::endl << std::endl << END;

	std::cout << "v.size()\t=\t" << v.size() << std::endl;

	v.resize(10);
	std::cout << std::endl << BPURPLE << "V RESIZED TO 10"
		<< std::endl << std::endl << END;
	std::cout << "v.size()\t=\t" << v.size() << std::endl;
	v.reserve(100);
	std::cout << std::endl << BPURPLE << "V RESERVE TO 100"
		<< std::endl << std::endl << END;
	std::cout << "v.capacity()\t=\t" << v.capacity() << std::endl;

	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}

void	tests_element_access()
{
	std::cout << BCYAN << "### element access ###" << END <<
		std::endl << std::endl;
	prefix::vector<int>			v;
	prefix::vector<int>::iterator	it;

	v.push_back(2);
	v.push_back(4);
	v.push_back(8);
	v.push_back(16);

	printVec_index(v);

	std::cout << "v.at(0)\t=\t" << v.at(0) << std::endl;
	v.at(2) = 3;
	std::cout << std::endl << BPURPLE << "V AT(2) TO 3"
		<< std::endl << std::endl << END;
	printVec(v);

	std::cout << "v.front()\t=\t" << v.front() << std::endl;
	std::cout << "v.back()\t=\t" << v.back() << std::endl;
	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}

void	tests_modifiers()
{
	std::cout << BCYAN << "### modifiers ###" << END <<
		std::endl << std::endl;
	prefix::vector<int>			v, v2;
	prefix::vector<int>::iterator	it;

	v.assign(7,100);
	it = v.begin() + 1;
	v2.assign(it, v.end() - 1);

	v.push_back(12);
	std::cout << "v" << std::endl;
	printVec(v);

	std::cout << "v2 before pop back" << std::endl;
	printVec(v2);
	v2.pop_back();
	std::cout << "v2 after pop back" << std::endl;
	printVec(v2);
	std::cout << BRED << "--------------------------------" << END
		<< std::endl << std::endl;

	it = v2.begin() + 1;
	v2.insert(it, 1);
	std::cout << "v2 insert nombre 1 a position begin + 1"
		<< std::endl;
	printVec(v2);
	v2.insert(it, 2, 300);
	std::cout << "v2 insert 2 fois nombre 300 a position begin + 1"
		<< std::endl;
	printVec(v2);
	std::cout << "v2 erase le nombre a begin + 3 (1)" << std::endl;
	v2.erase(v2.begin() + 3);
	printVec(v2);
	std::cout << "v2 erase begin + 3 a end (tous les 100)" << std::endl;
	v2.erase(v2.begin() + 3, v2.end());
	printVec(v2);
	std::cout << BRED << "--------------------------------" << END
		<< std::endl;
	std::cout << std::endl << "BEFORE SWAP" << std::endl;
	printVec(v);
	printVec(v2);
	std::cout << "AFTER SWAP V WITH V2 CONTENT" << std::endl;
	v.swap(v2);
	printVec(v);
	printVec(v2);
	v.clear();
	v2.clear();
	std::cout << "AFTER CLEAR" << std::endl;
	printVec(v);
	printVec(v2);

	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}

void	tests_allocator()
{
	std::cout << BCYAN << "### allocator ###" << END <<
		std::endl << std::endl;
	prefix::vector<int>	v;
	int					*p;
	unsigned int		i;

	p = v.get_allocator().allocate(5);
	for (i = 0; i < 5; i++)
		v.get_allocator().construct(&p[i] , i);
	std::cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		std::cout << ' ' << p[i];
	std::cout << std::endl;
	for (i = 0; i < 5; i++)
		v.get_allocator().destroy(&p[i]);
	v.get_allocator().deallocate(p, 5);

	std::cout << std::endl << BCYAN << "### END ###"
	<< END << std::endl << std::endl;
}



void	tests_methods()
{
	std::cout << BYELLOW << "*** TEST METHODS ***" << END << std::endl << std::endl;
	tests_capacity();
	tests_element_access();
	tests_modifiers();
	tests_allocator();
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}

void	tests_constructor()
{
	std::cout << BYELLOW << "*** TEST CONSTRUCTORS ***" << END << std::endl << std::endl;
	prefix::vector<int> first;                                // empty vector of ints
	prefix::vector<int> second(5, 20);                       // four ints with value 100
	std::cout << std::endl << "SECOND INIT" << std::endl;
	printVec(second);
	while (!second.empty())
		second.pop_back();
	for (int i = 0; i < 10; i++)
		second.push_back(i);
	prefix::vector<int>::iterator it_test = second.begin();
	prefix::vector<int>::iterator it_test_end = second.end();

	it_test_end--;
	std::cout << "DECREMENT END ITERATOR THIRD" << std::endl;
	prefix::vector<int> third(it_test, it_test_end);  // iterating through second
	prefix::vector<int> fourth(third);                       // a copy of third

	std::cout << "FIRST" << std::endl;
	printVec(first);
	std::cout << std::endl << "SECOND" << std::endl;
	printVec(second);
	std::cout << std::endl << "THIRD" << std::endl;
	printVec(third);
	std::cout << std::endl << "FOURTH" << std::endl;
	printVec(fourth);
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}
