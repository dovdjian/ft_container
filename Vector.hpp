/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:26:27 by dodjian           #+#    #+#             */
/*   Updated: 2021/12/24 20:53:37by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
// Colors
#define PURPLE	"\033[0;35m"
#define BLACK	"\033[1;30m"
#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define PURPLE2 "\033[1;35m"
#define CYAN	"\033[1;36m"
#define WHITE	"\033[1;37m"
#define END		"\033[0m"

#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <vector>

namespace ft
{
	template <class T, class Alloc = std::allocator <T> >
	class Vector
	{
		public:
			explicit Vector (const Alloc &alloc = Alloc());
			explicit Vector (size_t n, const T &val = T(), const Alloc &alloc = Alloc());
			template <class InputIterator> Vector (InputIterator first, InputIterator last, const Alloc &alloc = Alloc());
			Vector (const Vector &x);
			~Vector();
			Vector &		operator=(const Vector &x);
			// Iterator
			Vector iterator begin()
			{

			}
			// Method
			void push_back(const T &val)
			{
				Vector<int> my_vector;
				T new_val;
				for (Vector<int>::iterator it = my_vector.begin() ; it != my_vector.end(); ++it){}
				//if (Vector.size() > Vector.capacity())
				//	reallocation
			}
		private:
	};
}

//std::ostream &			operator<<( std::ostream & o, Vector const & i );

#endif /* ********************************************************** VECTOR_H */
