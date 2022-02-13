/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:40:05 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/12 19:40:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKITERATOR_HPP
#define REDBLACKITERATOR_HPP

namespace ft
{

	enum e_tree_color
	{

		NONE,
		RED,
		BLACK
	};

	template <typename T>
	struct setNode
	{

		T value;
		setNode *parent;
		setNode *left;
		setNode *right;
		e_tree_color color;

		// Default constructor
		setNode(T src = T()) : value(src)
		{

			parent = NULL;
			left = NULL;
			right = NULL;
			color = RED;
		}

		// Fill constructor
		setNode(T src, e_tree_color pColor,
				setNode *pParent, setNode *pLeft, setNode *pRight) : value(src)
		{

			color = pColor;
			parent = pParent;
			left = pLeft;
			right = pRight;
		}

		// Sentinal node constructor
		setNode(e_tree_color pColor,
				setNode *pParent, setNode *pLeft, setNode *pRight)
		{

			color = pColor;
			parent = pParent;
			left = pLeft;
			right = pRight;
		}
	};

	template <typename T>
	struct mapNode
	{

		T value;
		mapNode *parent;
		mapNode *left;
		mapNode *right;
		e_tree_color color;

		// Default constructor
		mapNode(T src = T()) : value(src)
		{

			color = RED;
			parent = NULL;
			left = NULL;
			right = NULL;
		}

		// Fill constructor
		mapNode(T src, e_tree_color pColor,
				mapNode *pParent, mapNode *pLeft, mapNode *pRight) : value(src)
		{

			color = pColor;
			parent = pParent;
			left = pLeft;
			right = pRight;
		}

		// Sentinal node constructor
		mapNode(e_tree_color pColor,
				mapNode *pParent, mapNode *pLeft, mapNode *pRight)
		{

			color = pColor;
			parent = pParent;
			left = pLeft;
			right = pRight;
		}
	};

	template <typename T, typename Node>
	class redBlackIterator
	{
		//--------------------------------TYPEDEF-------------------------------------//

	public:
		typedef T value_type;
		typedef Node node_type;
		typedef Node *node_pointer;
		typedef value_type &reference;
		typedef value_type *pointer;
		typedef std::ptrdiff_t difference_type;

		//-------------------------------CONSTRUCTOR----------------------------------//

		// Default constructor
		redBlackIterator(void) {

		}

		// Pointer constructor
		redBlackIterator(node_type *src, node_type *sentinal = NULL) {

			this->_node = src;
			if (sentinal != NULL)
			{
				this->_sentinal = sentinal;
			}
		}

		// Copy constructor
		redBlackIterator(redBlackIterator const &src) {

			*this = src;
		}

		virtual ~redBlackIterator(void) {

		}

		//-------------------------ASSIGNATION OPERATOR-------------------------------//

		// const overload
		operator redBlackIterator<const T, Node>(void)
		{
			return (redBlackIterator<const T, Node>(this->_node, this->_sentinal));
		}

		// node = node
		redBlackIterator &operator=(redBlackIterator const &rhs)
		{

			this->_node = rhs._node;
			if (rhs._sentinal != NULL)
				this->_sentinal = rhs._sentinal;
			return (*this);
		}

		//---------------------------COMP OPERATORS-----------------------------------//

		// node == node
		friend bool operator==(redBlackIterator const &lhs, redBlackIterator const &rhs)
		{

			if (lhs._node == rhs._node)
				return (true);
			return (false);
		}

		// node != node
		friend bool operator!=(redBlackIterator const &lhs, redBlackIterator const &rhs)
		{

			if (lhs._node != rhs._node)
				return (true);
			return (false);
		}

		//---------------------------INCR OPERATORS-----------------------------------//

		//++node
		redBlackIterator &operator++(void)
		{

			this->_node = _rbTreeIncrement(this->_node);
			return (*this);
		}

		// node++
		redBlackIterator operator++(int)
		{

			redBlackIterator tmp = (*this);

			++(*this);
			return (tmp);
		}

		//--node
		redBlackIterator &operator--(void)
		{
			this->_node = _rbTreeDecrement(this->_node);
			return (*this);
		}

		// node--
		redBlackIterator operator--(int)
		{

			redBlackIterator tmp = (*this);

			--(*this);
			return (tmp);
		}

		//------------------DEREFERENCING_AND_RANDOM_ACCESS_OPERATORS-----------------//

		//*(node->value)
		reference operator*(void) const
		{

			return (this->_node->value);
		}

		// node->value
		pointer operator->(void) const
		{

			return (&(this->operator*()));
		}

		//--------------------------------VARIABLES-----------------------------------//

		public:
		Node *_node;
		Node *_sentinal;

		//----------------------------PRIVATE FUNCTION--------------------------------//

		node_pointer _rbTreeIncrement(node_pointer head)
		{

			if (head->right != this->_sentinal) {

				head = lastLeft(head->right);
			}
			else
			{

				node_type *child = head;

				head = head->parent;
				while (head != this->_sentinal && child == head->right)
				{

					child = head;
					head = head->parent;
				}
			}

			return (head);
		}

		node_pointer _rbTreeDecrement(node_pointer head)
		{
			if (head == this->_sentinal)
			{
				while (head->parent != this->_sentinal)
					head = head->parent;
				head = lastRight(head);
			}
			else if (head->left != this->_sentinal)
			{
				head = lastRight(head->left);
			}
			else
			{
				node_type *child = head;

				head = head->parent;
				while (head != this->_sentinal && child == head->left)
				{

					child = head;
					head = head->parent;
				}
			}
			return (head);
		}
	};

	template <typename T>
	mapNode<T> *lastRight(mapNode<T> *head)
	{

		if (head->color != NONE)
		{
			while (head->right->color != NONE) {
				
				head = head->right;
			}
		}
		return (head);
	}

	template <typename T>
	setNode<T> *lastRight(setNode<T> *head)
	{

		if (head->color != NONE)
		{
			while (head->right->color != NONE) {
				
				head = head->right;
			}
		}
		return (head);
	}

	template <typename T>
	mapNode<T> *lastLeft(mapNode<T> *head)
	{

		if (head->color != NONE)
		{
			while (head->left->color != NONE)
			{
				head = head->left;
			}
		}
		return (head);
	}

	template <typename T>
	setNode<T> *lastLeft(setNode<T> *head)
	{

		if (head->color != NONE)
		{
			while (head->left->color != NONE)
			{
				head = head->left;
			}
		}
		return (head);
	}
};

#endif