/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:57:47 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/24 16:47:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "ft_containers.hpp"

namespace ft {

template <typename Key, typename T, typename Compare = std::less<Key>,
typename Alloc = std::allocator<std::pair<const Key, T> > >
class map {

//--------------------------------TYPEDEF-------------------------------------//

	public:

	typedef Key													key_type;
	typedef T													mapped_type;
	typedef ft::pair<const key_type, mapped_type>				value_type;//change for ft ?
	typedef Compare												key_compare;
	typedef Alloc												allocator_type;
	// typedef				Compare									value_compare;
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

//------------------------NESTED VALUE COMPARE CLASS--------------------------//

	public://its necessary ?
		class value_compare : public std::binary_function<value_type, value_type, bool> {

			friend class map<_Key, _Tp, Compare, _Alloc>;//remove friend here
		protected:
			Compare comp;

			value_compare(Compare __c) : comp(__c) {

			}

		public:
			bool operator()(const value_type& __x, const value_type& __y) const {

				return comp(__x.first, __y.first);
			}
	};

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
		this->insert(first, last);
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

//-------------------------------DESTRUCTOR-----------------------------------//

	~map(void) {

		this->clear();//delete all nodes
		delete (this->_root);
	}

//--------------------------ITERATORS FUNCTIONS-------------------------------//

	iterator begin() {

		return (iterator(lastLeft(this->_root)));
	}

	const_iterator begin() const {

		return (const_iterator(lastLeft(this->_root)));
	}

	iterator end() {

		return (iterator(lastRight(this->_root)));
	}

	const_iterator end() const {

		return (const_iterator(lastRight(this->_root)));
	}

	reverse_iterator rbegin() {

		return (reverse_iterator(lastRight(this->_root)));
	}

	const_reverse_iterator rbegin() const {

		return (const_reverse_iterator(lastRight(this->_root)));
	}

	reverse_iterator rend() {

		return (reverse_iterator(lastLeft(this->_root)));
	}

	const_reverse_iterator rend() const {

		return (const_reverse_iterator(lastLeft(this->_root)));
	}

//---------------------------CAPACITY FUNCTIONS-------------------------------//

	bool	empty() const {

		if (this->_size == 0)
			return (true);
		return (false);
	}

	size_type	size() const {

		return (this->_size);
	}

	size_type	max_size() const {

		return (this->_max_size);
	}

//-------------------------ELEMENT ACCESS FUNCTION----------------------------//

	mapped_type&	operator[](const key_type& k) {

		iterator it = lower_bound(k);

		it = insert(it, value_type(k, mapped_type()));

		return (*it).second;

	}

//---------------------------MODIFIERS FUNCTIONS------------------------------//

	// single element (1)
	ft::pair<iterator,bool>	insert(const value_type& val) {

	}

	// with hint (2)
	iterator insert (iterator position, const value_type& val);

	// range (3)
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last);

//--------------------------OBSERVERS FUNCTIONS-------------------------------//

	key_compare key_comp() const {

		return (key_compare());
	}

	value_compare value_comp() const {

		return (value_compare(key_compare()));
	}

//--------------------------OPERATIONS FUNCTIONS------------------------------//

	iterator	find(const key_type& __x) {

		iterator __j = _M_lower_bound(_M_begin(), _M_end(), __k);

		return (__j == end()
			|| _M_impl._M_key_compare(__k,
										_S_key(__j._M_node))) ? end() : __j;//redo this function
	}

	const_iterator	find(const key_type& __x) const {

		const_iterator __j = _M_lower_bound(_M_begin(), _M_end(), __k);

		return (__j == end()
				|| _M_impl._M_key_compare(__k,
											_S_key(__j._M_node))) ? end() : __j;//same
	}

	size_type count (const key_type& k) const {

		return (this->find(k) != this->end() ? 1 : 0);
	}

	iterator lower_bound (const key_type& k) {

		{ return _M_lower_bound(_M_begin(), _M_end(), __k); }//TODO
	}

	template<typename _Key, typename _Val, typename _KeyOfValue,
			typename _Compare, typename _Alloc>
		typename _Rb_tree<_Key, _Val, _KeyOfValue,
						_Compare, _Alloc>::iterator
		_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
		_M_lower_bound(_Link_type __x, _Base_ptr __y,
					const _Key& __k)
		{
		while (__x != 0)
			if (!_M_impl._M_key_compare(_S_key(__x), __k))
			__y = __x, __x = _S_left(__x);
			else
			__x = _S_right(__x);
		return iterator(__y);
		}

	const_iterator lower_bound (const key_type& k) const {

		{ return _M_lower_bound(_M_begin(), _M_end(), __k); }
	}

	template<typename _Key, typename _Val, typename _KeyOfValue,
			typename _Compare, typename _Alloc>
		typename _Rb_tree<_Key, _Val, _KeyOfValue,
						_Compare, _Alloc>::const_iterator
		_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
		_M_lower_bound(_Const_Link_type __x, _Const_Base_ptr __y,
					const _Key& __k) const
		{
		while (__x != 0)
			if (!_M_impl._M_key_compare(_S_key(__x), __k))
			__y = __x, __x = _S_left(__x);
			else
			__x = _S_right(__x);
		return const_iterator(__y);
		}

//---------------------------PRIVATE ATTRIBUTES-------------------------------//

	private:

	node_ptr				_root;
	allocator_type			_alloc;
	key_compare				_keyCompare;
	size_type				_size;
	size_type				_maxSize;

};

};

#endif