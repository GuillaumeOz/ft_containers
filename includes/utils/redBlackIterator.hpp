/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:40:05 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/21 15:21:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKITERATOR_HPP
# define REDBLACKITERATOR_HPP

namespace ft {

enum e_tree_color {

	RED = false,
	BLACK = true
};

template <typename T>
struct setNode {//change for set node specification

	T*							valptr;//switch for element if its too slow
	setNode*					parent;
	setNode*					left;
	setNode*					right;
	e_tree_color				color;

	setNode(T* src = T()) {

		valptr = src;
		parent(NULL);
		left(NULL);
		right(NULL);
		color = BLACK;
	}
};

template <typename T>
struct mapNode {

	T*							valptr;//switch for element if its too slow
	mapNode*					parent;
	mapNode*					left;
	mapNode*					right;
	e_tree_color				color;

	mapNode(T* src = T()) {

		valptr = src;
		parent(NULL);
		left(NULL);
		right(NULL);
		color = BLACK;
	}
};

template<typename T, typename Node>
class redBlackIterator : public ft::iterator<bidirectional_iterator_tag, T> {

//--------------------------------TYPEDEF-------------------------------------//

	public :

	typedef T																					value_type;
	typedef Node																				node_type;
	typedef Node*																				node_pointer;
	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::difference_type	difference_type;
	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::pointer			pointer;
	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::reference			reference;
	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;

//-------------------------------CONSTRUCTOR----------------------------------//

	//Default constructor
	redBlackIterator(void) : _node(NULL) {

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

		this->_node = rbTreeIncrement(this->_node);
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

		this->_node = rbTreeDecrement(this->_node);
		return (*this);
	}

	//node--
	redBlackIterator	operator--(int) {

		redBlackIterator	tmp = (*this);

		--(*this);
		return (tmp);
	}

//------------------DEREFERENCING_AND_RANDOM_ACCESS_OPERATORS-----------------//

	//*(node->valptr)
	reference	operator*(void) const {

		return (*this->_node->valptr);
	}

	//node->valptr
	pointer		operator->(void) const {

		return (this->operator*());
	}

//--------------------------------VARIABLES-----------------------------------//

	private:

	node_pointer		_node;

//----------------------------PRIVATE FUNCTION--------------------------------//

	node_pointer	lastRight(node_pointer head) {

		while (head->right != NULL)
			head = head->right;
		return (head);
	}

	node_pointer	lastLeft(node_pointer head) {

		while (head->left != NULL)
			head = head->left;
		return (head);
	}

	node_pointer	rbTreeIncrement(node_pointer head) {

		if (head->right != NULL) {

			head = head->right;
			while (head->left != NULL)
				head = head->left;
		}
		else {

			node_pointer tmpRoot = head->parent;

			while (head == tmpRoot->right) {

				head = tmpRoot;
				tmpRoot = tmpRoot->parent;
			}
			if (head->right != tmpRoot)
				head = tmpRoot;
		}
		return (head);
	}

	node_pointer	rbTreeDecrement(node_pointer head) {

		if (head->color == RED
			&& head->parent->parent == head)
			head = head->right;
		else if (head->left != 0) {

			node_pointer	tmpLeft =  lastRight(head->left);

			head = tmpLeft;
		}
		else {

			node_pointer tmpRoot = head->parent;

			while (head == tmpRoot->left) {

				head = tmpRoot;
				tmpRoot = tmpRoot->parent;
			}
			head = tmpRoot;
		}
		return (head);
	}

};

};

#endif