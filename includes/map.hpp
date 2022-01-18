/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:57:47 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/18 16:09:53 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

namespace ft {

template <typename Key, typename T, typename Compare = std::less<Key>,
typename _Alloc = std::allocator<std::pair<const Key, T> > >
class map {

//--------------------------------TYPEDEF-------------------------------------//

	public:

	typedef Key											key_type;
	typedef T											mapped_type;
	typedef std::pair<const key_type, mapped_type>		value_type;
	typedef Compare										key_compare;
	typedef _Alloc										allocator_type;


// value_compare	Nested function class to compare elements	see value_comp
// allocator_type	The fourth template parameter (Alloc)	defaults to: allocator<value_type>
// reference	allocator_type::reference	for the default allocator: value_type&
// const_reference	allocator_type::const_reference	for the default allocator: const value_type&
// pointer	allocator_type::pointer	for the default allocator: value_type*
// const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*
// iterator	a bidirectional iterator to value_type	convertible to const_iterator
// const_iterator	a bidirectional iterator to const value_type	
// reverse_iterator	reverse_iterator<iterator>	
// const_reverse_iterator	reverse_iterator<const_iterator>	
// difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
// size_type	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t



	private:

	typedef typename _Alloc::value_type		_Alloc_value_type;

	static_assert(is_same<typename _Alloc::value_type, value_type>::value,
		"std::map must have the same value_type as its allocator");

    typedef rb_tree<key_type, value_type, 
                    select1st<value_type, key_type>, key_compare> rep_type;
    rep_type t;  // red-black tree representing map


	public:


	empty (1)
	explicit map (const key_compare& comp = key_compare(),
	const allocator_type& alloc = allocator_type());

	range (2)
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());

	copy (3)
	map (const map& x);

    // map(const Compare& comp = Compare()) : t(comp, false) {}
    // map(const value_type* first, const value_type* last, 
    //     const Compare& comp = Compare()) : t(first, last, comp, false) {}
    // map(const map<Key, T, Compare>& x) : t(x.t, false) {}
    // map<Key, T, Compare>& operator=(const map<Key, T, Compare>& x) {
    //     t = x.t;
    //     return *this; 
    // }

};

};

#endif