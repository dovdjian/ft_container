/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stl.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:22:21 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/05 16:54:13 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STL_HPP
# define UTILS_STL_HPP

namespace ft
{
	template <bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> { typedef T type; };

	template <class T, T v>
	struct integral_constant
	{
		typedef T value_type;
		typedef integral_constant<T, v> type;

		static const T value = v;
		operator value_type() { return (v); };
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template <typename>
	struct is_integral : false_type {};

	template <typename T>
	struct is_integral<const T> : is_integral<T> {};

	template <>
	struct is_integral<bool> : true_type {};

	template <>
	struct is_integral<char> : true_type {};

	template <>
	struct is_integral<wchar_t> : true_type {};

	template <>
	struct is_integral<signed char> : true_type {};

	template <>
	struct is_integral<short int> : true_type {};

	template <>
	struct is_integral<int> : true_type {};

	template <>
	struct is_integral<long int> : true_type {};

	template <>
	struct is_integral<long long int> : true_type {};

	template <>
	struct is_integral<unsigned char> : true_type {};

	template <>
	struct is_integral<unsigned short int> : true_type {};

	template <>
	struct is_integral<unsigned int> : true_type {};

	template <>
	struct is_integral<unsigned long int> : true_type {};

	template <>
	struct is_integral<unsigned long long int> : true_type {};

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); first1++, first2++)
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}
	template <class InputIterator1, class InputIterator2>
		bool equal(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2))
				return (false);
		}
		return (true);
	}

	template <class T1, class T2>
	struct pair
	{
		// TYPEDEF
			typedef T1 first_type;
			typedef T2 second_type;
		// VARIABLES
			first_type first;
			second_type second;
		// CONSTRUCTOR
			// DEFAULT
				pair() : first(), second() {}
			// COPY
				template <class U, class V>
				pair(const pair<U, V> & pr)
				{
					this->first = pr.first;
					this->second = pr.second;
				}
			// INIT
				pair(const first_type & a, const second_type & b)
				{
					this->first = a;
					this->second = b;
				}
		// OPERATOR =
			pair & operator=(const pair & pr)
			{
				if (this != &pr)
				{
					this->first = pr.first;
					this->second = pr.second;
				}
				return (*this);
			}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
		{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
		{ return !(lhs == rhs); }

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
		{ return (lhs.first < rhs.first || (!(rhs.first < lhs.first)
			&& lhs.second < rhs.second)); }

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
		{ return !(rhs < lhs); }

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
		{ return (rhs < lhs); }

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
		{ return !(lhs < rhs); }

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}

#endif
