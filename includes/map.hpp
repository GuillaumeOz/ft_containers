/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:57:47 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/30 18:35:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP


# include "utils/lexicographical_compare.hpp"
# include "utils/equal_compare.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/iteratorTraits.hpp"
# include "utils/vectorIterator.hpp"
# include "utils/reverseIterator.hpp"
# include "utils/utils.hpp"
# include "vector.hpp"
# include "stack.hpp"
# include "utils/pair.hpp"
# include "utils/make_pair.hpp"
# include "utils/redBlackIterator.hpp"
# include "ft_containers.hpp"

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

			// friend class map<Key, T, Compare, Alloc>;//remove friend here
		public:
			Compare		comp;

			value_compare(Compare __c = key_compare()) : comp(__c) {

			}

			bool operator()(const value_type& __x, const value_type& __y) const {

				return comp(__x.first, __y.first);
			}
	};

//------------------------------CONSTRUCTORS----------------------------------//

	// Empty constructor
	explicit map(key_compare const &comp = key_compare(),
				allocator_type const &alloc = allocator_type()) {

		this->_sentinal = allocator_type().allocate(1);
		allocator_type().construct(this->_sentinal, node_type(NONE, NULL, NULL, NULL));

		this->_root = NULL;
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

		this->_root = NULL;
		this->_keyCompare = comp;
		this->_alloc = alloc;
		this->_size = 0;

		this->insert(first, last);
	}

	// Copy Constructor
	map(map const &src) {

		this->_sentinal = allocator_type().allocate(1);
		allocator_type().construct(this->_sentinal, node_type(NONE, NULL, NULL, NULL));

		this->_root = NULL;
		this->_keyCompare = src._keyCompare;
		this->_alloc = src._alloc;
		this->_size = 0;

		this->insert(src.end(), src.begin());
	}

//-------------------------------DESTRUCTOR-----------------------------------//

	~map(void) {

		this->clear();//delete all nodes
		// allocator_type().destroy(this->_root);
		// allocator_type().deallocate(this->_root, 1);//not necessary ?
	}

//--------------------------ITERATORS FUNCTIONS-------------------------------//

	iterator begin() {

		return (iterator(lastLeft(this->_root), this->_sentinal));
	}

	const_iterator begin() const {

		return (const_iterator(lastLeft(this->_root), this->_sentinal));
	}

	iterator end() {

		return ((iterator(this->_sentinal)));
	}

	const_iterator end() const {

		return ((const_iterator(this->_sentinal)));
	}

	reverse_iterator rbegin() {

		return (reverse_iterator(this->_sentinal));
	}

	const_reverse_iterator rbegin() const {

		return (const_reverse_iterator(this->_sentinal));
	}

	reverse_iterator rend() {

		return (reverse_iterator(lastLeft(this->_root), this->_sentinal));
	}

	const_reverse_iterator rend() const {

		return (const_reverse_iterator(lastLeft(this->_root), this->_sentinal));
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

		// return (std::numeric_limits<difference_type>::max() / (sizeof(node_type)));
		// return allocator_type().max_size();
		return (std::numeric_limits<difference_type>::max() / 20);
		// return (this->_alloc.max_size());
	}

//-------------------------ELEMENT ACCESS FUNCTION----------------------------//

	mapped_type&	operator[](const key_type& k) {

		return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
		// return (this->insert(value_type(k, mapped_type()))).first->second;
	}

//---------------------------MODIFIERS FUNCTIONS------------------------------//

	ft::pair<iterator, bool> insert(const value_type& val) {
		if (this->_mapInsertUnique(val) == false)
			return (ft::make_pair(find(val.first), false));
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

		this->erase(position->_node->first);
	}

	// key erase
	size_type erase (const key_type& k) {

		iterator itKey = this->find(k);

		if (itKey != this->end()) {

			this->_redBlackTreeEraseAndRebalance(itKey._node);
			return (1);
		}
		return (0);
	}

	// range erase
	void erase (iterator first, iterator last) {

		while (first != last) {//test this function

			first = find(first->first);
			erase(first);
			first++;//can have some bugs here
		}
	}

	void swap (map& x) {

		node_type *tmp;

		tmp->_root = x._root;
		x._root = this->_root;
		this->_root = tmp->_root;//test this
	}

	void clear() {

		// this->_root->color = RED;
		if (this->_root != NULL)
			this->_destroyNode(this->_root);
		this->_root = NULL;
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

				// itBegin++;
				return (itBegin);
			}
		}
		return (itEnd);
	}

	pair<iterator,iterator>				equal_range (const key_type& k) {

		pair<iterator, iterator> ret;

		ret.first = this->lower_bound(k);
		ret.second = this->upper_bound(k);

		return (ret);
	}

	pair<const_iterator,const_iterator>	equal_range (const key_type& k) const {

		pair<const_iterator, const_iterator> ret;

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

	void	_leftRotate(node_ptr node) {
		node_ptr	tmp = node->right;
		
		node->right = tmp->left;
		if (tmp->left != this->_sentinal)
			tmp->left->parent = node;

		tmp->parent = node->parent;
		// print("LALLA")

		if (node->parent == this->_sentinal)
			_root = tmp;
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
		// print("ICICI")
		if (node->parent == this->_sentinal)
			_root = tmp;
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
		if (this->_root == NULL) {

			this->_root = toInsert;
			this->_sentinal->parent = this->_root;
			this->_root->color = BLACK;
			// print("TRUE")
			// print(this->_sentinal)
			// print(this->_root)
			// print("TRUE")
			return (true);
		}
		while (root != this->_sentinal) {
			current = root;
			if (comp(toInsert->value, root->value))
				root = root->left;
			else if (comp(root->value, toInsert->value))
				root = root->right;
			else {
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

		//Assign Black color to _root node
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
				if (tmp != this->_sentinal && tmp->color == RED) {//add sentinal protect
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

				if (tmp != this->_sentinal && tmp->color == RED) {//add sentinal protect
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
			if (toFix == _root)
				break ;
		}
		this->_root->color = BLACK;
	}

	void	_redBlackTreeEraseAndRebalance(node_ptr rmNode) {
		node_ptr	replaceNode = NULL;
		node_ptr	*rmPlace = &this->_root;

		print("ERAAASEEE")
		--this->_size;
		if (rmNode->parent)
			rmPlace = (rmNode->parent->left == rmNode ? &rmNode->parent->left : &rmNode->parent->right);
		if (rmNode->left == NULL && rmNode->right == NULL)
			;
		else if (rmNode->left == NULL) // left == NULL && right != NULL
			replaceNode = rmNode->right;
		else // left != NULL && right ?= NULL
		{
			replaceNode = lastRight(rmNode->left);
			if (replaceNode != rmNode->left)
				if ((replaceNode->parent->right = replaceNode->left))
					replaceNode->left->parent = replaceNode->parent;
		}
		if (replaceNode)
		{
			replaceNode->parent = rmNode->parent;
			if (rmNode->left && rmNode->left != replaceNode)
			{
				replaceNode->left = rmNode->left;
				replaceNode->left->parent = replaceNode;
			}
			if (rmNode->right && rmNode->right != replaceNode)
			{
				replaceNode->right = rmNode->right;
				replaceNode->right->parent = replaceNode;
			}
		}
		*rmPlace = replaceNode;
		allocator_type().destroy(rmNode);
		allocator_type().deallocate(rmNode, 1);
	}

	void	_destroyNode(node_ptr node) {

		// print(node->color)
		if (node == this->_sentinal)
			return ;
		this->_destroyNode(node->right);
		this->_destroyNode(node->left);
		allocator_type().destroy(node);
		allocator_type().deallocate(node, 1);
	}

};

};

#endif
