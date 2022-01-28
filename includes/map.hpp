/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:57:47 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/28 19:32:45 by gozsertt         ###   ########.fr       */
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
#include "ft_containers.hpp"

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

			// std::less<Key>
			value_compare(Compare __c = key_compare()) : comp(__c) {

			}

			bool operator()(const value_type& __x, const value_type& __y) const {

				return comp(__x.first, __y.first);
			}
	};

//------------------------------CONSTRUCTORS----------------------------------//

	// Default constructor
	// map(void) {

	// 	this->_root = NULL;
	// 	this->_size = 0;

	// 	this->_root = new node_type;
	// }

	// Comparison object Allocator object constructor
	explicit map(key_compare const &comp, allocator_type const &alloc) {

		// this->_root = NULL;
		this->_keyCompare = comp;
		this->_alloc = alloc;
		// this->_size = 0;

		// this->_root = new node_type;
	}

	// Range constructor
	template <class InputIterator>
	map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){

		// this->_root = NULL;
		this->_keyCompare = comp;
		this->_alloc = alloc;
		// this->_size = 0;

		// this->_root = new node_type;
		this->insert(first, last);
	}

	// Copy Constructor
	map(map const &src) {

		// this->_root = NULL;
		this->_keyCompare = key_compare();
		this->_alloc = allocator_type();
		// this->_size = 0;

		this->_root = new node_type;
		*this = src;//Improve later
	}

//-------------------------------DESTRUCTOR-----------------------------------//

	~map(void) {

		this->clear();//delete all nodes
		delete (this->_root);//not necessary ?
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

	// std::numeric_limits<difference_type>::max() / (sizeof(node_type))
		return (this->_alloc.max_size());
	}

//-------------------------ELEMENT ACCESS FUNCTION----------------------------//

	mapped_type&	operator[](const key_type& k) {

		iterator it = lower_bound(k);

		it = insert(it, value_type(k, mapped_type()));

		return ((*it).second);
		// return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
		// return (this->insert(value_type(k, mapped_type()))).first->second;
	}

//---------------------------MODIFIERS FUNCTIONS------------------------------//

	// // single element insert
	// ft::pair<iterator,bool>	insert(const value_type& x) {

	// 	return (this->_mapInsertUnique(x));
	// }

	// // with hint insert
	// iterator insert (iterator position, const value_type& val) {

	// 	// static_cast<void>(position);
	// 	(void)position;
	// 	return this->insert(val).first;//redo
	// }

	// // range insert
	// template<typename InputIterator>
	// void insert(InputIterator first, InputIterator last) {

	// 	while (first != last) {

	// 		this->insert(*first);
	// 		first++;
	// 	}
	// }

	ft::pair<iterator, bool> insert(const value_type& val) {
		if (this->_mapInsertUnique(val) == false)
			return ft::make_pair(find(val.first), false);
		return ft::make_pair(find(val.first), true);
	}

	iterator insert(iterator position, const value_type& val) {
		(void)position;
		return insert(val).first;
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last) {
		for (; first != last; first++)
			insert(*first);
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

		(void)x;
	}

	void clear() {

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

			if (!this->_keyCompare(itBegin->first, k) && !this->_keyCompare(k, itBegin->first))
				return (itBegin);
		}
		return (itEnd);
	}

	const_iterator	find(const key_type& k) const {

		const_iterator itEnd = this->end();

		for (const_iterator itBegin = this->begin(); itBegin != itEnd; itBegin++) {

			if (!this->_keyCompare(itBegin->first, k) && !this->_keyCompare(k, itBegin->first))
				return (itBegin);
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

			if (this->_keyCompare(k, itBegin->first))
				return (itBegin);
		}
		return (itEnd);
	}

	const_iterator	upper_bound (const key_type& k) const {

		const_iterator itEnd = this->end();

		for (const_iterator itBegin = this->begin(); itBegin != itEnd; itBegin++) {

			if (this->_keyCompare(k, itBegin->first))
				return (itBegin);
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
	allocator_type			_alloc;
	key_compare				_keyCompare;
	size_type				_size;

	// void	_redBlackTreeInsertAndRebalance(node_ptr newNode) {

	// 	node_ptr	*parentNode = &this->_root;//rebalance the tree if needed
	// 	node_ptr	*currentNode = &this->_root;
	// 	node_ptr	lastNode = lastRight(this->_root);
	// 	bool		leftWay = 0;

	// 	while ((*currentNode) && (*currentNode) != lastNode) {

	// 		parentNode = currentNode;
	// 		leftWay = this->_keyCompare(newNode->value.first, (*currentNode)->value.first);
	// 		if (leftWay == true)
	// 			currentNode = &(*currentNode)->left;
	// 		else
	// 			currentNode = &(*currentNode)->right;
	// 	}
	// 	if (currentNode) {

	// 		(*currentNode) = newNode;
	// 		newNode->parent = lastNode->parent;
	// 		lastNode->parent = lastRight(newNode);
	// 		lastRight(newNode)->right = lastNode;
	// 	}
	// 	else {

	// 		newNode->parent = (*parentNode);
	// 		(*currentNode) = newNode;
	// 	}
	// 	this->_size++;
	// }

	void	leftRotate(node_ptr node) {
		node_ptr	tmp = node->right;
		
		node->right = tmp->left;
		if (tmp->left != NULL)
			tmp->left->parent = node;

		tmp->parent = node->parent;
		if (node->parent == NULL)
			_root = tmp;
		else if (node == node->parent->left)
			node->parent->left = tmp;
		else
			node->parent->right = tmp;

		tmp->left = node;
		node->parent = tmp;
	}

	void	rightRotate(node_ptr node) {

		node_ptr	tmp = node->left;

		node->left = tmp->right;
		if (tmp->right != NULL)
			tmp->right->parent = node;

		tmp->parent = node->parent;
		if (node->parent == NULL)
			_root = tmp;
		else if (node == node->parent->right)
			node->parent->right = tmp;
		else
			node->parent->left = tmp;

		tmp->right = node;
		node->parent = tmp;
	}

	// bool	insert(value_type const & val) {
	// 	pointer toInsert = allocator_type().allocate(1);
	// 	allocator_type().construct(toInsert, node_type(val, RED, ft_nullptr, _null, _null)); // new node must be red

	// 	pointer current = ft_nullptr;
	// 	pointer root = _root;

	// 	while (root != _null) {
	// 		current = root;
	// 		if (this->_keyCompare(toInsert->val, root->val))
	// 			root = root->left;
	// 		else if (this->_keyCompare(root->val, toInsert->val))
	// 			root = root->right;
	// 		else {
	// 			allocator_type().destroy(toInsert);
	// 			allocator_type().deallocate(toInsert, 1);
	// 			return false;
	// 		}
	// 	}

	// 	toInsert->parent = current;
	// 	if (current == ft_nullptr)
	// 		_root = toInsert;
	// 	else if (this->_keyCompare(toInsert->val, current->val))
	// 		current->left = toInsert;
	// 	else
	// 		current->right = toInsert;

	// 	if (toInsert->parent == ft_nullptr) {
	// 		toInsert->color = BLACK_NODE;
	// 		return true;
	// 	}

	// 	if (toInsert->parent->parent == ft_nullptr)
	// 		return true;

	// 	fixInsert(toInsert);
	// 	return true;
	// }

	bool	_mapInsertUnique(const value_type &val) {

		// node_ptr toInsert = allocator_type().allocate(1);
		// allocator_type().construct(toInsert, node_type(val, RED, NULL, NULL, NULL)); // new node must be red

		node_ptr toInsert = new node_type(val);
		toInsert->color = RED;

		value_compare comp;

		node_ptr current = NULL;
		node_ptr root = _root;

		while (root != NULL) {
			current = root;
			if (comp(toInsert->value, root->value))
				root = root->left;
			else if (comp(root->value, toInsert->value))
				root = root->right;
			else {
				// allocator_type().destroy(toInsert);
				// allocator_type().deallocate(toInsert, 1);
				delete toInsert;
				return false;
			}
		}

		toInsert->parent = current;
		if (current == NULL)
			_root = toInsert;
		else if (comp(toInsert->value, current->value))
			current->left = toInsert;
		else
			current->right = toInsert;

		if (toInsert->parent == NULL) {
			toInsert->color = BLACK;
			return true;
		}

		if (toInsert->parent->parent == NULL)
			return true;

		_redBlackTreeInsertAndRebalance(toInsert);
		return true;
	}

	void	_redBlackTreeInsertAndRebalance(node_ptr toFix) {

		node_ptr	tmp;

		while (toFix->parent->color == RED) {
			if (toFix->parent == toFix->parent->parent->right) {
				tmp = toFix->parent->parent->left;
				if (tmp->color == RED) {
					tmp->color = BLACK;
					toFix->parent->color = BLACK;
					toFix->parent->parent->color = RED;
					toFix = toFix->parent->parent;
				}
				else {
					if (toFix == toFix->parent->left) {
						toFix = toFix->parent;
						rightRotate(toFix);
					}
					toFix->parent->color = BLACK;
					toFix->parent->parent->color = RED;
					leftRotate(toFix->parent->parent);
				}
			}
			else {
				tmp = toFix->parent->parent->right;

				if (tmp->color == RED) {
					tmp->color = BLACK;
					toFix->parent->color = BLACK;
					toFix->parent->parent->color = RED;
					toFix = toFix->parent->parent;	
				}
				else {
					if (toFix == toFix->parent->right) {
						toFix = toFix->parent;
						leftRotate(toFix);
					}
					toFix->parent->color = BLACK;
					toFix->parent->parent->color = RED;
					rightRotate(toFix->parent->parent);
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
		delete rmNode;
	}

	void	_destroyNode(node_ptr node) {

		if (node == NULL)//fix const
			return ;
		_destroyNode(node->right);
		_destroyNode(node->left);
		delete node;//test leaks -> there are some leaks
	}

};

};

#endif




		// print("ROOT")

		// node_ptr	testNode = this->_root;

		// 	print("key :");print(testNode->value.first)
		// 	print("value :");print(testNode->value.second)

		// print("RIGHT")

		// testNode = this->_root->right;

		// while (testNode != NULL) {

		// 	print("key :");print(testNode->value.first)
		// 	print("value :");print(testNode->value.second)
		// 	testNode = testNode->right;
		// }

		// print("LEFT")

		// testNode = this->_root->left;

		// while (testNode != NULL) {

		// 	print("key :");print(testNode->value.first)
		// 	print("value :");print(testNode->value.second)
		// 	testNode = testNode->left;
		// }

		// print("OUT")








//   _Rb_tree_node_base*
//   _Rb_tree_rebalance_for_erase(_Rb_tree_node_base* const __z,
//                                _Rb_tree_node_base& __header) throw ()
// 		node_ptr* _redBlackTreeEraseAndRebalance(node_ptr toDeleteNode) {

// 		node_ptr *& __root = __header._M_parent;
// 		node_ptr *& __leftmost = __header._M_left;
// 		node_ptr *& __rightmost = __header._M_right;
// 		node_ptr* __y = __z;
// 		node_ptr* __x = 0;
// 		node_ptr* __x_parent = 0;
// 		if (__y->_M_left == 0)     // __z has at most one non-null child. y == z.
// 		__x = __y->_M_right;     // __x might be null.
// 		else
// 		if (__y->_M_right == 0)  // __z has exactly one non-null child. y == z.
// 			__x = __y->_M_left;    // __x is not null.
// 		else
// 			{
// 			// __z has two non-null children.  Set __y to
// 			__y = __y->_M_right;   //   __z's successor.  __x might be null.
// 			while (__y->_M_left != 0)
// 				__y = __y->_M_left;
// 			__x = __y->_M_right;
// 			}
// 		if (__y != __z)
// 		{
// 			// relink y in place of z.  y is z's successor
// 			__z->_M_left->_M_parent = __y;
// 			__y->_M_left = __z->_M_left;
// 			if (__y != __z->_M_right)
// 			{
// 				__x_parent = __y->_M_parent;
// 				if (__x) __x->_M_parent = __y->_M_parent;
// 				__y->_M_parent->_M_left = __x;   // __y must be a child of _M_left
// 				__y->_M_right = __z->_M_right;
// 				__z->_M_right->_M_parent = __y;
// 			}
// 			else
// 			__x_parent = __y;
// 			if (__root == __z)
// 			__root = __y;
// 			else if (__z->_M_parent->_M_left == __z)
// 			__z->_M_parent->_M_left = __y;
// 			else
// 			__z->_M_parent->_M_right = __y;
// 			__y->_M_parent = __z->_M_parent;
// 			std::swap(__y->_M_color, __z->_M_color);
// 			__y = __z;
// 			// __y now points to node to be actually deleted
// 		}
// 		else
// 		{                        // __y == __z
// 			__x_parent = __y->_M_parent;
// 			if (__x)
// 			__x->_M_parent = __y->_M_parent;
// 			if (__root == __z)
// 			__root = __x;
// 			else
// 			if (__z->_M_parent->_M_left == __z)
// 				__z->_M_parent->_M_left = __x;
// 			else
// 				__z->_M_parent->_M_right = __x;
// 			if (__leftmost == __z)
// 			{
// 				if (__z->_M_right == 0)        // __z->_M_left must be null also
// 				__leftmost = __z->_M_parent;
// 				// makes __leftmost == _M_header if __z == __root
// 				else
// 				__leftmost = _Rb_tree_node_base::_S_minimum(__x);
// 			}
// 			if (__rightmost == __z)
// 			{
// 				if (__z->_M_left == 0)         // __z->_M_right must be null also
// 				__rightmost = __z->_M_parent;
// 				// makes __rightmost == _M_header if __z == __root
// 				else                      // __x == __z->_M_left
// 				__rightmost = _Rb_tree_node_base::_S_maximum(__x);
// 			}
// 		}
// 		if (__y->_M_color != _S_red)
// 		{
// 			while (__x != __root && (__x == 0 || __x->_M_color == _S_black))
// 			if (__x == __x_parent->_M_left)
// 				{
// 				_Rb_tree_node_base* __w = __x_parent->_M_right;
// 				if (__w->_M_color == _S_red)
// 					{
// 					__w->_M_color = _S_black;
// 					__x_parent->_M_color = _S_red;
// 					local_Rb_tree_rotate_left(__x_parent, __root);
// 					__w = __x_parent->_M_right;
// 					}
// 				if ((__w->_M_left == 0 ||
// 					__w->_M_left->_M_color == _S_black) &&
// 					(__w->_M_right == 0 ||
// 					__w->_M_right->_M_color == _S_black))
// 					{
// 					__w->_M_color = _S_red;
// 					__x = __x_parent;
// 					__x_parent = __x_parent->_M_parent;
// 					}
// 				else
// 					{
// 					if (__w->_M_right == 0
// 						|| __w->_M_right->_M_color == _S_black)
// 						{
// 						__w->_M_left->_M_color = _S_black;
// 						__w->_M_color = _S_red;
// 						local_Rb_tree_rotate_right(__w, __root);
// 						__w = __x_parent->_M_right;
// 						}
// 					__w->_M_color = __x_parent->_M_color;
// 					__x_parent->_M_color = _S_black;
// 					if (__w->_M_right)
// 						__w->_M_right->_M_color = _S_black;
// 					local_Rb_tree_rotate_left(__x_parent, __root);
// 					break;
// 					}
// 				}
// 			else
// 				{
// 				// same as above, with _M_right <-> _M_left.
// 				_Rb_tree_node_base* __w = __x_parent->_M_left;
// 				if (__w->_M_color == _S_red)
// 					{
// 					__w->_M_color = _S_black;
// 					__x_parent->_M_color = _S_red;
// 					local_Rb_tree_rotate_right(__x_parent, __root);
// 					__w = __x_parent->_M_left;
// 					}
// 				if ((__w->_M_right == 0 ||
// 					__w->_M_right->_M_color == _S_black) &&
// 					(__w->_M_left == 0 ||
// 					__w->_M_left->_M_color == _S_black))
// 					{
// 					__w->_M_color = _S_red;
// 					__x = __x_parent;
// 					__x_parent = __x_parent->_M_parent;
// 					}
// 				else
// 					{
// 					if (__w->_M_left == 0 || __w->_M_left->_M_color == _S_black)
// 						{
// 						__w->_M_right->_M_color = _S_black;
// 						__w->_M_color = _S_red;
// 						local_Rb_tree_rotate_left(__w, __root);
// 						__w = __x_parent->_M_left;
// 						}
// 					__w->_M_color = __x_parent->_M_color;
// 					__x_parent->_M_color = _S_black;
// 					if (__w->_M_left)
// 						__w->_M_left->_M_color = _S_black;
// 					local_Rb_tree_rotate_right(__x_parent, __root);
// 					break;
// 					}
// 				}
// 			if (__x) __x->_M_color = _S_black;
// 		}
// 		return __y;
// 	}



// 	void
//   _Rb_tree_insert_and_rebalance(const bool          __insert_left,
//                                 _Rb_tree_node_base* __x,
//                                 _Rb_tree_node_base* __p,
//                                 _Rb_tree_node_base& __header) throw ()
//   {
//     _Rb_tree_node_base *& __root = __header._M_parent;
//     // Initialize fields in new node to insert.
//     __x->_M_parent = __p;
//     __x->_M_left = 0;
//     __x->_M_right = 0;
//     __x->_M_color = _S_red;
//     // Insert.
//     // Make new node child of parent and maintain root, leftmost and
//     // rightmost nodes.
//     // N.B. First node is always inserted left.
//     if (__insert_left)
//       {
//         __p->_M_left = __x; // also makes leftmost = __x when __p == &__header
//         if (__p == &__header)
//         {
//             __header._M_parent = __x;
//             __header._M_right = __x;
//         }
//         else if (__p == __header._M_left)
//           __header._M_left = __x; // maintain leftmost pointing to min node
//       }
//     else
//       {
//         __p->_M_right = __x;
//         if (__p == __header._M_right)
//           __header._M_right = __x; // maintain rightmost pointing to max node
//       }
//     // Rebalance.
//     while (__x != __root
//            && __x->_M_parent->_M_color == _S_red)
//       {
//         _Rb_tree_node_base* const __xpp = __x->_M_parent->_M_parent;
//         if (__x->_M_parent == __xpp->_M_left)
//           {
//             _Rb_tree_node_base* const __y = __xpp->_M_right;
//             if (__y && __y->_M_color == _S_red)
//               {
//                 __x->_M_parent->_M_color = _S_black;
//                 __y->_M_color = _S_black;
//                 __xpp->_M_color = _S_red;
//                 __x = __xpp;
//               }
//             else
//               {
//                 if (__x == __x->_M_parent->_M_right)
//                   {
//                     __x = __x->_M_parent;
//                     local_Rb_tree_rotate_left(__x, __root);
//                   }
//                 __x->_M_parent->_M_color = _S_black;
//                 __xpp->_M_color = _S_red;
//                 local_Rb_tree_rotate_right(__xpp, __root);
//               }
//           }
//         else
//           {
//             _Rb_tree_node_base* const __y = __xpp->_M_left;
//             if (__y && __y->_M_color == _S_red)
//               {
//                 __x->_M_parent->_M_color = _S_black;
//                 __y->_M_color = _S_black;
//                 __xpp->_M_color = _S_red;
//                 __x = __xpp;
//               }
//             else
//               {
//                 if (__x == __x->_M_parent->_M_left)
//                   {
//                     __x = __x->_M_parent;
//                     local_Rb_tree_rotate_right(__x, __root);
//                   }
//                 __x->_M_parent->_M_color = _S_black;
//                 __xpp->_M_color = _S_red;
//                 local_Rb_tree_rotate_left(__xpp, __root);
//               }
//           }
//       }
//     __root->_M_color = _S_black;
//   }
