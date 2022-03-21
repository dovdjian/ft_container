/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:41:37 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/20 13:24:37 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_ITERTATOR_HPP
# define REV_ITERTATOR_HPP

//#include "vector.hpp"

namespace ft
{
	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename	Iterator::difference_type	difference_type;
			typedef typename	Iterator::value_type		value_type;
			typedef typename	Iterator::pointer			pointer;
			typedef typename	Iterator::reference			reference;
			typedef typename	Iterator::iterator_category	iterator_category;
	};

	template <class Iterator>
	class reverse_iterator
	{
		public:
			// TYPEDEF
				typedef Iterator iterator_type;
				typedef typename iterator_traits<Iterator>::iterator_category
					iterator_category;
				typedef typename iterator_traits<Iterator>::value_type
					value_type;
				typedef typename iterator_traits<Iterator>::difference_type
					difference_type;
				typedef typename iterator_traits<Iterator>::pointer
					pointer;
			// CONSTRUCTOR
				// Default
					reverse_iterator() : _it(NULL) {}
				// Init
					explicit reverse_iterator(iterator_type it);
				// COPY CONSTRUCTIBLE
					reverse_iterator(const Iterator & cpy)
					{
						*this = cpy;
					}
				// COPY ASSIGNABLE
					reverse_iterator(pointer ptr) : _ptr(ptr) {}
				// DESTRUCTOR
					~reverse_iterator(){}
				// IMPLICIT CONVERSION
					operator reverse_iterator<const ite_T, true>() const
						{ return (reverse_iterator<const ite_T, true>(this->_ptr)); }
				// OPERATOR =
					Iterator & operator=( Iterator const & src)
					{
						if (this != &src)
							this->_ptr = src.getPtr();
						return (*this);
					}
			// METHODS
				iterator_type base() { return (this->_it); } const
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
				reference operator*() { return (*this->_it); }
				pointer operator->() const {  return &(operator*()); }
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
				reverse_iterator operator+(difference_type const & val) const
					{ return (Iterator(this->_ptr + val)); }
				difference_type operator+(Iterator<ite_T, false> const & it) const
					{ return (this->_ptr + it.getPtr()); }
				reverse_iterator operator-(difference_type const & val) const
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
				reverse_iterator operator+=(difference_type const & val)
					{ return (Iterator(this->_ptr += val)); }
				reverse_iterator operator-=(difference_type const & val)
					{ return (Iterator(this->_ptr -= val)); }
				reference operator[] (difference_type n) const
					{ return (this->_it[n]); }
			private:
				iterator_type _it;
	};
}
#endif


