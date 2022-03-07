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
#include <memory>
#include <iterator>

namespace ft
{
	// forward declare the iterator

	template <class T, class Alloc>
		class Iterator;
	template <class T, class Alloc>
		class Const_Iterator;

	template <class T, class Alloc = std::allocator <T> >
	class vector
	{
		public:
		// TYPEDEF
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename Alloc::size_type size_type;
			typedef typename Alloc::difference_type difference_type;
			typedef typename Alloc::reference reference;
			typedef typename Alloc::const_reference const_reference;
			typedef typename Alloc::pointer pointer;
			typedef typename Alloc::const_pointer const_pointer;
		// make the iterator a friend
			friend class Iterator <value_type, allocator_type >;
			friend class Const_Iterator <value_type, allocator_type >;
		// ITERATOR
			class Iterator : public std::iterator<std::random_access_iterator_tag, value_type>
			{
				public:
				// CONSTRUCTOR
					// Default
						Iterator() : _v(NULL)
						{

						}
					// COPY
						Iterator(const Iterator & it)
						{
							this->_v = it._v;
							this->_index = it._index;
						}
					// ?
						Iterator(vector * v, int index)
						{
							this->_v = v;
							this->_index = index;
						}
						~Iterator(){}
				// ALL CATEGORIES
					Iterator & operator++() // pre
					{
						std::cout << "preincrement operator" << std::endl;
						_index++;
						return (*this);
					}
					/* Iterator & operator++(value_type) // post
					{
						Iterator<value_type, allocator_type> it;

						it.setElem(this->_elem);
						this->_elem++;
						return (it);
					} */
				// FORWARD
					bool operator==(const Iterator & it)
						{ return (this->_v == it._v && this->_index == it._index); }
					bool operator!=(const Iterator & it)
						{ return (!(*this == it)); }
					value_type & operator*() { return (this->_v->_elements[_index]); }
				// BIDIRECTIONAL

				// RANDOM ACCESS

				private:
					const vector	*_v;
					int				_index;
			};
		// CONST_ITERATOR
		class Const_Iterator : public Iterator
			{
				public:
				// CONSTRUCTOR
					// Default
						Const_Iterator() : _v(NULL)
						{

						}
					// COPY
						Const_Iterator(const Iterator & it)
						{
							this->_v = it._v;
							this->_index = it._index;
						}
					// ?
						Const_Iterator(vector * v, int index)
						{
							this->_v = v;
							this->_index = index;
						}
						~Const_Iterator(){}
				// ALL CATEGORIES
					Iterator & operator++() // pre
					{
						std::cout << "preincrement operator" << std::endl;
						_index++;
						return (*this);
					}
					/* Iterator & operator++(value_type) // post
					{
						Iterator<value_type, allocator_type> it;

						it.setElem(this->_elem);
						this->_elem++;
						return (it);
					} */
				// FORWARD
					bool operator==(const Iterator & it)
						{ return (this->_v == it._v && this->_index == it._index); }
					bool operator!=(const Iterator & it)
						{ return (!(*this == it)); }
					value_type & operator*() { return (this->_v->_elements[_index]); }
				// BIDIRECTIONAL

				// RANDOM ACCESS

				private:
					const vector	*_v;
					int				_index;
			};
		// My Typedef iterator
			typedef vector::Iterator iterator;
			typedef vector::Const_Iterator const_iterator;
			typedef vector::Iterator reverse_iterator;
			typedef vector::Const_Iterator const_reverse_iterator;
		// std Typedef iterator
			/* typedef typename std::vector<T, Alloc>::iterator iterator;
			typedef typename std::vector<T, Alloc>::const_iterator const_iterator;
			typedef typename std::vector<T, Alloc>::reverse_iterator reverse_iterator;
			typedef typename std::vector<T, Alloc>::const_reverse_iterator const_reverse_iterator; */
			//typedef std::vectorerator const_iterator;
			//typedef std::vector reverse_iterator;
			//typedef std::vectorerator const_reverse_iterator;
		// METHOD ITERATOR
			iterator begin() { return (iterator(this, 0));}
			iterator end() { return (iterator(this, this->_size));}
			const_iterator begin() const { return (const_iterator(this, 0));}
			const_iterator end() const { return (const_iterator(this, this->_size));}
			//reverse_iterator rbegin() { return (reverse_iterator(*this, this->_size));}
			//reverse_iterator rend() { return (reverse_iterator(*this, 0));}
			//const_reverse_iterator rbegin() const { return (const_reverse_iterator(*this, this->_size));}
			//const_reverse_iterator rend() const { return (const_reverse_iterator(*this, 0));}
		// CONSTRUCTOR
			// DEFAULT
				explicit vector (const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _capacity(0), _size(0), _elements(NULL)
				{
				}
			// FILL
				explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _capacity(n), _size(n)
				{
					if (n == 0)
						this->_elements = NULL;
					else
						this->_elements = new value_type[n];
					for (size_type i = 0; i < n; i++)
						this->_elements[i] = val;
				}
			// RANGE
			/* 	template <class InputIterator>
					vector (InputIterator first, InputIterator last,
						const allocator &alloc = allocator_type())
						: _alloc(alloc), _first(first), _last(last)
				{

				} */
			// COPY
				vector (const vector &src) { *this = src; }
		// DESTRUCTOR
			~vector()
			{
				clear();
			}
		// =
			vector &		operator=(const vector &src)
			{
				*this = src;
			}
		// METHODS
			//CAPACITY
				size_type size() const{ return (this->_size); }
				//size_type max_size() const {}
				//void resize (size_type n, value_type val = value_type()){}
				size_type capacity() { return (this->_capacity); }
				bool empty() const{ return (this->_size == 0 ? true : false); }
				/* void reserve (size_type n)
				{
					if (n > this->capacity())
						reallocation
					if (n > this->max_size())
						throw (std::length_error);
				} */
			// ELEMENT ACCESS
				reference		operator[] (size_type n) const
				{
					return (this->_elements[n]);
				}
				//const_reference	operator[] (size_type n) const{}
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
			// MODIFIERS
				//template <class InputIterator>
				//void assign (InputIterator first, InputIterator last){}
				//void assign (size_type n, const value_type& val){}
				void push_back(const value_type &val)
				{
					if (this->_size >= this->_capacity)
						reallocate();
					this->_elements[this->_size] = val;
					this->_size++;
				}
				void pop_back()
				{
					if (this->_size > 0)
					{
						//delete this->_elements;
						this->_size--;
					}
				}
				/*iterator insert (iterator position, const value_type& val){}
				void insert (iterator position, size_type n, const value_type& val){}
				template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last){}
				iterator erase (iterator position){}
				iterator erase (iterator first, iterator last){}
				void swap (vector& x){} */
				void clear()
				{
					if (this->_elements)
						delete []this->_elements;
					this->_size = 0;
					this->_capacity = 0;
				}
			// Allocator
				allocator_type	get_allocator() const{ return (this->_alloc); }
		private:
			// METHODS
				void	reallocate()
				{
					this->_capacity *= 2;
					// allocate 2x larger memory
					value_type *new_mem = new value_type[this->_capacity];
					// copy data to there
					for (size_type i = 0; i < this->_size; ++i)
						new_mem[i] = this->_elements[i];
					delete this->_elements;
					this->_elements = new_mem;
				}
			// VARIABLES
				allocator_type	_alloc;
				size_type		_capacity; // allocate size of container
				size_type		_size; // nbr elements in container
				value_type		*_elements; // elements in container
	};
	// Non member function overload
		template <class T, class Alloc>
			bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
				{ return (lhs.size() == rhs.size()
					&& std::equal(lhs.begin(), lhs.end(), rhs.begin())); }
		template <class T, class Alloc>
				bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
				{ return (!(lhs == rhs));}
		template <class T, class Alloc>
			bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
				{ return std::lexicographical_compare(lhs.begin(), lhs.end(),
					rhs.begin(), rhs.end()); }
		template <class T, class Alloc>
			bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
				{ return (!(rhs < lhs));}
		template <class T, class Alloc>
			bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
				{ return (rhs < lhs);}
		template <class T, class Alloc>
			bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
				{ return (!(lhs < rhs));}
		//template <class T, class Alloc>
			//void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif /* ********************************************************** `VECTOR_HPP */
