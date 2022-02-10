/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:24:01 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/10 18:24:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {

	/// integral_constant template struct.
	template < class T, T v >
	struct integral_constant {

		static const T value = v;

		typedef T value_type;

		typedef integral_constant<T, v> type;

		operator T() {

			return (v);
		}
	};

	/// Set true_type with true value at compile time.
	typedef integral_constant<bool, true>	true_type;

	/// Set true_type with false value at compile time.
	typedef integral_constant<bool, false>	false_type;

	template < class T > struct is_integral : public false_type {};

	template <>			 struct is_integral<bool> : public true_type {};
	template <>			 struct is_integral<char> : public true_type {};
	template <>			 struct is_integral<signed char> : public true_type {};
	template <>			 struct is_integral<unsigned char> : public true_type {};
	template <>			 struct is_integral<wchar_t> : public true_type {};
	template <>			 struct is_integral<short> : public true_type {};
	template <>			 struct is_integral<unsigned short> : public true_type {};
	template <>			 struct is_integral<int> : public true_type {};
	template <>			 struct is_integral<unsigned int> : public true_type {};
	template <>			 struct is_integral<long> : public true_type {};
	template <>			 struct is_integral<long long> : public true_type {};
	template <>			 struct is_integral<unsigned long> : public true_type {};
	template <>			 struct is_integral<unsigned long long> : public true_type {};

};

#endif