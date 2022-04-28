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
		node		*_left_child;
		node		*_right_child;
		node		*_parent;
		int			_depth;
		pair_type	_data;

		node(pair_type new_pair) : _depth(1), _data(new_pair) {}
	};
	// TYPEDEF
		typedef size_t size_type;
		typedef typename	Alloc::template rebind<node>::other		allocator_type;
	// VARIABLES
		size_type		_size;
		key_compare		_cmp;
		allocator_type	_alloc;
		node			*_root;
		node			*_nul_node;
	// CONSTRUCTOR
		// DEFAULT
			BST()
			{
				node new_node((pair_type()));

				new_node._left_child = NULL;
				new_node._right_child = NULL;
				new_node._parent = NULL;

				this->_nul_node = this->_alloc.allocate(1);
				this->_alloc.construct(this->_nul_node, new_node);
				this->_root = this->_nul_node;
				this->_size = 0;
			}
		// COPY
			BST(const BST & src)
			{
				*this = src;
			}
	// DESTRUCTOR
		~BST()
		{
			this->destroy_tree(this->_root);
			this->_alloc.destroy(this->_nul_node);
			this->_alloc.deallocate(this->_nul_node, 1);
		}
	// OPERATOR =
		BST & operator=(BST const & src)
		{
			if (this != &src)
			{
				this->_alloc = src._alloc;
				this->_cmp = src._cmp;
				this->_size = src._size;
				this->_nul_node = src._nul_node;
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
						this->_node = src.getNode();
					return (*this);
				}
			// METHODS
				node *getNode() const { return (this->_node); }
				void	treeIncrement()
				{
					if (this->_node->_right_child->_right_child)
					{
						this->_node = this->_node->_right_child;
						while (this->_node->_left_child->_right_child)
							this->_node = this->_node->_left_child;
					}
					else
					{
						node *new_parent = this->_node->_parent;

						while (this->_node == new_parent->_right_child)
						{
							this->_node = new_parent;
							new_parent = new_parent->_parent;
						}
						this->_node = new_parent;
					}
				}
				void	treeDecrement()
				{
					if (!this->_node->_right_child)
					{
						node *new_right = this->_node;
						new_right = new_right->_parent;
						while (new_right->_right_child != this->_node)
							new_right = new_right->_right_child;
						this->_node = new_right;
					}
					else if (!this->_node->_left_child->_left_child)
					{
						node *new_parent = this->_node->_parent;

						while (this->_node == new_parent->_left_child)
						{
							this->_node = new_parent;
							new_parent = new_parent->_parent;
						}
						this->_node = new_parent;
					}
					else
					{
						this->_node = this->_node->_left_child;
						while (this->_node->_right_child->_left_child)
							this->_node = this->_node->_right_child;
					}
				}
			// ALL CATEGORIES
				bidir_iterator & operator++() // pre
				{
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
				node			*_node;
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
			return (iterator(this->_nul_node));
		}
		const_iterator begin() const
		{
			if (this->_size == 0)
				return (this->end());
			return (const_iterator(this->find_start()));
		}
		const_iterator end() const
		{
			return (const_iterator(this->_nul_node));
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
			node *ret = this->_alloc.allocate(1);
			node tmp(new_pair);

			tmp._parent = this->_nul_node;
			tmp._left_child = this->_nul_node;
			tmp._right_child = this->_nul_node;
			this->_alloc.construct(ret, tmp);
			return (ret);
		}
		void	clear()
		{
			this->destroy_tree(this->_root);
			this->_size = 0;
			this->_root = this->_nul_node;
			this->_nul_node->_parent = NULL;
		}
		void	swap(BST & x)
		{
			ft::swap(this->_root, x._root);
			ft::swap(this->_nul_node, x._nul_node);
			ft::swap(this->_size, x._size);
			ft::swap(this->_alloc, x._alloc);
			ft::swap(this->_cmp, x._cmp);
		}
		void	destroy_tree(node *del_node)
		{
			if (del_node == this->_nul_node)
				return ;
			this->destroy_tree(del_node->_left_child);
			this->destroy_tree(del_node->_right_child);
			this->_alloc.destroy(del_node);
			this->_alloc.deallocate(del_node, 1);
		}
		ft::pair<iterator, bool> insert(pair_type const & new_pair)
		{
			iterator it;
			bool	existed_bfr_insert;
			if (this->search(new_pair) != this->_nul_node)
			{
				it = iterator(this->search(new_pair));
				existed_bfr_insert = false;
			}
			else
			{
				this->insert_node(this->create_node(new_pair));
				it = iterator(this->search(new_pair));
				existed_bfr_insert = true;
			}
			return (ft::make_pair(it, existed_bfr_insert));
		}
		void	insert_node(node *node_arg)
		{
			node *new_root = this->_root;
			node *y = this->_nul_node;

			while (new_root != this->_nul_node)
			{
				y = new_root;
				if (this->_cmp(node_arg->_data.first, new_root->_data.first))
					new_root = new_root->_left_child;
				else
					new_root = new_root->_right_child;
			}
			node_arg->_parent = y;
			if (y == this->_nul_node)
				this->_root = node_arg;
			else if (this->_cmp(node_arg->_data.first, y->_data.first))
				y->_left_child = node_arg;
			else
				y->_right_child = node_arg;
			this->_nul_node->_parent = this->_root;
			this->_size++;
		}
		void	delete_node(pair_type const & new_pair)
		{
			node *newCurr = this->_nul_node;
			node *prev = this->_nul_node;
			node *curr = this->search(new_pair);

			if (curr == this->_nul_node)
				return ;
			if (curr->_left_child == this->_nul_node
				|| curr->_right_child == this->_nul_node)
				newCurr = curr;
			else
			{
				newCurr = curr->_right_child;
				while (newCurr->_left_child != this->_nul_node)
					newCurr = newCurr->_left_child;
			}
			if (newCurr->_left_child != this->_nul_node)
				prev = newCurr->_left_child;
			else
				prev = newCurr->_right_child;
			prev->_parent = newCurr->_parent;
			if (newCurr->_parent == this->_nul_node)
				this->_root = prev;
			else if (newCurr == newCurr->_parent->_left_child)
				newCurr->_parent->_left_child = prev;
			else
				newCurr->_parent->_right_child = prev;
			if (newCurr != curr)
			{
				curr->_left_child->_parent = newCurr;
				newCurr->_left_child = curr->_left_child;
				if (newCurr != curr->_right_child)
				{
					prev->_parent = newCurr->_parent;
					newCurr->_parent->_left_child = prev;
					newCurr->_right_child = curr->_right_child;
					curr->_right_child->_parent = newCurr;
				}
				else
					prev->_parent = newCurr;
				if (curr->_parent->_left_child == curr)
					curr->_parent->_left_child = newCurr;
				else if (curr->_parent->_right_child == curr)
					curr->_parent->_right_child = newCurr;
				else if (this->_root == curr)
					this->_root = newCurr;
				newCurr->_parent = curr->_parent;
				newCurr = curr;
			}
			this->_alloc.destroy(newCurr);
			this->_alloc.deallocate(newCurr, 1);
			newCurr = this->_nul_node;
			this->_nul_node->_parent = this->_root;
			this->_size--;
		}
		void	erase_node(pair_type const & new_pair)
		{
			node *new_node = this->search(new_pair);

			this->erase_node(new_node);
		}
		iterator find(pair_type const & new_pair)
		{
			return (iterator(this->search(new_pair)));
		}
		const_iterator find(pair_type const & new_pair) const
		{
			return (const_iterator(this->search(new_pair)));
		}
		size_type count(pair_type const & new_pair) const
		{
			if (this->search(new_pair) != this->_nul_node)
				return (1);
			return (0);
		}
		node *find_start() const
		{
			node *new_node = this->_root;

			while (new_node->_left_child != this->_nul_node)
				new_node = new_node->_left_child;
			return (new_node);
		}
		node *find_end() const
		{
			node *new_node = this->_root;

			while (new_node->_right_child != this->_nul_node)
				new_node = new_node->_right_child;
			return (new_node);
		}
		node	*search(pair_type const & new_pair) const
		{
			node *search_node = this->_root;

			while (search_node != this->_nul_node)
			{
				if (this->_cmp(search_node->_data.first, new_pair.first))
					search_node = search_node->_right_child;
				else if (this->_cmp(new_pair.first, search_node->_data.first))
					search_node = search_node->_left_child;
				else if (new_pair.first == search_node->_data.first)
					return (search_node);
			}
			return (this->_nul_node);
		}
};

#endif
