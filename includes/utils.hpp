/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:41:37 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/09 18:28:16 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "vector.hpp"

template <typename T>
void printVec(T & vec)
{
	typename T::iterator it;
	typename T::iterator end;

	std::cout << BGREEN << "vec = [ ";
	end = vec.end();
	for (it = vec.begin() ; it != end ; ++it)
		std::cout << *it << " ";
	std::cout << "]" << std::endl << std::endl << END;
}

template <typename T>
void printVec_index(T & vec)
{
	std::cout << BGREEN << "vec = [ ";
	for (size_t i = 0; i < vec.size() ; ++i)
		std::cout << vec[i] << " ";
	std::cout << "]" << std::endl << std::endl << END;
}



#endif
