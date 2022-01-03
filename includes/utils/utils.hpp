/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:59:15 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/03 17:11:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <limits>

// #include <type_trait>

// iterators_traits
// reverse_iterator 

// enable_if
// is_integral

// std::pair -> for map
// std::make_pair -> for map

namespace ft {

// is_integral Struct
template <typename T>
struct is_integer {

	static const bool value;
};

// is_integral bool assignation
// template <typename T>
// const bool is_integer<T>::value = std::numeric_limits<T>::is_specialized && std::numeric_limits<T>::is_integer;

// is_integral bool assignation
template <typename T>
	const bool is_integer<T>::value = std::numeric_limits<T>::is_integer;//test this

// Equal compare
template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 ) {

	while (first1 != last1) {
		
		if (!(*(first1) == *(first2)))
			return (false);
		++first1;
		++first2;
	}
	return (true);
}

// Lexicographical compare
template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1) {

		if (first2 == last2 || *(first2) < *(first1))//test this
			return (false);
		else if (*(first1) < *(first2))
			return (true);
		++first1;
		++first2;
	}
	return (first2 != last2);
}

};



#endif