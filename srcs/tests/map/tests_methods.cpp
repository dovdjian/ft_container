/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_methods.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:59:08 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/05 17:20:12 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/utils/tests.hpp"

void	tests_capacity_map()
{
	std::cout << BCYAN << "### capacity ###" << END <<
		std::endl << std::endl;
	prefix::map<char, int> m;

	//printMap(m);
	//std::cout << "m.empty()\t=\t" << m.empty() << std::endl;

	//m.insert(ft::make_pair('a', 10));
	//m.insert(ft::make_pair('b', 20));

	//printMap(m);
	std::cout << "m.empty()\t=\t" << m.empty() << std::endl;
	std::cout << "m.size()\t=\t" << m.size() << std::endl;
	//std::cout << "m.max_size()\t=\t" << m.max_size() << std::endl;

	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}

/* void	tests_modifiers_map()
{
	std::cout << BCYAN << "### modifiers ###" << END <<
		std::endl << std::endl;
	prefix::map<char, int>			m, m2;
	prefix::map<char, int>::iterator	it;

	std::cout << BRED << "--------------------------------" << END
		<< std::endl << std::endl;


	std::cout << std::endl << BCYAN << "### END ###"
		<< END << std::endl << std::endl;
}
 */

void	tests_methods_map()
{
	std::cout << BYELLOW << "*** TEST METHODS ***" << END << std::endl << std::endl;
	tests_capacity_map();
	//tests_modifiers_map();
	std::cout << std::endl << BYELLOW << "*** END ***" << END << std::endl << std::endl;
}
