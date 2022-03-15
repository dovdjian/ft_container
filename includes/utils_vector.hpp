/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:41:37 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/15 20:59:22 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_VECTOR_HPP
# define UTILS_VECTOR_HPP

//#include "vector.hpp"

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
		operator value_type() { return v };
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template <typename>
	struct is_integral : false_type {};

	template<typename T>
	struct is_integral<const T> : is_integral<T> {};

	template<class T>
	struct is_integral
	{
		static const bool value;
		typedef std::integral_constant<bool, value> type;
	};

	template<>
	struct is_integral<bool> : true_type {};

	template<>
	struct is_integral<char> : true_type {};

	template<>
	struct is_integral<char16_t> : true_type {};

	template<>
	struct is_integral<char32_t> : true_type {};

	template<>
	struct is_integral<wchar_t> : true_type {};

	template<>
	struct is_integral<signed char> : true_type {};

	template<>
	struct is_integral<short int> : true_type {};

	template<>
	struct is_integral<int> : true_type {};

	template<>
	struct is_integral<long int> : true_type {};

	template<>
	struct is_integral<long long int> : true_type {};

	template<>
	struct is_integral<unsigned char> : true_type {};

	template<>
	struct is_integral<unsigned short int> : true_type {};

	template<>
	struct is_integral<unsigned int> : true_type {};

	template<>
	struct is_integral<unsigned long int> : true_type {};

	template<>
	struct is_integral<unsigned long long int> : true_type {};
}

#endif
