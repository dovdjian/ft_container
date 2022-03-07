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

	/* std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!	 */
	std::ofstream out("out.txt");
	//std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!


	//while (std::getline(std::cin, line))  //input from the file in.txt
		//std::cout << line << "\n";   //output to the file out.txt
	//std::cout.rdbuf(coutbuf); //reset to standard output again
}
