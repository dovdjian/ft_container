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
	// TYPEDEF
		typedef size_t size_type;
		typedef typename	Alloc::template rebind<node>::other		allocator_type;

	// VARIABLES
		size_type		_size;
		key_compare		_cmp;
		allocator_type	_alloc;
		node			*_root;
	// CONSTRUCTOR
		// DEFAULT
			BST()
			{
				//std::cout << "construct default bst" << std::endl;
				node null_node((pair_type()));

				null_node._left_child = NULL;
				null_node._right_child = NULL;
				null_node._parent = NULL;

				this->_root = NULL;
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
			this->destroy_tree(this->_root);
			//destroy_children();
		}
	// OPERATOR =
		BST & operator=(BST const & src)
		{
			//std::cout << "operator =" << std::endl;
			if (this != &src)
			{
				this->_alloc = src._alloc;
				this->_cmp = src._cmp;
				this->_size = src._size;
				this->_root = src._root;
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
						this->_node = src._node;
						//this->_node = src.getNode();
					return (*this);
				}
			// METHODS
				node *getNode() const { return (this->_node); }
				void	treeIncrement()
				{
					//std::cout << "tree incr" << std::endl;
					if (this->_node->_right_child)
					{
						this->_node = this->_node->_right_child;
						while (this->_node->_left_child)
							this->_node = this->_node->_left_child;
					}
					else
					{
						node *new_parent = this->_node->_parent;

						while (new_parent)
						{
							if (this->_comp(new_parent->_data.first, this->_node->_data.first))
								break ;
							std::cout << new_parent->_right_child->_data.first << std::endl;
							//std::cout << ret->_data.first << std::endl;
							//this->_node = new_parent;
							new_parent = new_parent->_parent;
							//std::cout << "lol" << std::endl;
							//std::cout << new_parent->_right_child->_data.first << std::endl;
							//std::cout << ret->_data.first << std::endl;
						}
						//std::cout << "lol" << std::endl;
						this->_node = NULL;
						return ;
					}
					//std::cout << "end of tree incr" << std::endl;
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
					//std::cout << "dans preincr op" << std::endl;
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
				pointer operator->() const { return (&this->_node->_data); }
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
		size_type size() const { return (this->_size); }
		size_type max_size() const { return (this->_alloc.max_size()); }
		node *create_node(pair_type const & new_pair)
		{
			//std::cout << "in create node" << std::endl;
			//std::cout << "new_pair.first in create node\t=\t" << new_pair.first << std::endl;
			node *ret = this->_alloc.allocate(1);

			this->_alloc.construct(ret, node(new_pair));
			return (ret);
		}
		void	clear()
		{
			this->destroy_tree(this->_root);
			this->_size = 0;
			this->_root = NULL;
		}
		void	destroy_tree(node *del_node)
		{
			if (!del_node)
				return ;
			if (del_node->_left_child)
			{
				this->_alloc.destroy(del_node->_left_child);
				this->_alloc.deallocate(del_node->_left_child, 1);
				del_node->_left_child = NULL;
			}
			if (del_node->_right_child)
			{
				this->_alloc.destroy(del_node->_right_child);
				this->_alloc.deallocate(del_node->_right_child, 1);
				del_node->_right_child = NULL;
			}
			this->_alloc.destroy(del_node);
			this->_alloc.deallocate(del_node, 1);
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
			if (this->search(new_pair))
			{
				it = iterator(this->search(new_pair));
				//std::cout << "After ite->root" << std::endl;
				existed_bfr_insert = false;
			}
			else
			{
				this->insert_node(this->create_node(new_pair));
				//std::cout << "search existe !" << std::endl;
				it = iterator(this->search(new_pair));
				existed_bfr_insert = true;
			}
			//std::cout << "End of insert" << std::endl;
			return (ft::make_pair(it, existed_bfr_insert));
		}
		void	insert_node(node *node_arg)
		{
			node *new_root = this->_root;
			node *y = NULL;

			while (new_root)
			{
				y = new_root;
				if (this->_cmp(node_arg->_data.first, new_root->_data.first))
					new_root = new_root->_left_child;
				else
					new_root = new_root->_right_child;
			}
			node_arg->_parent = y;
			if (!y)
				this->_root = node_arg;
			else if (this->_cmp(node_arg->_data.first, y->_data.first))
				y->_left_child = node_arg;
			else
				y->_right_child = node_arg;
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
		void	erase_node(node *new_node)
		{
			//std::cout << "new_pair\t=\t" << new_pair.first << std::endl;
			//std::cout << "data\t=\t" << _data.first << std::endl;
			node *curr = this->_root;
			node *prev = NULL;

			while (curr && curr->_data.first != new_node->_data.first)
			{
				prev = curr;
				if (this->_cmp(new_node->_data.first, curr->_data.first))
					curr = curr->_left_child;
				else
					curr = curr->_right_child;
			}
			if (!curr)
				return ;
			if (!curr->_left_child || !curr->_right_child)
			{
				node* newCurr;

				if (!curr->_left_child)
					newCurr = curr->_right_child;
				else
					newCurr = curr->_left_child;
				if (!prev)
					return ;
				if (curr == prev->_left_child)
					prev->_left_child = newCurr;
				else
					prev->_right_child = newCurr;
				this->_alloc.destroy(curr);
				this->_alloc.deallocate(curr, 1);
			}
			else
			{
				node* p = NULL;
				node* temp;

				temp = curr->_right_child;
				while (temp->_left_child)
				{
					p = temp;
					temp = temp->_left_child;
				}
				if (p)
					p->_left_child = temp->_right_child;
				else
					curr->_right_child = temp->_right_child;
				//curr = temp;
				//curr->_data = temp->_data;
				this->_alloc.destroy(temp);
				this->_alloc.deallocate(temp, 1);
			}
			this->_size--;
			//return (this);
		}
		void	erase_node(pair_type const & new_pair)
		{
			node *new_node = this->search(new_pair);

			this->erase_node(new_node);
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

			while (search_node)
			{
				//std::cout << "allo" << std::endl;
				if (this->_cmp(search_node->_data.first, new_pair.first))
					search_node = search_node->_right_child;
				else if (this->_cmp(new_pair.first, search_node->_data.first))
					search_node = search_node->_left_child;
				else if (new_pair.first == search_node->_data.first)
					return (search_node);
			}
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
