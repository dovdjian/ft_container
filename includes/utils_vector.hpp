/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:41:37 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/22 10:50:09 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_VECTOR_HPP
# define UTILS_VECTOR_HPP

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
}

#endif
