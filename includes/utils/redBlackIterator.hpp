/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:40:05 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/10 18:24:28 by gozsertt         ###   ########.fr       */
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
	{ // change for set node specification

		T value;
		setNode *parent;
		setNode *left;
		setNode *right;
		e_tree_color color;

		setNode(T src = T()) : value(src)
		{

			parent = NULL;
			left = NULL;
			right = NULL;
			color = BLACK;
		}

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

		//------------------------------PRINT TREE------------------------------------//

		std::string printTree()
		{

			Node *rootNode = this->_node;

			while (rootNode->parent != this->_sentinal)
			{

				rootNode = rootNode->parent;
			}
			return (toString(rootNode).str());
		}

		template <typename _T>
		std::stringstream toString(mapNode<_T> *root)
		{

			return (toString(root, 0));
		};

		template <typename _T>
		std::stringstream toString(mapNode<_T> *tmp, int depth)
		{
			std::stringstream output;

			if (tmp == this->_sentinal)
			{

				return (output);
			}
			output << colorizeOutput(getSpaces(depth) + output.str(), tmp) << std::endl;
			if (tmp->left != this->_sentinal)
				output << toString(tmp->left, depth + 1).str();
			if (tmp->right != this->_sentinal)
				output << toString(tmp->right, depth + 1).str();
			return (output);
		};

		std::string getSpaces(int n)
		{
			std::string spaces("");
			while (--n >= 0)
			{
				spaces += "  ";
				spaces += ((n > 0) ? "│" : "└");
			}
			return spaces + "─ ";
		}

		template <typename _T>
		std::string colorizeOutput(std::string output, mapNode<_T> *tree)
		{
			std::stringstream tmp;
			std::stringstream content;

			content << tree->value.first;
			if (tree->color == RED)
				tmp << std::internal << content.str() + "R";
			if (tree->color == BLACK)
				tmp << std::internal << content.str() + "B";
			output += tmp.str();
			return (output);
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
				// print(head->value.first)
				// print(head->value.second)
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
				// print(head->left)
				// print(head->left->color)
			}
		}
		return (head);
	}
};

template <typename _T>
inline std::ostream &operator<<(std::ostream &outStream, ft::mapNode<_T> &instance)
{
	outStream << instance.toString().str();
	return (outStream);
};

#endif