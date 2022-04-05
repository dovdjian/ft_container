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
	class Alloc = std::allocator<ft::pair<const Key, T> >
	> class map
	{
		public:
		// TYPEDEF
			typedef Key key_type;
			typedef T mapped_type;
			typedef std::pair<const key_type, mapped_type> value_type;
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
			class bidir_iterator
			{
				public:
				// TYPEDEF
					typedef ite_T& reference;
					typedef ite_T* pointer;
					typedef ptrdiff_t difference_type;
					typedef size_t size_type;
				// CONSTRUCTOR
					// Default
						bidir_iterator() : _node(NULL) {}
					// COPY CONSTRUCTIBLE
						bidir_iterator(const bidir_iterator & cpy)
						{
							*this = cpy;
						}
					// COPY ASSIGNABLE
						bidir_iterator(BST *node) : _node(node) {}
				// DESTRUCTOR
					~bidir_iterator(){}
				// IMPLICIT CONVERSION
					operator bidir_iterator<const ite_T, true>() const
						{ return (bidir_iterator<const ite_T, true>(this->_node)); }
				// OPERATOR =
					bidir_iterator & operator=( bidir_iterator const & src)
					{
						if (this != &src)
							this->_node = src._node;
						return (*this);
					}
				// METHODS
					pointer		getNode() const { return (this->_node); }
				// ALL CATEGORIES
					bidir_iterator & operator++() // pre
					{
						_node++;
						return (*this);
					}
					bidir_iterator operator++(int) // post
					{
						bidir_iterator	ret = *this;
						_node++;
						return (ret);
					}
				// FORWARD
					bool operator==(bidir_iterator<ite_T, false> const & v) const
						{ return (this->_node == v.getNode()); }
					bool operator!=(bidir_iterator<ite_T, false> const & v) const
						{ return !(this->_node == v.getNode()); }
					// CONST
						bool operator==(bidir_iterator<const ite_T, true> const & v) const
							{ return (this->_node == v.getNode()); }
						bool operator!=(bidir_iterator<const ite_T, true> const & v) const
							{ return !(this->_node == v.getNode()); }
					reference operator*() const { return (*this->_node); }
					pointer operator->() const { return (this->_node); }
				// BIDIRECTIONAL
					bidir_iterator & operator--() // pre
					{
						_node--;
						return (*this);
					}
					bidir_iterator operator--(int) // post
					{
						bidir_iterator	ret = *this;

						_node--;
						return (ret);
					}
				private:
					key_compare _comp;
					pointer		_node;
			};
		// My Typedef iterator
			typedef bidir_iterator<T, false> iterator;
			typedef bidir_iterator<const T, true> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		// METHOD ITERATOR
			iterator begin()
			{
				if (this->_tree._size == 0)
					return (this->end());
				return (iterator(this->_tree[0]));
			}
			iterator end()
			{
				return (iterator(NULL));
			}
			/*const_iterator begin() const
			{
				if (this._tree->_size == 0)
					return (NULL);
				return (const_iterator(this._tree));
			}
			const_iterator end() const
			{
				return (const_iterator(NULL));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(this._tree.end()));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(this._tree.begin()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this._tree.end()));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this._tree.begin()));
			} */
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
				size_type size() const { return (this->_tree._size); }
				//size_type max_size() const { return (std::distance(this->begin(), this->end())); }
			// ELEMENT ACCESS
				mapped_type & operator[](const key_type & k)
				{
					//ft::pair<key_type, mapped_type> a = ft::make_pair(k, mapped_type());

					//return (this->insert(a.first)->second);
					// version of cpp
					return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
				}
			// MODIFIERS
				ft::pair<iterator, bool> insert(const value_type & val)
				{
					iterator it;
					bool	existed_bfr_insert;

					if (!this->_tree.search(val))
					{
						this->_tree.insert(this->_tree.create_node(val));
						//this->_tree.insert(val);
						it = iterator(this->_tree.search(val));
						existed_bfr_insert = true;
					}
					else
					{
						it = iterator(this->_tree.search(val));
						existed_bfr_insert = false;
					}
					return (ft::make_pair(it, existed_bfr_insert));
				}
				iterator insert(iterator position, const value_type & val)
				{
					static_cast<void>(position);
					return (this->insert(val).first);
				}
				template <class InputIterator>
				void insert(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
				{
					for (; first != last; ++first)
						this->insert(*first);
				}
				/*
				void erase(iterator position)
				{
					this->_tree->erase(position);
				}
				size_type erase(const key_type & k)
				{
					//this->_tree->erase(position);
				}
				void erase(iterator first, iterator last)
				{

				}
				void swap(map & x)
				{

				}
				void clear()
				{
					//erase(begin(), end());
					//this->_tree._size = 0;
				}
			// OBSERVERS
				key_compare key_comp() const {}
				value_compare value_comp() const {}

			// OPERATIONS
				iterator find (const key_type& k);
				const_iterator find (const key_type& k) const;
				size_type count (const key_type& k) const;
				iterator lower_bound (const key_type& k);
				const_iterator lower_bound (const key_type& k) const;
				iterator upper_bound (const key_type& k);
				const_iterator upper_bound (const key_type& k) const;
				pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
				pair<iterator,iterator>             equal_range (const key_type& k);*/

			// ALLOCATOR
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
