/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:40:49 by dodjian           #+#    #+#             */
/*   Updated: 2022/03/24 10:04:46 by dodjian          ###   ########.fr       */
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

#include "stl.hpp"

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

#endif
