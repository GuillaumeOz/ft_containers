/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_compare.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:29:52 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/06 16:30:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_COMPARE_HPP
# define EQUAL_COMPARE_HPP

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

#endif