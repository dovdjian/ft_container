/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_methods.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:59:08 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/25 16:10:01 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/utils/tests.hpp"

void	tests_capacity_map()
{
	std::cout << BCYAN << "### capacity ###" << END <<
		std::endl << std::endl;
	prefix::map<char, int> m;

	printMap(m);
	std::cout << "m.empty()\t=\t" << m.empty() << std::endl;

	m.insert(prefix::make_pair('a', 10));
	m.insert(prefix::make_pair('b', 20));

	printMap(m);
	std::cout << "m.empty()\t=\t" << m.empty() << std::endl;
	std::cout << "m.size()\t=\t" << m.size() << std::endl;
	std::cout << "m.max_size()\t=\t" << m.max_size() << std::endl;

	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}

void	tests_element_access_map()
{
	std::cout << BCYAN << "### element_access ###" << END <<
		std::endl << std::endl;
	prefix::map<char, int> m;

	m['a'] = 77;
	m['b'] = 88;
	m['c'] = m['b'];

	std::cout << "m['a'] is " << m['a'] << std::endl;
	std::cout << "m['b'] is " << m['b'] << std::endl;
	std::cout << "m['c'] is " << m['c'] << std::endl;
	std::cout << "m['d'] is " << m['d'] << std::endl;

	std::cout << "m.size()\t=\t" << m.size() << std::endl;
	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}

void	tests_modifiers_map()
{
	std::cout << BCYAN << "### modifiers ###" << END <<
		std::endl << std::endl;
	prefix::map<char, int> m;
	// first insert function version (single parameter):

	m.insert(prefix::pair<char, int>('a', 100));
	m.insert(prefix::pair<char, int>('z', 200));
	// second insert function version (with hint position):

	prefix::map<char, int>::iterator it = m.begin();
	m.insert(it, prefix::pair<char, int>('b', 300));  // max efficiency inserting
	m.insert(it, prefix::pair<char, int>('c', 400));  // no max efficiency inserting
	// third insert function version (range insertion):

	prefix::map<char, int> m2;
	m2.insert(m.begin(), m.find('c'));
	// showing contents:
	std::cout << "map1: " << std::endl;
	printMap(m);
	std::cout << "map2: " << std::endl;
	printMap(m2);

	/*it = m.find('c');
	m.erase(it);
	std::cout << "erase by iterator with key = c" << std::endl;
	printMap(m);

	m.erase('z');
	std::cout << "erase z with key" << std::endl;
	printMap(m);

	m.erase(m.begin(), m.end());
	std::cout << "erase range begin to end: all and clear m2" << std::endl;
	printMap(m);
	m2.clear();

	m['e'] = 1;
	m['f'] = 2;
	m['g'] = 3;

	m2['x'] = 11;
	m2['y'] = 22;
	m2['z'] = 33;
	printMap(m);
	printMap(m2);

	m.swap(m2);
	std::cout << "swap m with m2" << std::endl;
	std::cout << "map1: " << std::endl;
	printMap(m);
	std::cout << "map2: " << std::endl;
	printMap(m2);

	std::cout << "clear m and m2" << std::endl;
	m.clear();
	m2.clear();
	std::cout << "map1: " << std::endl;
	printMap(m);
	std::cout << "map2: " << std::endl;
	printMap(m2);
 */
	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}

void	tests_observers()
{
	std::cout << BCYAN << "### observers ###" << END <<
		std::endl << std::endl;

	prefix::map<char, int> m;
	prefix::map<char, int>::key_compare mycomp = m.key_comp();

	m['a'] = 1;
	m['b'] = 2;
	m['c'] = 3;

	std::cout << "test keycomp with highest char = c" << std::endl;
	char highest = m.rbegin()->first;
	prefix::map<char, int>::iterator it = m.begin();
	std::cout << it->first << " => " << it->second << std::endl;
	while (mycomp((*it++).first, highest))
		std::cout << it->first << " => " << it->second << std::endl;

	m.clear();

	m['x'] = 1001;
	m['y'] = 2002;
	m['z'] = 3003;

	std::cout << std::endl << "test value comp with pair highest : z => 3003" << std::endl;
	prefix::pair<char,int> pair_highest = *m.rbegin();
	it = m.begin();

	std::cout << it->first << " => " << it->second << std::endl;
	while (m.value_comp()(*it++, pair_highest))
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}

void	tests_operations()
{
	std::cout << BCYAN << "### observers ###" << END <<
		std::endl << std::endl;

	prefix::map<char, int> m;
	prefix::map<char, int>::iterator it;

	m['a'] = 50;
	m['b'] = 100;
	m['c'] = 150;
	m['d'] = 200;

	std::cout << "find b" << std::endl;

	it = m.find('b');
	std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl << "count a = " << m.count('a') << std::endl;
	std::cout << "count e = " << m.count('e') << std::endl;
	prefix::map<char, int>::iterator it_low, it_up;

	it_low = m.lower_bound('b');
	it_up = m.upper_bound('c');

	std::cout << std::endl << "it_low: " << it_low->first << " => " << it_low->second << std::endl;
	std::cout << "it_up: " << it_up->first << " => " << it_up->second << std::endl;

	prefix::pair<prefix::map<char, int>::iterator,
		prefix::map<char, int>::iterator> pair_range;

	pair_range = m.equal_range('a');

	std::cout << std::endl << "lower bound points to: ";
	std::cout << pair_range.first->first << " => " << pair_range.first->second << std::endl;

	std::cout << "upper bound points to: ";
	std::cout << pair_range.second->first << " => " << pair_range.second->second << std::endl;

	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}

void	tests_allocator_map()
{
	std::cout << BCYAN << "### allocator ###" << END <<
		std::endl << std::endl;

	int psize;
	prefix::map<char, int> m;
	prefix::pair<const char, int>* p;

	p = m.get_allocator().allocate(5);
	psize = sizeof(prefix::map<char, int>::value_type) * 5;
	std::cout << "The allocated array has a size of " << psize << " bytes. (5 * 8)" << std::endl;

	m.get_allocator().deallocate(p, 5);

	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}

void	tests_methods_map()
{
	std::cout << BYELLOW << "*** TEST METHODS ***" << END << std::endl << std::endl;
	//tests_capacity_map(); // ok
	//tests_element_access_map(); // ok
	tests_modifiers_map();
	//tests_observers();
	//tests_operations(); // ok
	//tests_allocator_map(); // ok
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}
