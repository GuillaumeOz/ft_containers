/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:59:44 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/12 19:39:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type itDiff(InputIterator start, InputIterator end) {

		typename iterator_traits<InputIterator>::difference_type len = 0;

		while (start != end) {

			len++;
			++start;
		}
		return (len);
	}

}

#endif