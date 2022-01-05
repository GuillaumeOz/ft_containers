/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:41:02 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 21:11:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTRAITS_HPP
# define ITERATORTRAITS_HPP

#include <iostream>

namespace ft {

	///  Marking input iterators.
	struct input_iterator_tag { };
	///  Marking output iterators.
	struct output_iterator_tag { };
	/// Forward iterators support a superset of input iterator operations.
	struct forward_iterator_tag : public input_iterator_tag { };
	/// Bidirectional iterators support a superset of forward iterator
	/// operations.
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	/// Random-access iterators support a superset of bidirectional
	/// iterator operations.
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
			typename _Pointer = _Tp*, typename _Reference = _Tp&>
	struct iterator {

	  /// One of the @link iterator_tags tag types@endlink.
	  typedef _Category  iterator_category;
	  /// The type "pointed to" by the iterator.
	  typedef _Tp        value_type;
	  /// Distance between iterators is represented as this type.
	  typedef _Distance  difference_type;
	  /// This type represents a pointer-to-value_type.
	  typedef _Pointer   pointer;
	  /// This type represents a reference-to-value_type.
	  typedef _Reference reference;
	};

	template<typename Iterator>
	struct iterator_traits {

		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	/// Partial specialization for pointer types.
	template<typename Tp>
	struct iterator_traits<Tp*> {

		typedef random_access_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef ptrdiff_t					difference_type;
		typedef Tp*							pointer;
		typedef Tp&							reference;
	};

	/// Partial specialization for const pointer types.
	template<typename Tp>
	struct iterator_traits<const Tp*> {

		typedef random_access_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef ptrdiff_t					difference_type;
		typedef const Tp*					pointer;
		typedef const Tp&					reference;
	};

	template<typename _Iter>
		inline _GLIBCXX_CONSTEXPR
	typename iterator_traits<_Iter>::iterator_category
		__iterator_category(const _Iter&)
	{ return typename iterator_traits<_Iter>::iterator_category(); }

	//Work on this part

};

#endif