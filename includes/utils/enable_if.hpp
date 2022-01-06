/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:26:37 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/06 20:17:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

// Primary template.
/// Define a member typedef @c type only if a boolean constant is true.
template<bool Cond, class T = void>
struct enable_if {};

// Partial specialization for true.
template<class T>
struct enable_if<true, T> {

	typedef T type;
};

#endif