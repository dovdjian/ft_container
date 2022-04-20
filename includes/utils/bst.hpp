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

template <class pair_type, class key_compare, class Alloc>
struct BST
{
	typedef typename	Alloc::template rebind<node>::other		allocator_type;
	typedef size_t size_type;
	struct node
	{
		node *_left_child;
		node *_right_child;
		node *_parent;
		int _depth;
		pair_type _data;

		node(pair_type new_pair) : _left_child(NULL), _right_child(NULL), _parent(NULL),
			_depth(1), _data(new_pair) {}
	};

	size_type		_size;
	key_compare		_cmp;
	allocator_type	_alloc;
	node			*_root;
	// CONSTRUCTOR
		// DEFAULT
			BST()
			{
				//std::cout << "construct default bst" << std::endl;
				this->_root = node(pair_type());
				this->_size = 0;
			}
		// COPY
			BST(const BST & src)
			{
				//std::cout << "construct copy bst" << std::endl;
				*this = src;
			}
	// DESTRUCTOR
		~BST()
		{
			//destroy_children();
		}
	// OPERATOR =
		BST & operator=(BST const & src)
		{
			//std::cout << "operator =" << std::endl;
			if (this != &src)
			{
				//std::cout << "bfr destroy children" << std::endl;
				//destroy_children();
				//std::cout << "after destroy children" << std::endl;
				this->_cmp = src._cmp;
				this->_size = src._size;
				//std::cout << "bfr left child" << std::endl;
				/* if (!this->_root)
				{
					this->_root = this->_alloc.allocate(1);
					this->_alloc.construct(this->_root, *src._root);
				} */
			}
			return (*this);
		}
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
					bidir_iterator(node *node) : _node(node) {}
			// DESTRUCTOR
				~bidir_iterator(){}
			// IMPLICIT CONVERSION
				operator bidir_iterator<const ite_T, true>() const
					{ return (bidir_iterator<const ite_T, true>(this->_node)); }
			// OPERATOR =
				bidir_iterator & operator=(bidir_iterator const & src)
				{
					if (this != &src)
						this->_node = src.getNode();
					return (*this);
				}
			// METHODS
				node *getNode() const { return (this->_node); }
				void	treeIncrement()
				{
					std::cout << "tree incr" << std::endl;
					node *ret = this->_node;

					if (ret->_right_child)
					{
						ret = ret->_right_child;
						while (ret->_left_child)
							ret = ret->_left_child;
					}
					else
					{
						node *new_parent = ret->_parent;

						while (ret == new_parent->_right_child)
						{
							ret = new_parent;
							new_parent = new_parent->_parent;
						}
						if (ret->_right_child != new_parent)
							ret = new_parent;
					}
					this->_node = ret;
				}
				void	treeDecrement()
				{
					//std::cout << "tree decr" << std::endl;
					node *ret = this->_node;

					if (ret->_left_child)
					{
						node *new_left = ret->_left_child;

						while (ret->_right_child)
							ret = ret->_right_child;
						ret = new_left;
					}
					else
					{
						node *new_parent = ret->_parent;

						while (ret == new_parent->_left_child)
						{
							ret = new_parent;
							new_parent = new_parent->_parent;
						}
						ret = new_parent;
					}
					this->_node = ret;
				}
			// ALL CATEGORIES
				bidir_iterator & operator++() // pre
				{
					std::cout << "dans preincr op" << std::endl;
					this->treeIncrement();
					return (*this);
				}
				bidir_iterator operator++(int) // post
				{
					bidir_iterator	ret = *this;

					this->operator++();
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
				reference operator*() const { return (this->_node->_data); }
				pointer operator->() const {
					//std::cout << "dabs const ->" << std::endl;
					return &(this->_node->_data); }
			// BIDIRECTIONAL
				bidir_iterator & operator--() // pre
				{
					this->treeDecrement();
					return (*this);
				}
				bidir_iterator operator--(int) // post
				{
					bidir_iterator	ret = *this;

					this->operator--();
					return (ret);
				}
			private:
				key_compare	_comp;
				node		*_node;
		};
	// My Typedef iterator
		typedef bidir_iterator<pair_type, false> iterator;
		typedef bidir_iterator<const pair_type, true> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	// METHOD ITERATOR
		iterator begin()
		{
			//std::cout << "size tree = " << this->_size << std::endl;
			if (this->_size == 0)
				return (this->end());
			return (iterator(this->find_start()));
		}
		iterator end()
		{
			return (iterator(NULL));
		}
		const_iterator begin() const
		{
			//std::cout << "size tree = " << this->_size << std::endl;
			if (this->_size == 0)
				return (this->end());
			return (const_iterator(this->find_start()));
		}
		const_iterator end() const
		{
			return (const_iterator(NULL));
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->end()));
		}
		reverse_iterator rend()
		{
			return (reverse_iterator(this->begin()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->begin()));
		}
	// METHODS
		node *create_node(pair_type const & new_pair)
		{
			//std::cout << "new_pair.first in create node\t=\t" << new_pair.first << std::endl;
			node *ret = this->_alloc.allocate(1);

			this->_alloc.construct(ret, node(new_pair));
			return (ret);
		}
		/* void	destroy_children()
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
		} */
		bool	compare(pair_type const & new_pair) const
		{
			node *new_node = search(new_pair);

			return (_cmp(new_pair.first, new_node->_data.first));
		}
		/* BST *rotateRight(BST *node)
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
		} */
		ft::pair<iterator, bool> insert(pair_type const & new_pair)
		{
			iterator it;
			bool	existed_bfr_insert;
			if (!this->search(new_pair))
			{
				this->insert_node(create_node(new_pair));
				//std::cout << "After insert node" << std::endl;
				it = iterator(this->_root);
				existed_bfr_insert = false;
			}
			else
			{
				//std::cout << "search existe !" << std::endl;
				it = iterator(this->_root);
				existed_bfr_insert = true;
			}
			//std::cout << "End of insert" << std::endl;
			return (ft::make_pair(it, existed_bfr_insert));
		}
		void	insert_node(node *new_node)
		{
			if (compare(new_node->_data)) //less = left
			{
				if (new_node->_left_child)
					this->insert_node(new_node->_left_child);
				else
					new_node->_left_child = create_node(new_node->_data);
			}
			else
			{
				if (new_node->_right_child)
					this->insert_node(new_node->_right_child);
				else
					new_node->_right_child = create_node(new_node->_data);
			}
			//this->_depth = std::max(getDepth(_left_child),
				//getDepth(_right_child)) + 1;
			//std::cout << "getBalanced_factor()\t=\t" << getBalanced_factor() << std::endl;
			//std::cout << "_data.first\t=\t" << _data.first << std::endl;
			//std::cout << "new_pair.first\t=\t" << new_pair.first << std::endl;
			this->_size++;
			//if (!is_balanced())
				//return (balance_bst(this->_data));
			//return (this); // initial
		}
		void	erase_node(pair_type const & new_pair)
		{
			node *new_node;

			new_node = this->search(new_pair);
			//std::cout << "new_pair\t=\t" << new_pair.first << std::endl;
			//std::cout << "data\t=\t" << _data.first << std::endl;
			if (compare(new_pair))
				new_node->_left_child->erase_node(new_pair);
			else if (new_pair.first > new_node->_data.first)
				new_node->_right_child->erase_node(new_pair);
			else
			{
				// 3 cases : 0, 1, 2 children
				// No child
				if (!new_node->_left_child && !new_node->_right_child)
				{
					std::cout << "no child" << std::endl;
					_alloc.destroy(this);
					//return (NULL);
					//this = NULL;
				}
				// One child
				else if (!new_node->_left_child)
				{
					std::cout << "right erase" << std::endl;
					node *tmp = new_node->_right_child;
					//this = this->_right_child;
					_alloc.destroy(tmp);
					// return (tmp);
				}
				else if (!new_node->_right_child)
				{
					std::cout << "left erase" << std::endl;
					node *tmp = new_node->_left_child;

					_alloc.destroy(tmp);
					//return (tmp);
				}
				// 2 children
				else
				{
					std::cout << "2 children" << std::endl;
					node *tmp = new_node->_right_child->find_start();

					new_node->_data.second = tmp->_data.second;
					std::cout << "seg" << std::endl;
					new_node->_right_child->erase_node(tmp->_data);
				}
			}
			this->_size--;
			//return (this);
		}
		iterator find(pair_type const & new_pair)
		{
			if (this->search(new_pair))
				return (iterator(this->_root));
			return (iterator(NULL));
		}
		const_iterator find(pair_type const & new_pair) const
		{
			if (this->search(new_pair))
				return (const_iterator(this->_root));
			return (const_iterator(NULL));
		}
		node *find_start() const
		{
			node *new_node = this->_root;

			while (new_node->_left_child)
				new_node = new_node->_left_child;
			return (new_node);
		}
		node *find_end() const
		{
			node *new_node = this->_root;

			while (new_node->_right_child)
				new_node = new_node->_right_child;
			return (new_node);
		}
		node	*search(pair_type const & new_pair) const
		{
			//std::cout << "new_pair.first = " << new_pair.first << std::endl;
			//std::cout << "allo" << std::endl;
			node *search_node = this->_root;

			if (search_node == NULL)
				return (NULL);
			else if (new_pair.first == search_node->_data.first)
				return (search_node);
			else if (compare(new_pair))
				return (search(search_node->_left_child->_data));
			else
				return (search(search_node->_right_child->_data));
			return (NULL);
		}
		/*bool	is_balanced()
		{
			int b_factor = getBalanced_factor();

			if (b_factor >= -1 && b_factor <= 1)
				return (true);
			return (false);
		}
		int	getDepth(node *node)
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
		} */
};

#endif
