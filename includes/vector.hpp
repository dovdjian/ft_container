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
		class Const_iterator;

	template <class T, class Alloc = std::allocator <T> >
	class vector
	{
		public:
		// Typedef
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename Alloc::size_type size_type;
			typedef typename Alloc::difference_type difference_type;
			typedef typename Alloc::reference reference;
			typedef typename Alloc::const_reference const_reference;
			typedef typename Alloc::pointer pointer;
			typedef typename Alloc::const_pointer const_pointer;
		// make the iterator a friend
			friend class Iterator <value_type, Alloc >;
			//friend class Const_iterator <value_type, Alloc >;
		// Iterator
			class Iterator : public std::iterator<std::input_iterator_tag, value_type>
			{
				public:
				// Constructor
					// Default
						//Iterator();
					Iterator(vector & src, size_type size)
					: _vector(src), _size(size)
					{

					}
					~Iterator();
				private:
					vector <value_type, Alloc> & _vector;
					size_type _size;
			};
		// Const_iterator
			/* class Const_iterator : public std::iterator<std::input_iterator_tag, value_type>
			{
				public:
				// Constructor
					// Default
						//Iterator();
					Const_iterator(vector & src, size_type size)
					: _vector(src), _size(size)
					{

					}
					~Const_iterator();
				private:
					vector <value_type, Alloc> & _vector;
					size_type _size;
			}; */
		// Typedef iterator
			typedef vector::Iterator iterator;
			//typedef vector::Const_iterator const_iterator;
			typedef vector::Iterator reverse_iterator;
			//typedef vector::Const_iterator const_reverse_iterator;
		// Method Iterator
			iterator begin() { return (iterator(*this, 0));}
			iterator end() { return (iterator(*this, this->_nbr_elements));}
			//const_iterator begin() { return (const_iterator(*this, 0)); const}
			//const_iterator end() { return (const_iterator(*this, this->_nbr_elements)); const}
			reverse_iterator rbegin() { return (reverse_iterator(*this, 0));}
			reverse_iterator rend() { return (reverse_iterator(*this, this->_nbr_elements));}
			//const_reverse_iterator rbegin() { return (const_reverse_iterator(*this, 0)); const}
			//const_reverse_iterator rend() { return (const_reverse_iterator(*this, this->_nbr_elements)); const}
		// Constructor
			// Default
				explicit vector (const allocator_type &alloc = allocator_type())
				: _alloc(alloc) ,_capacity(0), _nbr_elements(0)
				{
				}
			// Fill
				explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _capacity(n), _nbr_elements(n)
				{
					if (n == 0)
						this->_elements = NULL;
					else
						this->_elements = new value_type[n];
					for (size_type i = 0; i < n; i++)
						this->_elements[i] = val;
				}
			// Range
				/* template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator &alloc = allocator())
				:
				{

				} */
			// Copy
				vector (const vector &src) { *this = src; }
		// Destructor
			~vector()
			{
				if (this->_elements)
					delete[] this->_elements;
			}
		// Operator =, []
			/* vector &		operator=(const vector &src)
			{
				*this = src;
			} */
			//reference		operator[] (size_type n){}
			//const_reference	operator[] (size_type n) const{}
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
			allocator_type _alloc;
			size_type _capacity; // allocate size of container
			size_type _nbr_elements; // nbr elements in container
			value_type	*_elements; // elements in container
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

			reverse_iterator rbegin() { return (reverse_iterator(*this, 0));}
			reverse_iterator rend() { return (reverse_iterator(*this, this->_nbr_elements));}
		// Constructor
			// Default
				explicit vector (const allocator_type &alloc = allocator_type())
				: _alloc(alloc) ,_capacity(0), _nbr_elements(0)
				{
				}
			// Fill
				explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _capacity(n), _nbr_elements(n)
				{
					if (n == 0)
						this->_elements = NULL;
					else
						this->_elements = new value_type[n];
					for (size_type i = 0; i < n; i++)
						this->_elements[i] = val;
				}
			// Range
				/* template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator &alloc = allocator())
				:
				{

				} */
			// Copy
				vector (const vector &src) { *this = src; }
		// Destructor
			~vector()
			{
				if (this->_elements)
					delete[] this->_elements;
			}
		// Operator =, []
			/* vector &		operator=(const vector &src)
			{
				*this = src;
			} */
			//reference		operator[] (size_type n){}
			//const_reference	operator[] (size_type n) const{}
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
			allocator_type _alloc;
			size_type _capacity; // allocate size of container
			size_type _nbr_elements; // nbr elements in container
			value_type	*_elements; // elements in container
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
