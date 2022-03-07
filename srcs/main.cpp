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
	std::cout << BBLUE << std::endl << "Test stack:" << END << std::endl << std::endl;
	test_map();
	std::cout << BGREEN << std::endl << "Test map:" << END << std::endl << std::endl;
	test_stack();

	std::string file_str, line;
	std::ifstream ifs("./container", std::ofstream::out | std::ofstream::binary);
	std::ofstream file("ft_output.txt");

	ifs.open("./container", std::ofstream::out | std::ofstream::binary);
	if (!ifs.is_open())
		//throw std::invalid_argument("[Error] Opening file");
		return (-1);
	while (std::getline(ifs, line))
		file_str += line;

	ifs.close();
	file << file_str;
	return (0);
}
