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
	class vector
	{
		public:
		// Typedef
			typedef T value_type;
			typedef Alloc allocator;
			typedef size_t size_type;
		// Constructor
			explicit vector (const allocator &alloc = allocator()){(void)alloc;}
			//explicit vector (size_type n, const value_type &val = value_type(), const allocator &alloc = allocator()){}
			//template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator &alloc = allocator()){}
			vector (const vector &x){(void)x;}
		// Destructor
			~vector(){}
			vector &		operator=(const vector &x){(void)x;}
		// Iterator
			class Iterator
			{
				public:
					Iterator();
					~Iterator();
			};
			typedef vector::Iterator iterator;
			iterator begin() { return (iterator(*this, 0));}
			iterator end() { return (iterator(*this, this->size()));}
		// Method
			size_type size() const{ return (this->_size);}
			//size_t max_size() const {}
			//void resize (size_type n, value_type val = value_type()){}
			size_type capacity() { return (this->_capacity);}
			bool empty() const{ return (this->size() == 0 ? true : false);}
			void reserve (size_type n)
			{
				/* if (n > this->capacity())
					reallocation
				if (n > this->max_size())
					throw (std::length_error); */
			}
			void push_back(const T &val)
			{
				(void)val;
				vector<T> my_vector;
				T new_val;
				//for (vector<int>::iterator it = my_vector.begin() ; it != my_vector.end(); ++it){}
				//if (Vector.size() > Vector.capacity())
				//	reallocation
			}
		private:
			size_type _size;
			size_type _capacity;
	};
}

//std::ostream &			operator<<( std::ostream & o, Vector const & i );

#endif /* ********************************************************** VECTOR_H */
