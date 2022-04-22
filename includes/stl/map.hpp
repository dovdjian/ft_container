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
	template <class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<ft::pair<const Key, T> >
	> class map
	{
		public:
		// TYPEDEF
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef typename Alloc::reference reference;
			typedef typename Alloc::const_reference const_reference;
			typedef typename Alloc::pointer pointer;
			typedef typename Alloc::const_pointer const_pointer;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;
			typedef BST<value_type, key_compare, allocator_type> BST;
			typedef typename BST::iterator iterator;
			typedef typename BST::const_iterator const_iterator;
			typedef typename BST::reverse_iterator reverse_iterator;
			typedef typename BST::const_reverse_iterator const_reverse_iterator;
		// METHOD ITERATOR
			iterator	begin()
			{
				return (this->_tree.begin());
			}
			const_iterator	begin() const
			{
				return (this->_tree.begin());
			}
			iterator	end()
			{
				return (this->_tree.end());
			}
			const_iterator	end() const
			{
				return (this->_tree.end());
			}
			reverse_iterator	rbegin()
			{
				return (this->_tree.rbegin());
			}
			const_reverse_iterator	rbegin() const
			{
				return (this->_tree.rbegin());
			}
			reverse_iterator	rend()
			{
				return (this->_tree.rend());
			}
			const_reverse_iterator	rend() const
			{
				return (this->_tree.rend());
			}
		// CONSTRUCTOR
			// EMPTY
				explicit map(const key_compare & comp = key_compare(),
					const allocator_type & alloc = allocator_type())
				{
					//std::cout << "construct default map" << std::endl;
					this->_comp = comp;
					this->_alloc = alloc;
				}
			// RANGE
				template <class InputIterator>
				map(InputIterator first, InputIterator last,
					const key_compare & comp = key_compare(),
					const allocator_type & alloc = allocator_type())
					{
						//std::cout << "construct with pair" << std::endl;
						this->_comp = comp;
						this->_alloc = alloc;
						this->insert(first, last);
					}
			// COPY
				map(const map & x)
				{
					//std::cout << "construct copy" << std::endl;
					*this = x;
				}
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
					this->clear();
					this->_comp = src._comp;
					this->_alloc = src._alloc;
					this->insert(src.begin(), src.end());
				}
				return (*this);
			}
		// METHODS
			//CAPACITY
				bool empty() const { return (this->size() == 0 ? true : false); }
				size_type size() const { return (this->_tree.size()); }
				size_type max_size() const { return (this->_tree.max_size()); }
			// ELEMENT ACCESS
				mapped_type & operator[](const key_type & k)
				{
					return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
				}
			// MODIFIERS
				ft::pair<iterator, bool> insert(const value_type & val)
				{
					return (this->_tree.insert(val));
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
				void erase(iterator position)
				{
					this->_tree.erase_node(*position);
				}
				size_type erase(const key_type & k)
				{
					this->_tree.erase_node(ft::make_pair(k, mapped_type()));
					return (1);
				}
				void erase(iterator first, iterator last)
				{
					for (; first != last; ++first)
						this->_tree.erase_node(*first);
				}
				void swap(map & x)
				{
					key_compare		tmp_comp = this->_comp;
					allocator_type	tmp_alloc = this->_alloc;
					BST				tmp_tree = this->_tree;

					this->_comp = x._comp;
					this->_alloc = x._alloc;
					this->_tree = x._tree;

					x._comp = tmp_comp;
					x._alloc = tmp_alloc;
					x._tree = tmp_tree;
				}
				void clear()
				{
					this->_tree.clear();
				}
			// OBSERVERS
				key_compare key_comp() const
				{
					return (this->_comp);
				}
				class value_compare
				{
					friend class map;
					protected:
						Compare comp;
						value_compare(Compare c) : comp(c) {}
					public:
						bool operator()(const value_type & x, const value_type & y) const
						{
							return (comp(x.first, y.first));
						}
				};
				value_compare value_comp() const
				{
					return (value_compare(this->_comp));
				}
			// OPERATIONS
				iterator find(const key_type & k)
				{
					return (this->_tree.find(ft::make_pair(k, mapped_type())));
				}
				const_iterator find(const key_type & k) const
				{
					return (this->_tree.find(ft::make_pair(k, mapped_type())));
				}
				size_type count(const key_type & k) const
				{
					value_type v = ft::make_pair(k, mapped_type());

					if (this->_tree.search(v))
						return (1);
					return (0);
				}
				iterator lower_bound(key_type const & k)
				{
					iterator	it;

					for (it = this->begin(); it != this->end()
						&& this->_comp(it->first, k); ++it) {}
					return (it);
				}
				const_iterator lower_bound(key_type const & k) const
				{
					const_iterator	it;

					for (it = this->begin(); it != this->end()
						&& this->_comp(it->first, k) ; ++it) {}
					return (it);
				}
				iterator upper_bound(key_type const & k)
				{
					iterator	it;

					for (it = this->begin(); it != this->end()
						&& !this->_comp(k, it->first); ++it) {}
					return (it);
				}
				const_iterator upper_bound(key_type const & k) const
				{
					const_iterator	it;

					for (it = this->begin(); it != this->end()
						&& !this->_comp(k, it->first); ++it) {}
					return (it);
				}
				pair<iterator, iterator> equal_range(const key_type & k)
				{
					return (ft::make_pair(lower_bound(k), upper_bound(k)));
				}
				pair<const_iterator, const_iterator> equal_range(const key_type & k) const
				{
					return (ft::make_pair(lower_bound(k), upper_bound(k)));
				}

			// ALLOCATOR
				allocator_type	get_allocator() const { return (this->_alloc); }
		private:
			// VARIABLES
				key_compare		_comp;
				allocator_type	_alloc;
				BST				_tree; // laisser le ptr
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc> & lhs,
					const ft::map<Key, T, Compare, Alloc> & rhs)
		{ return (lhs.size() == rhs.size()
				&& ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc> & lhs,
					const ft::map<Key, T, Compare, Alloc> & rhs)
			{ return (!(lhs == rhs)); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key ,T, Compare, Alloc> & lhs,
				const ft::map<Key ,T, Compare, Alloc> & rhs)
		{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
			rhs.begin(), rhs.end())); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare,Alloc> & lhs,
					const ft::map<Key, T, Compare,Alloc> & rhs)
		{ return (!(rhs < lhs)); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc> & lhs,
				const ft::map<Key,T,Compare,Alloc> & rhs)
		{ return (rhs < lhs); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc> & lhs,
				const ft::map<Key, T, Compare, Alloc> & rhs)
		{ return (!(lhs < rhs)); }
	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> & lhs,
				ft::map<Key, T, Compare, Alloc> & rhs)
		{ lhs.swap(rhs); }
}

#endif /* ********************************************************** `MAP_HPP */
