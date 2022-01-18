/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:01:08 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/18 15:09:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

namespace ft {

// template<class _T1, class _T2>
// inline pair<typename __decay_and_strip<_T1>::__type,
// typename __decay_and_strip<_T2>::__type>
// make_pair(_T1&& __x, _T2&& __y)
// {
// 	return pair<typename __decay_and_strip<_T1>::__type,
// 	typename __decay_and_strip<_T2>::__type>
// 	(std::forward<_T1>(__x), std::forward<_T2>(__y));
// }

// template<typename _T1, typename _T2>
// constexpr pair<typename __decay_and_strip<_T1>::__type, 
// 	typename __decay_and_strip<_T2>::__type>
// make_pair(_T1&& __x, _T2&& __y)
// {
// 	typedef typename __decay_and_strip<_T1>::__type __ds_type1;
// 	typedef typename __decay_and_strip<_T2>::__type __ds_type2;
// 	typedef pair<__ds_type1, __ds_type2> 	      __pair_type;

// 	return __pair_type(std::forward<_T1>(__x), std::forward<_T2>(__y));
// }; // its usefull from source code // C11 implementation


	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {//test this

		ft::pair	retPair(x, y);

		return (retPair);
	}

};

#endif