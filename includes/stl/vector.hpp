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

#include "../utils/stl.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator <T> >
	class vector
	{
		public:
		// TYPEDEF
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename Alloc::reference reference;
			typedef typename Alloc::const_reference const_reference;
			typedef typename Alloc::pointer pointer;
			typedef typename Alloc::const_pointer const_pointer;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;
		// ITERATOR
			template <typename ite_T, bool is_const = false>
			class Iterator
			{
				public:
				// TYPEDEF
					typedef ite_T& reference;
					typedef ite_T* pointer;
					typedef ptrdiff_t difference_type;
					typedef size_t size_type;
				// CONSTRUCTOR
					// Default
						Iterator() : _ptr(NULL) {}
					// COPY CONSTRUCTIBLE
						Iterator(const Iterator & cpy)
						{
							*this = cpy;
						}
					// COPY ASSIGNABLE
						Iterator(pointer ptr) : _ptr(ptr) {}
				// DESTRUCTOR
					~Iterator(){}
				// IMPLICIT CONVERSION
					operator Iterator<const ite_T, true>() const
						{ return (Iterator<const ite_T, true>(this->_ptr)); }
				// OPERATOR =
					Iterator & operator=(Iterator const & src)
					{
						if (this != &src)
							this->_ptr = src.getPtr();
						return (*this);
					}
				// METHODS
					pointer		getPtr() const { return (this->_ptr); }
				// ALL CATEGORIES
					Iterator & operator++() // pre
					{
						_ptr++;
						return (*this);
					}
					Iterator operator++(int) // post
					{
						Iterator	ret = *this;
						_ptr++;
						return (ret);
					}
				// FORWARD
					bool operator==(Iterator<ite_T, false> const & v) const
						{ return (this->_ptr == v.getPtr()); }
					bool operator!=(Iterator<ite_T, false> const & v) const
						{ return (this->_ptr != v.getPtr()); }

					// CONST
						bool operator==(Iterator<const ite_T, true> const & v) const
							{ return (this->_ptr == v.getPtr()); }
						bool operator!=(Iterator<const ite_T, true> const & v) const
							{ return (this->_ptr != v.getPtr()); }
					reference operator*() { return (*this->_ptr); }
					pointer operator->() { return (this->_ptr); }
				// BIDIRECTIONAL
					Iterator & operator--() // pre
					{
						_ptr--;
						return (*this);
					}
					Iterator operator--(int) // post
					{
						Iterator	ret = *this;

						_ptr--;
						return (ret);
					}
				// RANDOM ACCESS
					Iterator operator+(difference_type const & val) const
						{ return (Iterator(this->_ptr + val)); }
					difference_type operator+(Iterator<ite_T, false> const & it) const
						{ return (this->_ptr + it.getPtr()); }
					Iterator operator-(difference_type const & val) const
						{ return (Iterator(this->_ptr - val)); }
					difference_type operator-(Iterator<ite_T, false> const & it) const
						{ return (this->_ptr - it.getPtr()); }
					bool operator<(Iterator<ite_T, false> const & it) const
						{ return (this->_ptr < it.getPtr()); }
					bool operator>(Iterator<ite_T, false> const & it) const
						{ return (this->_ptr > it.getPtr()); }
					bool operator<=(Iterator<ite_T, false> const & it) const
						{ return (this->_ptr <= it.getPtr()); }
					bool operator>=(Iterator<ite_T, false> const & it) const
						{ return (this->_ptr >= it.getPtr()); }
					// CONST
						difference_type operator+(Iterator<const ite_T, true> const & it) const
							{ return (this->_ptr + it.getPtr()); }
						difference_type operator-(Iterator<const ite_T, true> const & it) const
							{ return (this->_ptr - it.getPtr()); }
						bool operator<(Iterator<const ite_T, true> const & it) const
							{ return (this->_ptr < it.getPtr()); }
						bool operator>(Iterator<const ite_T, true> const & it) const
							{ return (this->_ptr > it.getPtr()); }
						bool operator<=(Iterator<const ite_T, true> const & it) const
							{ return (this->_ptr <= it.getPtr()); }
						bool operator>=(Iterator<const ite_T, true> const & it) const
							{ return (this->_ptr >= it.getPtr()); }
					Iterator operator+=(difference_type const & val)
						{ return (Iterator(this->_ptr += val)); }
					Iterator operator-=(difference_type const & val)
						{ return (Iterator(this->_ptr -= val)); }
					reference operator[] (difference_type n) const
						{ return (this->_ptr[n]); }
				private:
					pointer			_ptr;
			};
		// OVERLOAD +
			template<typename ite_T, bool is_const >
				friend Iterator<ite_T, is_const> operator+(
					typename Iterator<ite_T, is_const>::difference_type const & lhs,
						Iterator<ite_T, is_const> const & rhs )
			{
				return (Iterator<ite_T, is_const>(rhs + lhs));
			}
		// My Typedef iterator
			typedef Iterator<T, false> iterator;
			typedef Iterator<const T, true> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		// METHOD ITERATOR
			iterator begin() { return (iterator(this->_elements)); }
			iterator end() { return (iterator(this->_elements + this->_size)); }
			const_iterator begin() const { return (const_iterator(this->_elements)); }
			const_iterator end() const { return (const_iterator(this->_elements + this->_size));}
			reverse_iterator rbegin() { return (reverse_iterator(this->end())); }
			reverse_iterator rend() { return (reverse_iterator(this->begin())); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->end())); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }
		// CONSTRUCTOR
			// DEFAULT
				explicit vector(const allocator_type & alloc = allocator_type())
				{
					this->_alloc = alloc;
					this->_size = 0;
					this->_capacity = 0;
					this->_elements = this->_alloc.allocate(0);
				}
			// FILL
				explicit vector(size_type n, const value_type & val = value_type(),
					const allocator_type & alloc = allocator_type())
				{
					this->_alloc = alloc;
					this->_size = 0;
					this->_capacity = 0;
					this->_elements = NULL;
					this->resize(n, val);
				}
			// RANGE
				template <class Iterator>
					vector(Iterator first, Iterator last,
						const allocator_type & alloc = allocator_type(),
							typename ft::enable_if<!ft::is_integral<Iterator>::value>::type* = 0)
				{
					this->_alloc = alloc;
					this->_size = 0;
					this->_capacity = 0;
					this->_elements = NULL;
					this->assign(first, last);
				}
			// COPY
				vector(const vector & src)
				{
					this->_alloc = src._alloc;
					this->_elements = this->_alloc.allocate(src.capacity());
					this->_capacity = src.capacity();
					this->_size = src.size();
					for (size_type i = 0 ; i < src.size() ; i++)
					{
						this->_alloc.construct(this->_elements + i, src[i]);
						//this->_elements[i] = src._elements[i];
					}
				}
		// DESTRUCTOR
			~vector()
			{
				clear();
				this->_alloc.deallocate(this->_elements, this->_capacity);
			}
		// =
			vector &		operator=(const vector & src)
			{
				if (this != &src)
				{
					clear();
					reserve(src._size);
					for (size_type i = 0; i < src.size(); i++)
						this->_alloc.construct(this->_elements + i, src[i]);
					this->_size = src.size();
				}
				return (*this);
			}
		// METHODS
			//CAPACITY
				size_type size() const { return (this->_size); }
				size_type max_size() const { return (this->_alloc.max_size()) ;}
				void resize(size_type n, value_type val = value_type())
				{
					if (n < size())
					{
						for (size_type i = n; i < size(); ++i)
							_alloc.destroy(this->_elements + i);
						this->_size = n;
					}
					else if (n > size())
					{
						if (n > capacity() * 2)
							reserve(n);
						else if (n > capacity())
							reserve(this->_capacity * 2);
						for (size_type i = size(); i < n; ++i)
						{
							this->_size++;
							_alloc.construct(this->_elements + i, val);
						}
					}
				}
				size_type capacity() const { return (this->_capacity); }
				bool empty() const { return (this->size() == 0 ? true : false); }
				void reserve(size_type n)
				{
					if (n > this->capacity())
					{
						value_type *new_mem = _alloc.allocate(n);
						for (size_type i = 0; i < size(); ++i)
						{
							_alloc.construct(new_mem + i, this->_elements[i]);
							_alloc.destroy(this->_elements + i);
						}
						this->_capacity = n;
						this->_elements = new_mem;
					}
					if (n > this->max_size())
						throw (std::length_error("n greater than max_size"));
				}
			// ELEMENT ACCESS
				reference operator[](size_type n)
				{
					return *(this->_elements + n);
				}
				const_reference operator[](size_type n) const
				{
					return *(this->_elements + n);
				}
				reference at(size_type n)
				{
					if (n > this->size())
						throw (std::out_of_range("n greater than max_size"));
					return (this->_elements[n]);
				}
				const_reference at(size_type n) const
				{
					if (n > this->size())
						throw (std::out_of_range("n greater than max_size"));
					return (this->_elements[n]);
				}
				reference front()
					{ return (this->_elements[0]); }
				const_reference front() const
					{ return (this->_elements[0]); }
				reference back()
					{ return (this->_elements[size() - 1]); }
				const_reference back() const
					{ return (this->_elements[size() - 1]); }
			// MODIFIERS
				template <class InputIterator>
				void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
				{
					erase(begin(), end());
					insert(begin(), first, last);
				}
				void assign(size_type n, const value_type & val)
				{
					erase(begin(), end());
					insert(begin(), n, val);
				}
				void push_back(const value_type & val)
				{
					if (this->_capacity == 0)
						reserve(1);
					else if (this->_size == this->_capacity)
						reserve(this->_capacity * 2);
					this->_alloc.construct(this->_elements + this->_size, val);
					this->_size++;
				}
				void pop_back()
				{
					if (this->_size > 0)
					{
						this->_alloc.destroy(this->_elements + size() - 1);
						this->_size--;
					}
					if (this->_size == this->_capacity / 2)
						this->_capacity /= 2;
				}
				iterator insert(iterator position, const value_type & val)
				{
					size_type start = position - this->begin();

					insert(position, 1, val);
					return (iterator(begin() + start));
				}
				void insert(iterator position, size_type n, const value_type & val)
				{
					size_type	start = position - begin();

					if (n + size() > capacity() * 2)
						reserve(n + size());
					else if (n + size() > capacity())
						reserve(capacity() * 2);

					for (size_type i = 0 ; i < n ; ++i)
						this->_alloc.construct(this->_elements + i + size(), val);
					for (size_type i = size() + n ; i > start + n ; --i)
						this->_elements[i - 1] = this->_elements[i - n - 1];
					for (size_type i = 0 ; i < n ; ++i)
						this->_elements[i + start] = val;
					this->_size += n;
				}
				template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
				{
					size_type	start = position - begin();
					size_type	n = 0;
					InputIterator it;

					for (it = first ; it != last ; n++, it++) {}
					if (n + size() > capacity() * 2)
						reserve(n + size());
					else if (n + size() > capacity())
						reserve(capacity() * 2);

					it = first;
					for (size_type i = 0 ; i < n ; ++i, ++it)
						this->_alloc.construct(this->_elements + i + size(), *it);
					for (size_type i = size() + n ; i > start + n ; --i)
						this->_elements[i - 1] = this->_elements[i - n - 1];
					for (size_type i = 0 ; i < n ; ++i, ++first)
						this->_elements[i + start] = *first;
					this->_size += n;
				}
				iterator erase(iterator position)
				{
					return (erase(position, position + 1));
				}
				iterator erase(iterator first, iterator last)
				{
					size_type begin = first - this->begin();
					size_type end = last - this->begin();
					size_type i;

					for (i = begin ; (i - begin) + end < size() ; i++)
						this->_elements[i] = this->_elements[(i - begin) + end];
					for (i = size() - end + begin ; i < size() ; i++)
						this->_alloc.destroy(this->_elements + i);
					this->_size = size() - end + begin;
					return (iterator(this->begin() + begin));
				}
				void swap(vector & x)
				{
					size_type tmp_size = this->_size;
					size_type tmp_capa = this->_capacity;
					value_type *tmp_elem = this->_elements;

					this->_size = x._size;
					this->_capacity = x._capacity;
					this->_elements = x._elements;

					x._size = tmp_size;
					x._capacity = tmp_capa;
					x._elements = tmp_elem;
				}
				void clear()
				{
					for (size_t i = 0; i < size(); ++i)
						_alloc.destroy(this->_elements + i);
					this->_size = 0;
				}
			// Allocator
				allocator_type	get_allocator() const { return (this->_alloc); }
		private:
			// VARIABLES
				allocator_type	_alloc;
				size_type		_capacity;	// allocate size of container
				size_type		_size;		// nbr elements in container
				value_type		*_elements;	// elements in container
	};
	// Non member function overload
		template <class T, class Alloc>
		bool operator==(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
			{ return (lhs.size() == rhs.size()
				&& ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }
		template <class T, class Alloc>
			bool operator!=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
			{ return (!(lhs == rhs)); }
		template <class T, class Alloc>
		bool operator<(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
			{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
				rhs.begin(), rhs.end())); }
		template <class T, class Alloc>
		bool operator<=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
			{ return (!(rhs < lhs)); }
		template <class T, class Alloc>
		bool operator>(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
			{ return (rhs < lhs); }
		template <class T, class Alloc>
		bool operator>=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
			{ return (!(lhs < rhs)); }
		template <class T, class Alloc>
		void swap(vector<T, Alloc> & x, vector<T, Alloc> & y)
			{ x.swap(y); }
}

#endif /* ********************************************************** `VECTOR_HPP */
