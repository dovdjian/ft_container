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
#include "stack.hpp"
#include "map.hpp"
#include "tests.hpp"

int main(void)
{
	std::cout << PURPLE << "Test vector:" << END << std::endl << std::endl;
	test_vector();
	std::cout << PURPLE << "Test stack:" << END << std::endl << std::endl;
	test_map();
	std::cout << PURPLE << "Test map:" << END << std::endl << std::endl;
	test_stack();
	return (0);
}
