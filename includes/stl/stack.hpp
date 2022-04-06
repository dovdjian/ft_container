/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <dovdjianpro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:25:25 by dodjian           #+#    #+#             */
/*   Updated: 2022/04/06 15:36:10 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
// Colors
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

#include "../utils/stl.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
		// TYPEDEF
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
		// CONSTRUCTOR
			// DEFAULT
				explicit stack(const container_type & ctnr = container_type())
				{
					this->c = ctnr;
				}
			// COPY
				stack(const stack & src)
				{
					this->c = src.c;
				}
		// =
			stack &		operator=(const stack & src)
			{
				if (this != &src)
				{
					this->c = src.c;
				}
				return (*this);
			}
		// DESTRUCTOR
			~stack() {}
		// METHODS
			// CAPACITY
				bool empty() const { return (c.empty()); }
				size_type size() const { return (c.size()); }
			// ELEMENT ACCESS
				value_type & top()
				{
					return (c.back());
				}
				const value_type & top() const
				{
					return (c.back());
				}
			// MODIFIERS
				void push(const value_type & val)
				{
					c.push_back(val);
				}
				void pop()
				{
					c.pop_back();
				}
			// GETTERS
				container_type const & get_c() const { return (this->c); }
		protected:
			// VARIABLES
				container_type	c;			// obj container(vector by default)
	};
	// Non member function overload
		template <class T, class Container>
		bool operator==(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
			{ return (lhs.get_c() == rhs.get_c()); }
		template <class T, class Container>
		bool operator!=(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
			{ return (lhs.get_c() != rhs.get_c()); }
		template <class T, class Container>
		bool operator<(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
			{ return (lhs.get_c() < rhs.get_c()); }
		template <class T, class Container>
		bool operator<=(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
			{ return (lhs.get_c() <= rhs.get_c()); }
		template <class T, class Container>
		bool operator>(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
			{ return (lhs.get_c() > rhs.get_c()); }
		template <class T, class Container>
		bool operator>=(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
			{ return (lhs.get_c() >= rhs.get_c()); }
}

#endif /* ********************************************************** `STACK_HPP */
