/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:57:47 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/12 19:45:41 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

// # include "utils/lexicographical_compare.hpp"
// # include "utils/equal_compare.hpp"
// # include "utils/enable_if.hpp"
// # include "utils/is_integral.hpp"
// # include "utils/iteratorTraits.hpp"
// # include "utils/vectorIterator.hpp"
// # include "utils/reverseIterator.hpp"
// # include "utils/utils.hpp"
// # include "vector.hpp"
// # include "stack.hpp"
// # include "utils/pair.hpp"
// # include "utils/make_pair.hpp"
// # include "utils/redBlackIterator.hpp"
// # include "ft_containers.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::mapNode<ft::pair<const Key, T> > > >
class map {

//--------------------------------TYPEDEF-------------------------------------//

	public:

	typedef Key													key_type;
	typedef T													mapped_type;
	typedef ft::pair<const key_type, mapped_type>				value_type;
	typedef Compare												key_compare;
	typedef Alloc												allocator_type;

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
	typedef std::ptrdiff_t										difference_type;
	typedef size_t												size_type;

//------------------------NESTED VALUE COMPARE CLASS--------------------------//

	public:
		class value_compare : public std::binary_function<value_type, value_type, bool> {

		public:
			Compare		comp;

			value_compare(Compare c = key_compare()) : comp(c) {

			}

			bool operator()(const value_type& x, const value_type& y) const {

				return comp(x.first, y.first);
			}
	};

//------------------------------CONSTRUCTORS----------------------------------//

	// Empty constructor
	explicit map(key_compare const &comp = key_compare(),
				allocator_type const &alloc = allocator_type()) {

		this->_sentinal = allocator_type().allocate(1);
		allocator_type().construct(this->_sentinal, node_type(NONE, NULL, NULL, NULL));

		this->_root = this->_sentinal;
		this->_keyCompare = comp;
		this->_alloc = alloc;
		this->_size = 0;
	}

	// Range constructor
	template <class InputIterator>
	map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){

		this->_sentinal = allocator_type().allocate(1);
		allocator_type().construct(this->_sentinal, node_type(NONE, NULL, NULL, NULL));

		this->_root = this->_sentinal;
		this->_keyCompare = comp;
		this->_alloc = alloc;
		this->_size = 0;

		this->insert(first, last);
	}

	// Copy Constructor
	map(map const &src) {

		this->_sentinal = allocator_type().allocate(1);
		allocator_type().construct(this->_sentinal, node_type(NONE, NULL, NULL, NULL));

		this->_root = this->_sentinal;
		this->_keyCompare = src._keyCompare;
		this->_alloc = src._alloc;
		this->_size = 0;

		this->insert(src.begin(), src.end());

	}

//-------------------------------DESTRUCTOR-----------------------------------//

	~map(void) {

		this->clear();
		allocator_type().destroy(this->_sentinal);
		allocator_type().deallocate(this->_sentinal, 1);
	}

//--------------------------ASSIGNATION OPERATOR------------------------------//

	map& operator=(const map& rhs) {

		this->clear();

		_insertInputIterator(rhs.begin(), rhs.end());

		return (*this);
	}

//--------------------------ITERATORS FUNCTIONS-------------------------------//

	iterator begin() {

		return (iterator(lastLeft(this->_root), this->_sentinal));
	}

	const_iterator begin() const {

		return (const_iterator(lastLeft(this->_root), this->_sentinal));
	}

	iterator end() {

		return ((iterator(this->_sentinal, this->_sentinal)));
	}

	const_iterator end() const {

		return ((const_iterator(this->_sentinal, this->_sentinal)));
	}

	reverse_iterator rbegin() {

		return (reverse_iterator(iterator(this->_sentinal, this->_sentinal)));

	}

	const_reverse_iterator rbegin() const {

		return (const_reverse_iterator(const_iterator(this->_sentinal, this->_sentinal)));
	}

	reverse_iterator rend() {

		return (reverse_iterator(iterator(lastLeft(this->_root), this->_sentinal)));
	}

	const_reverse_iterator rend() const {

		return (const_reverse_iterator(const_iterator(lastLeft(this->_root), this->_sentinal)));
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

		return (std::numeric_limits<difference_type>::max() / (sizeof(node_type)));
	}

//-------------------------ELEMENT ACCESS FUNCTION----------------------------//

	mapped_type&	operator[](const key_type& k) {

		return ((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second);
	}

//---------------------------MODIFIERS FUNCTIONS------------------------------//

	ft::pair<iterator, bool> insert(const value_type& val) {
	
		if (this->_mapInsertUnique(val) == false) {

			return (ft::make_pair(find(val.first), false));
		}
		return (ft::make_pair(find(val.first), true));
	}

	iterator insert(iterator position, const value_type& val) {
		(void)position;
		return insert(val).first;
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last) {

		while (first != last) {

			insert(*first);
			first++;
		}
	}

	// iterator erase
	void	erase(iterator position) {

		this->erase(position->first);
	}

	// key erase
	size_type erase (const key_type& k) {

		if (this->_redBlackTreeEraseAndRebalance(ft::make_pair(k, mapped_type())) == true) {
			
			return (1);
		}
		return (0);
	}

	// range erase
	void erase (iterator first, iterator last) {

		while (first != last) {

			first = find(first->first);
			erase(first++);
		}
	}

	void swap (map& x) {

		map tmp;

		tmp._swapContent(x);
		x._swapContent(*this);
		this->_swapContent(tmp);
	}

	void clear() {

		if (this->_root != NULL)
			this->_destroyNode(this->_root);
		this->_root = this->_sentinal;
		this->_size = 0;
	}

//--------------------------OBSERVERS FUNCTIONS-------------------------------//

	key_compare key_comp() const {

		return (key_compare());
	}

	value_compare value_comp() const {

		return (value_compare(key_compare()));
	}

//--------------------------OPERATIONS FUNCTIONS------------------------------//

	iterator	find(const key_type& k) {


		iterator itEnd = this->end();

		for (iterator itBegin = this->begin(); itBegin != itEnd; itBegin++) {

			if (!this->_keyCompare(itBegin->first, k) && !this->_keyCompare(k, itBegin->first)) {

				return (itBegin);
			}
		}
		return (itEnd);
	}

	const_iterator	find(const key_type& k) const {

		const_iterator itEnd = this->end();

		for (const_iterator itBegin = this->begin(); itBegin != itEnd; itBegin++) {

			if (!this->_keyCompare(itBegin->first, k) && !this->_keyCompare(k, itBegin->first)) {

				return (itBegin);
			}
		}
		return (itEnd);
	}

	size_type count(const key_type& k) const {

		return (this->find(k) != this->end() ? 1 : 0);
	}

	iterator lower_bound (const key_type& k) {

		iterator itEnd = this->end();

		for (iterator itBegin = this->begin(); itBegin != itEnd; itBegin++) {

			if (!this->_keyCompare(itBegin->first, k))
				return (itBegin);
		}
		return (itEnd);
	}

	const_iterator lower_bound (const key_type& k) const {

		const_iterator itEnd = this->end();

		for (const_iterator itBegin = this->begin(); itBegin != itEnd; itBegin++) {

			if (!this->_keyCompare(itBegin->first, k))
				return (itBegin);
		}
		return (itEnd);
	}

	iterator	upper_bound (const key_type& k) {

		iterator itEnd = this->end();

		for (iterator itBegin = this->begin(); itBegin != itEnd; itBegin++) {

			if (this->_keyCompare(k, itBegin->first)) {

				return (itBegin);
			}
		}
		return (itEnd);
	}

	const_iterator	upper_bound (const key_type& k) const {

		const_iterator itEnd = this->end();

		for (const_iterator itBegin = this->begin(); itBegin != itEnd; itBegin++) {

			if (this->_keyCompare(k, itBegin->first)) {

				return (itBegin);
			}
		}
		return (itEnd);
	}

	pair<iterator,iterator>				equal_range (const key_type& k) {

		ft::pair<iterator, iterator> ret;

		ret.first = this->lower_bound(k);
		ret.second = this->upper_bound(k);

		return (ret);
	}

	pair<const_iterator,const_iterator>	equal_range (const key_type& k) const {

		ft::pair<const_iterator, const_iterator> ret;

		ret.first = this->lower_bound(k);
		ret.second = this->upper_bound(k);

		return (ret);
	}

//---------------------------ALLOCATOR FUNCTIONS------------------------------//

	allocator_type get_allocator() const {

		return (this->_alloc);
	}

//---------------------------PRIVATE ATTRIBUTES-------------------------------//

	private:

	node_ptr				_root;
	node_ptr				_sentinal;
	allocator_type			_alloc;
	key_compare				_keyCompare;
	size_type				_size;

	template <class InputIterator>
	void		_insertInputIterator(InputIterator first, InputIterator last) {

		this->insert(first, last);
	}

	void	_leftRotate(node_ptr node) {
		node_ptr	tmp = node->right;

		node->right = tmp->left;
		if (tmp->left != this->_sentinal)
			tmp->left->parent = node;

		tmp->parent = node->parent;
		if (node->parent == this->_sentinal)
			this->_root = tmp;
		else if (node == node->parent->left)
			node->parent->left = tmp;
		else
			node->parent->right = tmp;

		tmp->left = node;
		node->parent = tmp;
	}

	void	_rightRotate(node_ptr node) {
		node_ptr	tmp = node->left;

		node->left = tmp->right;
		if (tmp->right != this->_sentinal)
			tmp->right->parent = node;

		tmp->parent = node->parent;
		if (node->parent == this->_sentinal)
			this->_root = tmp;
		else if (node == node->parent->right)
			node->parent->right = tmp;
		else
			node->parent->left = tmp;

		tmp->right = node;
		node->parent = tmp;
	}

	bool	_mapInsertUnique(const value_type &val) {

		node_ptr toInsert = allocator_type().allocate(1);
		allocator_type().construct(toInsert, node_type(val, RED, NULL, NULL, NULL));

		toInsert->parent = this->_sentinal;
		toInsert->left = this->_sentinal;
		toInsert->right = this->_sentinal;

		value_compare comp;

		node_ptr current = NULL;
		node_ptr root = this->_root;

		this->_size++;
		if (this->_root == this->_sentinal) {

			this->_root = toInsert;
			this->_sentinal->parent = this->_root;
			this->_root->color = BLACK;
			return (true);
		}
		while (root != this->_sentinal) {

			current = root;
			if (comp(toInsert->value, root->value))
				root = root->left;
			else if (comp(root->value, toInsert->value))
				root = root->right;
			else {
				this->_size--;
				allocator_type().destroy(toInsert);
				allocator_type().deallocate(toInsert, 1);
				return (false);
			}
		}

		toInsert->parent = current;
		if (current == NULL) {
			this->_root = toInsert;
		}
		else if (comp(toInsert->value, current->value))
			current->left = toInsert;
		else
			current->right = toInsert;

		if (toInsert->parent == this->_sentinal) {
			toInsert->color = BLACK;
			return (true);
		}

		if (toInsert->parent->parent == this->_sentinal)
			return (true);

		_redBlackTreeInsertAndRebalance(toInsert);
		return (true);
	}

	void	_redBlackTreeInsertAndRebalance(node_ptr toFix) {

		node_ptr	tmp;

		while (toFix->parent->color == RED) {
			if (toFix->parent == toFix->parent->parent->right) {
				tmp = toFix->parent->parent->left;
				if (tmp != this->_sentinal && tmp->color == RED) {
					tmp->color = BLACK;
					toFix->parent->color = BLACK;
					toFix->parent->parent->color = RED;
					toFix = toFix->parent->parent;
				}
				else {
					if (toFix == toFix->parent->left) {
						toFix = toFix->parent;
						_rightRotate(toFix);
					}
					toFix->parent->color = BLACK;
					toFix->parent->parent->color = RED;
					_leftRotate(toFix->parent->parent);
				}
			}
			else {
				tmp = toFix->parent->parent->right;

				if (tmp != this->_sentinal && tmp->color == RED) {
					tmp->color = BLACK;
					toFix->parent->color = BLACK;
					toFix->parent->parent->color = RED;
					toFix = toFix->parent->parent;	
				}
				else {
					if (toFix == toFix->parent->right) {
						toFix = toFix->parent;
						_leftRotate(toFix);
					}
					toFix->parent->color = BLACK;
					toFix->parent->parent->color = RED;
					_rightRotate(toFix->parent->parent);
				}
			}
			if (toFix == this->_root)
				break ;
		}
		this->_root->color = BLACK;
	}

	void	_insertNewNode(node_ptr node, node_ptr toInsert) {

		if (node->parent == this->_sentinal)
			this->_root = toInsert;
		else if (node == node->parent->left)
			node->parent->left = toInsert;
		else
			node->parent->right = toInsert;

		toInsert->parent = node->parent;
	}

	void	_eraseRotation(node_ptr toFix) {

		node_ptr	tmp;

		while (toFix != this->_root && toFix->color == BLACK) {

			if (toFix == toFix->parent->left) {
				tmp = toFix->parent->right;
				if (tmp->color == RED) {
					tmp->color = BLACK;
					if (toFix->parent->color != NONE)
						toFix->parent->color = RED;
					_leftRotate(toFix->parent);
					tmp = toFix->parent->right;
				}

				if (tmp->left->color == BLACK && tmp->right->color == BLACK) {
					tmp->color = RED;
					if (toFix != this->_sentinal)
						toFix = toFix->parent;
				}
				else {
					if (tmp->right->color == BLACK) {
						tmp->left->color = BLACK;
						tmp->color = RED;
						_rightRotate(tmp);
						tmp = toFix->parent->right;
					}
					if (tmp->color != NONE)
						tmp->color = toFix->parent->color;
					if (toFix->parent->color != NONE)
						toFix->parent->color = BLACK;
					if (tmp->right->color != NONE)
						tmp->right->color = BLACK;
					_leftRotate(toFix->parent);
					toFix = this->_root;
				}
			}
			else {
				tmp = toFix->parent->left;
				if (tmp->color == RED) {
					tmp->color = BLACK;
					if (toFix->parent->color != NONE)
						toFix->parent->color = RED;
					_rightRotate(toFix->parent);
					tmp = toFix->parent->left;
				}
				if (tmp->left->color == BLACK && tmp->right->color == BLACK) {
					tmp->color = RED;
					toFix = toFix->parent;
				}
				else {
					if (tmp->left->color == BLACK) {
						if (tmp->right->color != NONE)
							tmp->right->color = BLACK;
						if (tmp->color != NONE)
							tmp->color = RED;
						_leftRotate(tmp);
						tmp = toFix->parent->left;
					} 

					tmp->color = toFix->parent->color;
					if (toFix->parent->color != NONE)
						toFix->parent->color = BLACK;
					if (tmp->left->color != NONE)
						tmp->left->color = BLACK;
					_rightRotate(toFix->parent);
					toFix = this->_root;
				}
			} 
		}
		if (toFix != this->_sentinal)
			toFix->color = BLACK;
	}

	pointer	_rightMin(pointer node) {

		if (node == this->_sentinal)
			return this->_sentinal;
		while (node->left != this->_sentinal)
			node = node->left;
		return (node);
	}

	bool	_redBlackTreeEraseAndRebalance(value_type const & val) {

		node_ptr		node = this->_root;
		node_ptr		toDelete = NULL;
		node_ptr		tmp;
		node_ptr		current;
		value_compare	comp;

		while (node != this->_sentinal) {

			if (comp(node->value, val)){

				node = node->right;
			}
			else if (comp(val, node->value)) {
	
				node = node->left;
			}
			else {

				toDelete = node;
				node = node->right;
			}
		}

		if (toDelete == NULL) {

			return false;
		}

		current = toDelete;
		int previousCurrentColor = current->color;
		if (toDelete->left == this->_sentinal) {

			tmp = toDelete->right;
			_insertNewNode(toDelete, toDelete->right);
		}
		else if (toDelete->right == this->_sentinal) {

			tmp = toDelete->left;
			_insertNewNode(toDelete, toDelete->left);
		}
		else {

			current = _rightMin(toDelete->right);
			previousCurrentColor = current->color;
			tmp = current->right;
			if (current->parent == toDelete) {

				if (tmp != this->_sentinal)
					tmp->parent = current;
			}
			else {
				_insertNewNode(current, current->right);
				current->right = toDelete->right;
				if (current->right->parent != this->_sentinal)
					current->right->parent = current;
			}

			_insertNewNode(toDelete, current);
			current->left = toDelete->left;
			if (current->left->parent != this->_sentinal)
				current->left->parent = current;
			current->color = toDelete->color;
		}

		allocator_type().destroy(toDelete);
		allocator_type().deallocate(toDelete, 1);
		this->_size--;

		if (previousCurrentColor == BLACK)
			_eraseRotation(tmp);
		
		this->_sentinal->parent = this->_root;
		return (true);
	}

	void	_swapContent(map &src) {

		this->clear();
		node_ptr newRoot = this->_root;
		node_ptr newSentinal = this->_sentinal;

		this->_root = src._root;
		this->_sentinal = src._sentinal;
		this->_keyCompare = src._keyCompare;
		this->_alloc = src._alloc;
		this->_size = src._size;
		src._root = newRoot;
		src._sentinal = newSentinal;
		src._size = 0;
	}

	void	_destroyNode(node_ptr node) {

		if (node == this->_sentinal)
			return ;
		this->_destroyNode(node->right);
		this->_destroyNode(node->left);
		allocator_type().destroy(node);
		allocator_type().deallocate(node, 1);
	}
};

//--------------------------RELATIONAL OPERATOR-------------------------------//

	// Operator ==
	template <class Key, class T, class Compare, class Alloc>
	bool operator== (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		if (lhs.size() == rhs.size()) {

			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
		return (false);
	}

	// Operator !=
	// a!=b -> !(a==b)
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		return (!(lhs == rhs));
	}

	// Operator <
	template <class Key, class T, class Compare, class Alloc>
	bool operator<  (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		if (lhs != rhs) {

			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
		return (false);
	}

	// Operator <=
	// a<=b -> !(b<a)
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		if (lhs == rhs)
			return (true);
		return (!(rhs < lhs));
	}

	// Operator >
	// a>b -> b<a
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		if (lhs == rhs)
			return (false);
		return (rhs < lhs);
	}

	// Operator >=
	// a>=b -> !(a<b)
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		if (lhs == rhs)
			return (true);
		return (!(lhs < rhs));
	}

	// Swap overload
	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {

		x.swap(y);
	}
};

#endif
