/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:59:15 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 20:08:10 by gozsertt         ###   ########.fr       */
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
// #define print(x)	std::cout << x << std::endl;

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

	template < class T, T v >
	struct integral_constant {

		static const T value = v;

		typedef T value_type;

		typedef integral_constant<T, v> type;

		operator T() {
		
			return v;
		}
	};

	typedef integral_constant<bool, true>	true_type;

	typedef integral_constant<bool, false>	false_type;

	template < class T > struct is_integral : public false_type {};

	template <>			 struct is_integral<bool> : public true_type {};

	template <>			 struct is_integral<char> : public true_type {};
	template <>			 struct is_integral<wchar_t> : public true_type {};
	template <>			 struct is_integral<signed char> : public true_type {};//its usefull ?
	template <>			 struct is_integral<unsigned char> : public true_type {};

	template <>			 struct is_integral<short int> : public true_type {};
	template <>			 struct is_integral<unsigned short int> : public true_type {};

	template <>			 struct is_integral<int> : public true_type {};
	template <>			 struct is_integral<unsigned int> : public true_type {};

	template <>			 struct is_integral<long int> : public true_type {};
	template <>			 struct is_integral<long long int> : public true_type {};
	template <>			 struct is_integral<unsigned long int> : public true_type {};
	template <>			 struct is_integral<unsigned long long int> : public true_type {};

template<bool Cond, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> {

	typedef T type;
};

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