/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:01:08 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/19 08:35:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

namespace ft {

	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {//test this

		ft::pair	retPair(x, y);

		return (retPair);
	}
};

#endif