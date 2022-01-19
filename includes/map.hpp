/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:57:47 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/19 18:04:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <map>

namespace ft {

template <typename Key, typename T, typename Compare = std::less<Key>,
typename Alloc = std::allocator<std::pair<const Key, T> > >
class map {

//--------------------------------TYPEDEF-------------------------------------//

	public:

	typedef Key													key_type;
	typedef T													mapped_type;
	typedef std::pair<const key_type, mapped_type>				value_type;//change for ft
	typedef Compare												key_compare;
	typedef Alloc												allocator_type;
	//create value_compare class later

	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;

	typedef ft::mapNode<value_type>								node_type;
	typedef node_type*											node_ptr;

	typedef ft::redBlackIterator<value_type, node_type>			iterator;
	typedef ft::redBlackIterator<const value_type, node_type>	const_iterator;
	typedef ft::reverseIterator<iterator>						reverse_iterator;
	typedef ft::reverseIterator<const_iterator>					const_reverse_iterator;
	typedef ptrdiff_t											difference_type;
	typedef size_t												size_type;

//------------------------------CONSTRUCTORS----------------------------------//
	
	// Default constructor
	map(key_compare const &comp, allocator_type const &alloc) {

		this->_root = NULL;
		this->_keyCompare = comp;
		this->_alloc = alloc;
		this->_size = 0;

		this->_root = new node_type;
	}

	// Range constructor
	template <class InputIterator>
	map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

	// Range constructor overload, at runtime, C++14 implementation, check if necessary
	template <class InputIterator>
	map(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first,
		InputIterator last, key_compare const &comp, allocator_type const &alloc) {

		this->_root = NULL;
		this->_keyCompare = comp;
		this->_alloc = alloc;
		this->_size = 0;

		this->_root = new node_type;
		//create the node content with range
	}

	// Copy Constructor
	map(map const &src) {

		this->_root = NULL;
		this->_keyCompare = key_compare();
		this->_alloc = allocator_type();
		this->_size = 0;

		this->_root = new node_type;
		*this = src;
	}

	~map(void) {

		this->clear();//delete all nodes
		delete (this->_root);
	}

	private:

	node_ptr				_root;
	allocator_type			_alloc;
	key_compare				_keyCompare;
	size_type				_size;
	size_type				_maxSize;

};

};

#endif