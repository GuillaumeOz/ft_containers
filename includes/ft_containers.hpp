/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:59:15 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/06 20:21:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

# include <iostream>
# include <cstddef>
# include <limits>
# include <fstream>
# include <limits>


namespace ft {

	struct  nullptr_t {
		void *_ptr;

		struct __nat { int __for_bool_; };

		nullptr_t() : _ptr(0) {}
		nullptr_t(int __nat::*) : _ptr(0) {}

		operator int __nat::*() const { return 0; }

		template <class _T>
		operator _T* () const {return 0;}

		template <class _T, class _U>
		operator _T _U::* () const {return 0;}

		friend	bool operator==(nullptr_t, nullptr_t) {

			return (true);
		}

		friend	bool operator!=(nullptr_t, nullptr_t) {

			return (false);
		}
	};

	#define ft_nullptr nullptr_t(0)

};

#define print(x)	std::cout << x << std::endl;

# include "equal_compare.hpp"
# include "lexicographical_compare.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "iteratorTraits.hpp"
# include "vectorIterator.hpp"
# include "reverseIterator.hpp"

// std::pair -> for map
// std::make_pair -> for map

#endif
