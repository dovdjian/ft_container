/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:40:49 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/28 11:16:49 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#ifndef prefix
# define prefix ft
#endif

# if prefix == ft
	# define print_prefix "ft"
# else
	# define print_prefix "std"
# endif

#include "../stl/vector.hpp"
#include "../stl/stack.hpp"
#include "../stl/map.hpp"

// ---------------- UTILS_TESTS -------------------



// ---------------- TEST VECTOR -------------------

void	tests_vector();
void	tests_constructor();
void	tests_iterator();
void	tests_r_iterator();
void	tests_methods();

// ---------------- TEST STACK -------------------
void	tests_stack();
void	tests_constructor_stack();
void	tests_methods_stack();

// ---------------- TEST MAP -------------------
void	tests_map();
void	tests_iterator_map();
void	tests_methods_map();

#endif
