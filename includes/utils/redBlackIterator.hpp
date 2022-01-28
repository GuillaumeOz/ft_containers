/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:40:05 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/28 19:17:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKITERATOR_HPP
# define REDBLACKITERATOR_HPP

#ifndef COUCOU
# define print(x)	std::cout << x << std::endl;
#endif

namespace ft {

enum e_tree_color {

	RED = false,
	BLACK = true
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
};

template <typename T>
struct mapNode {

	T							value;
	mapNode*					parent;
	mapNode*					left;
	mapNode*					right;
	e_tree_color				color;

	mapNode(T src = T()) : value(src) {

		parent = NULL;
		left = NULL;
		right = NULL;
		color = BLACK;
	}
};

template<typename T, typename Node>
class redBlackIterator {
// template<typename T, typename Node>
// class redBlackIterator : public ft::iterator<bidirectional_iterator_tag, T> {

// //--------------------------------TYPEDEF-------------------------------------//

// 	public :

// 	typedef T																					value_type;
// 	typedef Node																				node_type;
// 	typedef Node*																				node_pointer;
// 	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::difference_type	difference_type;
// 	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::pointer			pointer;
// 	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::reference			reference;
// 	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;

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
	// redBlackIterator(node_type *src);

//----------------------------PRIVATE FUNCTION--------------------------------//

	node_pointer	rbTreeIncrement(node_pointer head) {

		if (head->right != 0) {

			head = head->right;
			while (head->left != 0)
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
		
		// while (head->left != 0){}
		// 		head = head->left;
		// return (head);

	// if (this->_node->right != NULL)
	// 	this->_node = lastLeft(this->_node->right);
	// else
	// {
	// 	node_type	*child = this->_node;

	// 	this->_node = this->_node->parent;
	// 	while (this->_node && child == this->_node->right)
	// 	{
	// 		child = this->_node;
	// 		this->_node = this->_node->parent;
	// 	}
	// }
	// return (*this);
	}

//   static _Rb_tree_node_base*
//   local_Rb_tree_decrement(_Rb_tree_node_base* __x) throw ()
//   {
//     if (__x->_M_color == _S_red
//         && __x->_M_parent->_M_parent == __x)
//       __x = __x->_M_right;
//     else if (__x->_M_left != 0)
//       {
//         _Rb_tree_node_base* __y = __x->_M_left;
//         while (__y->_M_right != 0)
//           __y = __y->_M_right;
//         __x = __y;
//       }
//     else
//       {
//         _Rb_tree_node_base* __y = __x->_M_parent;
//         while (__x == __y->_M_left)
//           {
//             __x = __y;
//             __y = __y->_M_parent;
//           }
//         __x = __y;
//       }
//     return __x;
//   }

	node_pointer	rbTreeDecrement(node_pointer head) {

		if (head->color == RED
			&& head->parent->parent == head)
			head = head->right;
		else if (head->left != 0) {

			node_pointer	tmpLeft =  head->left;

			while (tmpLeft->right != 0)
				tmpLeft = tmpLeft->right;
			head = tmpLeft;
		}
		else {

			node_pointer tmpRoot = head->parent;

			while (tmpRoot && head == tmpRoot->left) {

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

		while (head->right != NULL)
			head = head->right;
		return (head);
	}

	template <typename T>
	mapNode<T>		*lastLeft(mapNode<T>	*head) {

		while (head->left != NULL)
			head = head->left;
		return (head);
	}

};

#endif