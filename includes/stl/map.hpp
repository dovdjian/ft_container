/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:26:27 by dodjian           #+#    #+#             */
/*   Updated: 2021/12/24 20:53:37by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
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
	template < class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<pair<const Key, T> >
	> class map
	{
		public:
		// TYPEDEF
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const Key, T> value_type;
			typedef Compare key_compare;
			//typedef cmp_elem value_compare;
			typedef Alloc allocator_type;
			typedef typename Alloc::reference reference;
			typedef typename Alloc::const_reference const_reference;
			typedef typename Alloc::pointer pointer;
			typedef typename Alloc::const_pointer const_pointer;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;
			typedef BST<value_type, key_compare> BST;
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
						Iterator() : _node(NULL) {}
					// COPY CONSTRUCTIBLE
						Iterator(const Iterator & cpy)
						{
							*this = cpy;
						}
					// COPY ASSIGNABLE
						Iterator(BST *node) : _node(node) {}
				// DESTRUCTOR
					~Iterator(){}
				// IMPLICIT CONVERSION
					operator Iterator<const ite_T, true>() const
						{ return (Iterator<const ite_T, true>(this->_node)); }
				// OPERATOR =
					Iterator & operator=( Iterator const & src)
					{
						if (this != &src)
							this->_node = src._node;
						return (*this);
					}
				// METHODS
					//pointer		getPtr() const { return (this->_node); }
				// ALL CATEGORIES
					Iterator & operator++() // pre
					{
						_node++;
						return (*this);
					}
					Iterator operator++(int) // post
					{
						Iterator	ret = *this;
						_node++;
						return (ret);
					}
				// FORWARD
					bool operator==(Iterator<ite_T, false> const & v) const
						{ return (this->_node == v._node); }
					bool operator!=(Iterator<ite_T, false> const & v) const
						{ return (this->_node != v._node); }

					// CONST
						bool operator==(Iterator<const ite_T, true> const & v) const
							{ return (this->_node == v._node); }
						bool operator!=(Iterator<const ite_T, true> const & v) const
							{ return (this->_node != v._node); }
					reference operator*() { return (*this->_node->_data); }
					pointer operator->() { return (this->_node->_data); }
				// BIDIRECTIONAL
					Iterator & operator--() // pre
					{
						_node--;
						return (*this);
					}
					Iterator operator--(int) // post
					{
						Iterator	ret = *this;

						_node--;
						return (ret);
					}
				private:
					key_compare _comp;
					BST*		_node;
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
			iterator begin() { return (this->_tree.begin()); }
			iterator end() { return (iterator(this->_elements + this->_size)); }
			const_iterator begin() const { return (const_iterator(this->_elements)); }
			const_iterator end() const { return (const_iterator(this->_elements + this->_size));}
			reverse_iterator rbegin() { return (reverse_iterator(this->end())); }
			reverse_iterator rend() { return (reverse_iterator(this->begin())); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->end())); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }
		// CONSTRUCTOR
			// EMPTY
			explicit map(const key_compare & comp = key_compare(),
					const allocator_type & alloc = allocator_type())
				{
					this->_comp = comp;
					this->_alloc = alloc;
				}
			// RANGE
				template <class InputIterator>
				map(InputIterator first, InputIterator last,
					const key_compare & comp = key_compare(),
					const allocator_type & alloc = allocator_type())
					{
						this->_comp = comp;
						this->_alloc = alloc;
						this->insert(first, last);
					}
			// COPY
				map(const map & x) { *this = x;}
		// DESTRUCTOR
			~map()
			{
				//clear();
				//this->_alloc.deallocate(this->_elements, this->_capacity);
			}
		// =
			map &		operator=(const map & src)
			{
				if (this != &src)
				{
					this->_tree = src._tree;
				}
				return (*this);
			}
		// METHODS
			//CAPACITY
				bool empty() const { return (this->size() == 0 ? true : false); }
				size_type size() const { return (this->_size); }
				size_type max_size() const { return (this->_alloc.max_size()) ;}
			// ELEMENT ACCESS
				/* reference operator[](size_type n)
				{
					return *(this->_elements + n);
				}
				const_reference operator[](size_type n) const
				{
					return *(this->_elements + n);
				}
			// MODIFIERS
				pair<iterator, bool> insert(const value_type & val);
				{

				}
				void insert(iterator position, const value_type & val)
				{

				}
				template <class InputIterator>
				void insert(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
				{

				}
				void erase(iterator position)
				{
				}
				size_type erase(const key_type & k)
				{
				}
				void erase(iterator first, iterator last)
				{
					size_type begin = first - this->begin();
					size_type end = last - this->begin();
					size_type i;

					for (i = begin ; (i - begin) + end < size() ; i++)
						this->_elements[i] = this->_elements[(i - begin) + end];
					for (i = size() - end + begin ; i < size() ; i++)
						this->_alloc.destroy(this->_elements + i);
					this->_size = size() - end + begin;
				}
				void swap(map & x)
				{

				}
				void clear()
				{

				}
			// OBSERVERS
				key_compare key_comp() const {}
				value_compare value_comp() const {} */

			// Allocator
				allocator_type	get_allocator() const { return (this->_alloc); }
		private:
			// VARIABLES
				key_compare		_comp;
				allocator_type	_alloc;
				BST				_tree;
				//size_type		_key;
				//value_compare	_value;
	};
}

#endif /* ********************************************************** `MAP_HPP */
