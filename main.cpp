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

	std::vector<int> first;				// empty vector of ints
	std::vector<int> second(4,100);		// four ints with value 100
	std::vector<int> third(second.begin(), second.end());  // iterating through second
	std::vector<int> fourth(third); // copy
	std::cout << BYELLOW << "The contents of first are:" << BBLUE;
	for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << BYELLOW << "The contents of second(4, 100) are:" << BBLUE;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << BYELLOW << "The contents of third(second.begin, second.end) are:" << BBLUE;
	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << BYELLOW << "The contents of fourth(third) are:" << BBLUE;
	for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << BYELLOW << "The contents of fifth are:" << BBLUE;
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << BYELLOW << "The contents of fifth in reverse are:" << BBLUE;
	for (std::vector<int>::reverse_iterator it = fifth.rbegin(); it != fifth.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl << std::endl << END;
}

void	test_operator()
{
	std::cout << BRED << "Test all operator !" << END << std::endl << std::endl;
	std::vector<int> foo(3,0);
	std::vector<int> bar(5,0);
	bar = foo;
	foo = std::vector<int>();
	std::cout << "Size of foo: " << int(foo.size()) << std::endl;
	std::cout << "Size of bar: " << int(bar.size()) << std::endl;
}

int main(void)
{
	//std::cout << BGREEN << "C++ |" << BRED << " MOI" << END << std::endl << std::endl;
	test_constructor_and_iterator();
	std::cout << "----------------------------" << std::endl;
	test_operator();
	return (0);
}
