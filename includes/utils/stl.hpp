/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:57:59 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/06 15:40:51 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STL_HPP
# define STL_HPP

// COLORS
#define YELLOW		"\033[0;33m"
#define PURPLE		"\033[0;35m"
#define BBLACK		"\033[1;30m"
#define BRED		"\033[1;31m"
#define BGREEN		"\033[1;32m"
#define BYELLOW		"\033[1;33m"
#define BBLUE		"\033[1;34m"
#define BPURPLE		"\033[1;35m"
#define BCYAN		"\033[1;36m"
#define BWHITE		"\033[1;37m"
#define END			"\033[0m"

// OTHER
#include <vector>
#include <stack>
#include <map>
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <stack>
#include <cstddef>

// MY CLASSES
#include "utils_stl.hpp"
#include "utils_display.hpp"
#include "rev_iterator.hpp"
#include "bst.hpp"
#include "../stl/vector.hpp"

#endif
