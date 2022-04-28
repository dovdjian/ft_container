/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:15:14 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/28 11:27:05 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/utils/tests.hpp"

bool	isFt(ft::vector<int> x)
{
	static_cast<void>(x);
	return true;
}

bool	isFt(std::vector<int> x)
{
	static_cast<void>(x);
	return false;
}

void	tests_vector()
{
	clock_t		t;
	t = clock();

	tests_constructor();
	tests_iterator();
	tests_r_iterator();
	tests_methods();

	t = clock() - t;
	prefix::vector<int> new_vec;
	std::cerr << "time for "
		<< (isFt(new_vec) ? "ft::" : "std::")
		<< "vector: [" << BRED
		<< (static_cast<double>(t) / CLOCKS_PER_SEC)
		<< END << "]" << std::endl;
}
