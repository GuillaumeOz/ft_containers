/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:40:05 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/30 16:21:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKITERATOR_HPP
# define REDBLACKITERATOR_HPP

#ifndef COUCOU
# define print(x)	std::cout << x << std::endl;//delete this
#endif

namespace ft {

enum e_tree_color {

	NONE,
	RED,
	BLACK
};

template <typename T>
struct setNode {//change for set node specification

	T							value;
	setNode*					parent;
	setNode*					left;
	setNode*					right;
	e_tree_color				color;

	setNode(T src = T()) : value(src) {

		parent = NULL;
		left = NULL;
		right = NULL;
		color = BLACK;
	}

	setNode(e_tree_color pColor,\
		setNode* pParent, setNode* pLeft, setNode* pRight) {

		color = pColor;
		parent = pParent;
		left = pLeft;
		right = pRight;
	}
};

template <typename T>
struct mapNode {

	T							value;
	mapNode*					parent;
	mapNode*					left;
	mapNode*					right;
	e_tree_color				color;

	// Default constructor
	mapNode(T src = T()) : value(src) {

		color = RED;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	// Fill constructor
	mapNode(T src, e_tree_color pColor,\
		mapNode* pParent, mapNode* pLeft, mapNode* pRight) : value(src){

		color = pColor;
		parent = pParent;
		left = pLeft;
		right = pRight;
	}

	// Sentinal node constructor
	mapNode(e_tree_color pColor,\
		mapNode* pParent, mapNode* pLeft, mapNode* pRight) {

		color = pColor;
		parent = pParent;
		left = pLeft;
		right = pRight;
	}
};

template<typename T, typename Node>
class redBlackIterator {
//--------------------------------TYPEDEF-------------------------------------//

	public :

		typedef T						value_type;
		typedef Node					node_type;
		typedef Node*					node_pointer;
		typedef value_type&				reference;
		typedef value_type*				pointer;
		typedef std::ptrdiff_t			difference_type;

//-------------------------------CONSTRUCTOR----------------------------------//

	// redBlackIterator(value_compare const & comp = value_compare()) : _comp(comp) {
	// 	_null = allocator_type().allocate(1);
	// 	allocator_type().construct(_null, node_type());
	// 	_root = _null;
	// }

	//Default constructor
	redBlackIterator(void) {

		return ;
	}

	//Pointer constructor
	redBlackIterator(node_type *src) {

		this->_node = src;
	}

	//Copy constructor
	redBlackIterator(redBlackIterator const &src) {

		*this = src;
	}

	virtual ~redBlackIterator(void) {

	}

//-------------------------ASSIGNATION OPERATOR-------------------------------//

	//const overload
	operator redBlackIterator<const T, node_type>(void) const {
		return (redBlackIterator<const T, node_type>(this->_node));
	}

	//node = node
	redBlackIterator	&operator=(redBlackIterator const &rhs) {

		this->_node = rhs._node;
		return (*this);
	}

//---------------------------COMP OPERATORS-----------------------------------//

	//node == node
	friend bool operator==(redBlackIterator const &lhs, redBlackIterator const &rhs) {
	
		if (lhs._node == rhs._node)
			return (true);
		return (false);
	}

	//node != node
	friend bool operator!=(redBlackIterator const &lhs, redBlackIterator const &rhs) {
	
		if (lhs._node != rhs._node)
			return (true);
		return (false);
	}

//---------------------------INCR OPERATORS-----------------------------------//

	//++node
	redBlackIterator	&operator++(void) {

		this->_node = _rbTreeIncrement(this->_node);
		return (*this);
	}

	//node++
	redBlackIterator	operator++(int) {

		redBlackIterator	tmp = (*this);

		++(*this);
		return (tmp);
	}

	//--node
	redBlackIterator	&operator--(void) {

		this->_node = _rbTreeDecrement(this->_node);
		return (*this);
	}

	//node--
	redBlackIterator	operator--(int) {

		redBlackIterator	tmp = (*this);

		--(*this);
		return (tmp);
	}

//------------------DEREFERENCING_AND_RANDOM_ACCESS_OPERATORS-----------------//

	//*(node->value)
	reference	operator*(void) const {

		return (this->_node->value);
	}

	//node->value
	pointer		operator->(void) const {

		return (&(this->operator*()));
	}

//--------------------------------VARIABLES-----------------------------------//

	private:

	Node		*_node;

//----------------------------PRIVATE FUNCTION--------------------------------//
	// if (head->right != NULL)
	// 	head = lastLeft(head->right);
	// else
	// {
	// 	node_type	*child = head;

	// 	head = head->parent;
	// 	while (head && child == head->right)
	// 	{
	// 		child = head;
	// 		head = head->parent;
	// 	}
	// }
	// return (*this);

	node_pointer	_rbTreeIncrement(node_pointer head) {

		if (head->right->color != NONE) {

			head = head->right;
			while (head->left->color != NONE)
				head = head->left;
		}
		else {

			node_pointer tmpRoot = head->parent;

			// this->_node = this->_node->parent;
			while (head == tmpRoot->right) {

				head = tmpRoot;
				tmpRoot = tmpRoot->parent;
			}
			if (head->right != tmpRoot)
				head = tmpRoot;
		}
		return (head);
	}

	node_pointer	_rbTreeDecrement(node_pointer head) {

		if (head->color == RED
			&& head->parent->parent == head)
			head = head->right;
		else if (head->left->color != NONE) {

			node_pointer	tmpLeft =  head->left;

			while (tmpLeft->right->color != NONE)
				tmpLeft = tmpLeft->right;
			head = tmpLeft;
		}
		else {

			node_pointer tmpRoot = head->parent;

			while (tmpRoot->color != NONE && head == tmpRoot->left) {

				head = tmpRoot;
				tmpRoot = tmpRoot->parent;
			}
			head = tmpRoot;
		}
		return (head);
	}

};

	template <typename T>
	mapNode<T>		*lastRight(mapNode<T>	*head) {

		while (head->parent->color != NONE)
			head = head->parent;
		while (head->right->color != NONE)
			head = head->right;
		head = head->right;
		return (head);
	}

	template <typename T>
	mapNode<T>		*lastLeft(mapNode<T>	*head) {

		while (head->parent->color != NONE)
			head = head->parent;
		while (head->left->color != NONE)
			head = head->left;
		return (head);
	}

};

#endif