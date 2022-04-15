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
	typedef size_t size_type;

	size_type		_size;
	pair_type		_data;
	key_compare		_cmp;
	allocator_type	_alloc;
	pointer			_left_child;
	pointer			_right_child;
	int				_depth;
	// CONSTRUCTOR
		// DEFAULT
			BST()
			{
				//std::cout << "construct default" << std::endl;
				this->_left_child = NULL;
				this->_right_child = NULL;
				this->_size = 0;
				this->_depth = 1; // ?
			}
		// PAIR
			BST(pair_type new_pair)
			{
				std::cout << "construct with pair" << std::endl;
				(void)new_pair;
				//std::cout << "new_pair.first\t=\t" << new_pair.first << std::endl;
				//this->_data = new_pair;
				this->_left_child = NULL;
				this->_right_child = NULL;
				this->_size = 0;
				this->_depth = 1; // ?
			}
		// COPY
			BST(const BST & src)
			{
				//std::cout << "construct copy" << std::endl;
				*this = src;
				/* this->_data = src._data;
				this->_cmp = src._cmp;
				this->_left_child = NULL;
				this->_right_child = NULL;
				this->_depth = src._depth; // ?
				this->_size = src._size;
				if (this->_left_child)
				{
					this->_left_child = this->_alloc.allocate(1);
					this->_alloc.construct(this->_left_child, *src._left_child);
				}
				if (this->_right_child)
				{
					this->_right_child = this->_alloc.allocate(1);
					this->_alloc.construct(this->_right_child, *src._right_child);
				} */
			}
	// DESTRUCTOR
		~BST()
		{
			destroy_children();
		}
	// OPERATOR =
		BST & operator=(BST const & src)
		{
			if (this != &src)
			{
				//*this = src;
				destroy_children();
				this->_cmp = src._cmp;
				//this->_data = src._data;
				this->_depth = src._depth;
				if (this->_left_child)
				{
					this->_left_child = this->_alloc.allocate(1);
					this->_alloc.construct(this->_left_child, *src._left_child);
				}
				if (this->_right_child)
				{
					this->_right_child = this->_alloc.allocate(1);
					this->_alloc.construct(this->_right_child, *src._right_child);
				}
			}
			return (*this);
		}
	// METHODS
		pointer create_node(pair_type const & new_pair)
		{
			pointer ret = this->_alloc.allocate(1);

			this->_alloc.construct(ret, BST(new_pair));
			return (ret);
		}
		void	destroy_children()
		{
			if (_left_child)
			{
				this->_alloc.destroy(_left_child);
				this->_alloc.deallocate(_left_child, 1);
				_left_child = NULL;
			}
			if (_right_child)
			{
				this->_alloc.destroy(_right_child);
				this->_alloc.deallocate(_right_child, 1);
				_right_child = NULL;
			}
		}
		bool	compare(pair_type const & new_pair)
			{ return (_cmp(new_pair.first, _data.first)); }
		BST *rotateRight(BST *node)
		{
			std::cout << "rright" << std::endl;
			std::cout << "node->_data.first\t=\t" << node->_data.first << std::endl;
			BST *ret = node->_left_child;
			node->_left_child= ret->_right_child;

			ret->_right_child = node;
			//node->_depth = std::max(getDepth(node->_left_child),
				//getDepth(node->_right_child)) + 1;
			_depth = std::max(getDepth(_left_child),
				getDepth(_right_child)) + 1;
			ret->_depth = std::max(getDepth(ret->_left_child),
				getDepth(ret->_right_child)) + 1;
			return (ret);
		}
		BST *rotateLeft(BST *node) // x
		{
			std::cout << "rleft" << std::endl;
			std::cout << "node->_data.first\t=\t" << node->_data.first << std::endl;
			BST *ret = node->_right_child;
			std::cout << "ret->_data.first\t=\t" << ret->_data.first << std::endl; // 20 ?
			node->_right_child = ret->_left_child;
			//std::cout << "node->_right_child->_data.first\t=\t" << node->_right_child->_data.first << std::endl; // 0

			ret->_left_child = node;
			std::cout << "ret->_left_child_data.first\t=\t" << ret->_left_child->_data.first << std::endl; // 20 ?
			ret->_depth = std::max(getDepth(ret->_left_child),
				getDepth(ret->_right_child)) + 1;
			//node->_depth = std::max(getDepth(node->_left_child),
				//getDepth(node->_right_child)) + 1;
			_depth = std::max(getDepth(_left_child),
				getDepth(_right_child)) + 1;
			std::cout << "node->depth" << node->_depth << std::endl; // 1 ?
			std::cout << "ret->depth" << ret->_depth << std::endl; // 0 ?
			return (ret);
		}
		BST	*balance_bst(pair_type const & new_pair)
		{
			std::cout << "getBalanced_factor()\t=\t" << getBalanced_factor() << std::endl;
			std::cout << "new_pair.first in balance bst\t=\t" << new_pair.first << std::endl;
			if (getBalanced_factor() > 1
				&& _left_child->compare(new_pair)) // RR
				return (rotateRight(this));
			if (getBalanced_factor() > 1
				&& !_left_child->compare(new_pair)) // RL
			{
				_left_child = rotateLeft(_left_child);
				return (rotateRight(this));
			}
			if (getBalanced_factor() < -1
				&& _right_child->compare(new_pair)) // LL
				return (rotateLeft(this));
			if (getBalanced_factor() < -1
				&& !_right_child->compare(new_pair)) // LR
			{
				_right_child = rotateRight(_right_child);
				return (rotateLeft(this));
			}
			return (this); // initial
		}
		void	insert_node(pair_type const & new_pair)
		{
			//std::cout << "new_pair.first\t=\t" << new_pair.first << std::endl;
			if (compare(new_pair)) //less = left
			{
				if (_left_child)
					_left_child->insert_node(new_pair);
				else
					_left_child = create_node(new_pair);
			}
			else
			{
				if (_right_child)
					_right_child->insert_node(new_pair);
				else
					_right_child = create_node(new_pair);
			}
			this->_depth = std::max(getDepth(_left_child),
				getDepth(_right_child)) + 1;
			//std::cout << "getBalanced_factor()\t=\t" << getBalanced_factor() << std::endl;
			//std::cout << "_data.first\t=\t" << _data.first << std::endl;
			//std::cout << "new_pair.first\t=\t" << new_pair.first << std::endl;
			this->_size++;
			//if (!is_balanced())
				//return (balance_bst(this->_data));
			//return (this); // initial
		}
		BST	*erase(pair_type const & new_pair)
		{
			//std::cout << "new_pair\t=\t" << new_pair.first << std::endl;
			//std::cout << "data\t=\t" << _data.first << std::endl;
			if (new_pair.first < _data.first)
				_left_child = _left_child->erase(new_pair);
			else if (new_pair.first > _data.first)
				_right_child = _right_child->erase(new_pair);
			else
			{
				// 3 cases : 0, 1, 2 children
				// No child
				if (!_left_child && !_right_child)
				{
					std::cout << "no child" << std::endl;
					//node->_alloc.destroy(node);
					return (NULL);
					//this = NULL;
				}
				// One child
				else if (!_left_child)
				{
					std::cout << "right erase" << std::endl;
					BST *tmp = _right_child;
					//this = this->_right_child;
					//_alloc.destroy(tmp);
					return (tmp);
				}
				else if (!_right_child)
				{
					std::cout << "left erase" << std::endl;
					BST *tmp = _left_child;

					//_alloc.destroy(tmp);
					return (tmp);
				}
				// 2 children
				else
				{
					BST *tmp = findMin(_right_child);

					_data = tmp->_data;
					_right_child = _right_child->erase(tmp->_data);
				}
			}
			this->_size--;
			return (this);
		}
		/* pointer	find_start()
		{
			if (this->_left_child)
				return (_left_child->find_start());
			else
				return (this);
		}
		pointer	find_end()
		{
			if (this->_right_child)
				return (_right_child->find_end());
			else
				return (this);
		} */
		BST	*findMin(BST *curr) const
		{
			while (curr->_left_child)
				curr = curr->_left_child;
			return (curr);
		}
		BST *treeIncrement()
		{
			BST *ret = this;

			if (ret->_right_child)
			{
				ret = ret->_right_child;
			}
			return (ret);
		}
		BST *treeDecrement()
		{
			BST *ret = this;

			if (ret->_left_child)
			{
				ret = ret->_left_child;
			}
			return (ret);
		}
		bool	search(pair_type const & new_pair) const
		{
			if (new_pair == this->_data)
				return (true);
			else if (new_pair < this->_data)
				return (search(_left_child->_data));
			else
				return (search(_right_child->_data));
			return (false);
		}
		bool	is_balanced()
		{
			int b_factor = getBalanced_factor();

			if (b_factor >= -1 && b_factor <= 1)
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
			//return (std::max(getDepth(_left_child),
				//getDepth(_right_child)) + 1);
			return (getDepth(_left_child) -
				getDepth(_right_child));
		}
};

#endif
