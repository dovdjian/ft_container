/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:22:31 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/29 14:05:29by dodjian          ###   ########.fr       */
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
	//typedef cmp_data value_compare;
	pair_type		_data;
	key_compare		_cmp;
	allocator_type	_alloc;
	pointer			_left_child;
	pointer			_right_child;
	int				_depth;
	// CONSTRUCTOR
		BST(pair_type const & new_pair, const key_compare & comp = key_compare())
		{
			_data = new_pair;
			_cmp = comp;
			_left_child = NULL;
			_right_child = NULL;
			_depth = 1; // ?
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
			{ return (_cmp(new_pair.first, _data.first)); }
		BST *rotateRight(BST *node)
		{
			BST *ret = node->_left_child;
			BST *tmp2 = ret->_right_child;

			ret->_right_child = node;
			node->_left_child = tmp2;

			node->_depth = std::max(getDepth(node->_left_child),
				getDepth(node->_right_child)) + 1;
			ret->_depth = std::max(getDepth(ret->_left_child),
				getDepth(ret->_right_child)) + 1;
			return (ret);
		}
		BST *rotateLeft(BST *node)
		{
			BST *ret = node->_right_child;
			BST *tmp2 = ret->_left_child;

			ret->_left_child = node;
			node->_right_child = tmp2;

			ret->_depth = std::max(getDepth(ret->_left_child),
				getDepth(ret->_right_child)) + 1;
			node->_depth = std::max(getDepth(node->_left_child),
				getDepth(node->_right_child)) + 1;
			return (ret);
		}
		BST	*balance_bst(pair_type const & new_pair)
		{
			std::cout << "in balance bst" << std::endl;
			if (getBalanced_factor() > 1
				&& _left_child->compare(new_pair)) // LL
				return (rotateRight(this));
			if (getBalanced_factor() > 1
				&& !_left_child->compare(new_pair)) // LR
			{
				_left_child = rotateLeft(_left_child);
				return (rotateRight(this));
			}
			if (getBalanced_factor() < -1
				&& _right_child->compare(new_pair)) // RR
				return (rotateLeft(this));
			if (getBalanced_factor() < -1
				&& !_right_child->compare(new_pair)) // RL
			{
				_right_child = rotateRight(_right_child);
				return (rotateLeft(this));
			}
			return (this); // initial
		}
		BST	*insert(pair_type const & new_pair)
		{
			if (compare(new_pair)) //less = left
			{
				if (_left_child)
					_left_child = _left_child->insert(new_pair);
				else
					_left_child = create_node(new_pair);
			}
			else
			{
				if (_right_child)
					_right_child = _right_child->insert(new_pair);
				else
					_right_child = create_node(new_pair);
			}
			_depth = 1 + std::max(getDepth(_left_child),
				getDepth(_right_child));
			if (!is_balanced(_depth))
				return (balance_bst(new_pair));
			return (this); // initial
		}
		bool	search(pair_type const & new_pair)
		{
			if (new_pair == this->_data)
				return (true);
			else if (new_pair < this->_data)
				return (search(_left_child->_data));
			else
				return (search(_right_child->_data));
			return (false);
		}
		bool	is_balanced(int depth)
		{
			std::cout << "depth\t=\t" << depth << std::endl;
			if (depth >= -1 && depth <= 1)
				return (true);
			return (false);
		}
		int	getDepth(BST *node)
		{
			if (node == NULL)
				return (0);
			return (node->_depth);
		}
		int getBalanced_factor()
		{
			return (getDepth(_left_child) -
				getDepth(_right_child));
		}
};

#endif
