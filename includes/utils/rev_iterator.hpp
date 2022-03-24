/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:41:37 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/21 11:15:29by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_ITERTATOR_HPP
# define REV_ITERTATOR_HPP

namespace ft
{
	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename	Iterator::difference_type	difference_type;
			//typedef typename	Iterator::value_type		value_type;
			typedef typename	Iterator::pointer			pointer;
			typedef typename	Iterator::reference			reference;
			//typedef typename	Iterator::iterator_category	iterator_category;
	};

	template <class Iterator>
	class reverse_iterator
	{
		public:
			// TYPEDEF
				typedef Iterator iterator_type;
				//typedef typename iterator_traits<Iterator>::iterator_category
					//iterator_category;
				//typedef typename iterator_traits<Iterator>::value_type
					//value_type;
				typedef typename iterator_traits<Iterator>::difference_type
					difference_type;
				typedef typename iterator_traits<Iterator>::pointer
					pointer;
				typedef typename iterator_traits<Iterator>::reference
					reference;
			// CONSTRUCTOR
				// DEFAULT
					reverse_iterator() { Iterator(); }
				// INIT
					explicit reverse_iterator(iterator_type it)
					{
						this->_it = it;
					}
				// COPY
					template <class Iter>
					reverse_iterator(const reverse_iterator<Iter> & rev_it)
					{
						this->_it = rev_it.base();
					}
			// DESTRUCTOR
				~reverse_iterator(){}
			// METHODS
				iterator_type base() const { return (this->_it); }
				reference operator*() const
				{
					Iterator tmp = this->_it;

					--tmp;
					return (*tmp);
				}
				reverse_iterator operator+(difference_type n) const
					{ return (reverse_iterator(this->base() - n)); }
				reverse_iterator & operator++() // pre
				{
					_it--;
					return (*this);
				}
				reverse_iterator operator++(int) // post
				{
					reverse_iterator	ret = *this;
					_it--;
					return (ret);
				}
				reverse_iterator & operator+=(difference_type n)
				{
					this->_it -= n;
					return (*this);
				}
				reverse_iterator operator-(difference_type n) const
					{ return (reverse_iterator(this->base() + n)); }
				reverse_iterator & operator--() // pre
				{
					_it++;
					return (*this);
				}
				reverse_iterator operator--(int) // post
				{
					reverse_iterator	ret = *this;
					_it++;
					return (ret);
				}
				reverse_iterator & operator-=(difference_type n)
					{
						this->_it += n;
						return (*this);
					}
				pointer operator->() const { return &(operator*()); }
				reference operator[](difference_type n) const
					{ return (this->base()[-n - 1]); }
			private:
				iterator_type _it;
	};
	template <class Iterator, class Iterator2>
	bool operator==(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator2> & rhs)
			{ return (lhs.base() == rhs.base()); }
	template <class Iterator, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator2> & rhs)
			{ return (lhs.base() != rhs.base()); }
	template <class Iterator, class Iterator2>
	bool operator<(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator2> & rhs)
			{ return (lhs.base() > rhs.base()); }
	template <class Iterator, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator2> & rhs)
			{ return (lhs.base() >= rhs.base()); }
	template <class Iterator, class Iterator2>
	bool operator>(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator2> & rhs)
			{ return (lhs.base() < rhs.base()); }
	template <class Iterator, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator2> & rhs)
			{ return (lhs.base() <= rhs.base()); }
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it)
			{ return (reverse_iterator<Iterator>(rev_it.base() - n)); }
	template <class Iterator, class Iterator2>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator2>& rhs)
				{ return (rhs.base() - lhs.base()); }
}
#endif


