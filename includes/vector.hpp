/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
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
#define YELLOW		"\033[0;33m"
#define PURPLE		"\033[0;35m"
#define BBLACK		"\033[1;30m"
#define BRED		"\033[1;31m"
#define BGREEN		"\033[1;32m"
#define BYELLOW		"\033[1;33m"
#define BBLUE		"\033[1;34m"
#define BPURPLE		"\033[1;35m"
#define BCYAN		"\033[1;36m"
#define BWHITE		"\033[1;37m"
#define END			"\033[0m"

#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

namespace ft
{
	template <class T, class Alloc = std::allocator <T> >
	class vector
	{
		public:
		// Iterator
			class Iterator
			{
				bool	operator < (vector const &src) const { return (*this < src);}
				bool	operator > (vector const &src) const { return (*this > src);}
				bool	operator <= (vector const &src) const { return (*this <= src);}
				bool	operator >= (vector const &src) const { return (*this >= src);}
				bool	operator == (vector const &src) const { return (*this == src);}
				bool	operator != (vector const &src) const { return (*this != src);}
				public:
					Iterator();
					~Iterator();
			};
		// Typedef iterator
			typedef vector::Iterator iterator;
			typedef vector::Iterator const_iterator;
			typedef vector::Iterator reverse_iterator;
			typedef vector::Iterator const_reverse_iterator;
			iterator begin() { return (iterator(*this, 0));}
			iterator end() { return (iterator(*this, this->size()));}
			reverse_iterator rbegin() { return (reverse_iterator(*this, 0));}
			reverse_iterator rend() { return (reverse_iterator(*this, this->size()));}
		// Typedef
			typedef Alloc allocator_type;
			typedef typename Alloc::value_type value_type;
			typedef typename Alloc::size_type size_type;
			typedef typename Alloc::difference_type difference_type;
			typedef typename Alloc::reference reference;
			typedef typename Alloc::const_reference const_reference;
			typedef typename Alloc::pointer pointer;
			typedef typename Alloc::const_pointer const_pointer;
		// Constructor
			vector(){};
			explicit vector (const allocator_type &alloc = allocator_type())
			{
				(void)alloc;
			}
			explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator())
			{
				(void)n;
				(void)val;
				(void)alloc;
				//(void)allocator;
			}
			//template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator &alloc = allocator()){}
			//vector (const vector &x){(void)x;}
		// Destructor
			~vector(){}
		// Operator
			/* vector &		operator=(const vector &x){}
			reference		operator[] (size_type n){}
			const_reference	operator[] (size_type n) const{} */
		// Method
			//Capacity
				size_type size() const{ return (this->_size);}
				//size_type max_size() const {}
				//void resize (size_type n, value_type val = value_type()){}
				size_type capacity() { return (this->_capacity);}
				bool empty() const{ return (this->size() == 0 ? true : false);}
				/* void reserve (size_type n)
				{
					if (n > this->capacity())
						reallocation
					if (n > this->max_size())
						throw (std::length_error);
				} */
			// Element access
				reference at (size_type n)
				{
					//if (n > this->size())
						//throw (std::out_of_range());
					for (size_type i = 0; i < n; i++){}
					//return (reference val);
				}
				const_reference at (size_type n) const
				{
					//if (n > this->size())
						//throw (std::out_of_range());
					for (size_type i = 0; i < n; i++){}
					//return (const_reference val);
				}
				reference front(){}
				const_reference front() const{}
				reference back(){}
				const_reference back() const{}
			// Modifiers
				/* template <class InputIterator>
				void assign (InputIterator first, InputIterator last){}
				void assign (size_type n, const value_type& val){}
				void push_back(const value_type &val)
				{
					vector<value_type> my_vector;
					for (vector<int>::iterator it = my_vector.begin() ; it != my_vector.end(); ++it){}
					*it = val;
					//if (vector.size() > vector.capacity())
						//reallocation
				}
				void pop_back(){}
				iterator insert (iterator position, const value_type& val){}
				void insert (iterator position, size_type n, const value_type& val){}
				template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last){}
				iterator erase (iterator position){}
				iterator erase (iterator first, iterator last){}
				void swap (vector& x){}
				void clear(){} */
			// Allocator
				//allocator_type get_allocator() const{}
		private:
			size_type _size;
			size_type _capacity;
	};
}

// Non member function overload
/*
	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);*/

#endif /* ********************************************************** `VECTOR_HPP */
