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

#include "../includes/utils/tests.hpp"

int	main(void)
{
	try
	{
		std::cout << PURPLE << "--------------- TEST VECTOR ---------------"
			<< END << std::endl << std::endl;
		//tests_vector();
		std::cout << PURPLE << "------------------- END -------------------"
			<< END << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << BBLUE << std::endl <<  "--------------- TEST STACK ----------------"
			<< END << std::endl << std::endl;
		//tests_stack();
		std::cout << BBLUE << std::endl <<  "------------------- END -------------------"
			<< END << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << BGREEN << std::endl <<  "---------------- TEST MAP -----------------"
			<< END << std::endl << std::endl;
		tests_map();
		std::cout << BGREEN << std::endl <<  "------------------- END -------------------"
			<< END << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
