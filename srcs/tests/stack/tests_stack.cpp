/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_stack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:15:14 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/28 11:29:06 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/utils/tests.hpp"

bool	isFt(ft::stack<int> x)
{
	static_cast<void>(x);
	return true;
}

bool	isFt(std::stack<int> x)
{
	static_cast<void>(x);
	return false;
}

void	tests_stack()
{
	clock_t		t;
	t = clock();

	tests_constructor_stack();
	tests_methods_stack();

	t = clock() - t;
	prefix::stack<int> new_stack;
	std::cerr << "time for "
		<< (isFt(new_stack) ? "ft::" : "std::")
		<< "stack: [" << BGREEN
		<< (static_cast<double>(t) / CLOCKS_PER_SEC)
		<< END << "]" << std::endl;
}
