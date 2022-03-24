/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:22:31 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/24 17:51:43 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

#include "stl.hpp"

template <class pair_type, class key_compare>
struct BST
{
	typedef typename std::allocator<BST<pair_type, key_compare> > allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	//typedef cmp_elem value_compare;
	pair_type		_elem;
	key_compare		_cmp;
	allocator_type	_alloc;
	pointer			_left_child;
	pointer			_right_child;
	// CONSTRUCTOR
		BST(pair_type const & new_pair, const key_compare & comp = key_compare())
		: _elem(new_pair)
		{
			_left_child = NULL;
			_right_child = NULL;
		}
	// DESTRUCTOR
		~BST()
		{
		/* 	if (_left_child)
				_alloc.destroy(_left_child);
			if (_right_child)
				_alloc.destroy(_right_child);
			if (*this)
				_alloc.destroy(*this); */
		}
	// METHODS
		pointer create_node(pair_type const & new_pair)
		{
			pointer ret = _alloc.allocate(1);

			_alloc.construct(ret, BST(new_pair));
			return (ret);
		}
		bool	compare(pair_type const & new_pair)
			{ return (_cmp(new_pair.first, _elem.first)); }
		void	insert(pair_type const & new_pair)
		{
			if (compare(new_pair)) // less
			{
				if (_left_child)
					_left_child->insert(_left_child->_elem);
				else
					_left_child = create_node(new_pair);
			}
			else
			{
				if (_right_child)
					_right_child->insert(_right_child->_elem);
				else
					_right_child = create_node(new_pair);
			}
		}
};

#endif
