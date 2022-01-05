/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:42:56 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 19:00:58 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include <iostream>

namespace ft {

template <class T, class Pointer = T*, class Reference = T&, class Distance = std::ptrdiff_t>
class reverseIterator {

	public:
//--------------------------------TYPEDEF-------------------------------------//

		typedef T			value_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Distance	difference_type;
		//add const ptr? for member function return

//-------------------------------CONSTRUCTOR----------------------------------//

		reverseIterator(void) : _element(NULL){

		}

		reverseIterator(pointer element) : _element(element){

		}

		reverseIterator(reverseIterator const & src) {

			*this = src;
		}

		virtual	~reverseIterator() {

		}

//---------------------------COMP_OPERATORS-----------------------------------//

	//elem == rhs
		bool	operator==(reverseIterator const & rhs) const {

			if (this->_element == rhs._element)
				return (true);
			return (false);
		}

	//elem != rhs
		bool	operator!=(reverseIterator const & rhs) const {

			if (this->_element != rhs._element)
				return (true);
			return (false);
		}

	//elem < rhs
		bool	operator<(reverseIterator const & rhs) const {

			if (this->_element < rhs._element)
				return (true);
			return (false);
		}

	//elem > rhs
		bool	operator>(reverseIterator const & rhs) const {

			if (this->_element > rhs._element)
				return (true);
			return (false);
		}

	//elem <= rhs
		bool	operator<=(reverseIterator const & rhs) const {

			if (this->_element <= rhs._element)
				return (true);
			return (false);
		}

	//elem >= rhs
		bool	operator>=(reverseIterator const & rhs) const {

			if (this->_element >= rhs._element)
				return (true);
			return (false);
		}

//---------------------------INCR_OPERATORS-----------------------------------//

	//++elem
		reverseIterator	operator++() {

			this->_element--;
			return (*this);
		}

	//elem++
		reverseIterator	operator++(int) {

			reverseIterator	tmp = (*this);

			--(*this);
			return (tmp);
		}

	//--elem
		reverseIterator	operator--() {

			this->_element++;
			return (*this);
		}

	//elem--
		reverseIterator	operator--(int) {

			reverseIterator	tmp = (*this);

			++(*this);
			return (tmp);
		}

	//elem + rhs
		reverseIterator	operator+(difference_type const & rhs) const {

			return (this->_element - rhs);
		}

	//elem += rhs
		void			operator+=(difference_type const & rhs) {

			this->_element += rhs;
		}

	//elem - rhs
		reverseIterator	operator-(difference_type const & rhs) const {

			return (this->_element + rhs);
		}

	//elem -= rhs
		void			operator-=(difference_type const & rhs) {

			this->_element += rhs;
		}

//------------------DEREFERENCING_AND_RANDOM_ACCESS_OPERATORS-----------------//

	// *elem
	reference	operator*(void) const {

		return (*(this->_element));
	}

	// elem[]
	reference	operator[](difference_type value) const {

		return ((this->_element + value));
	}

	// &elem
	pointer		operator->(void) const {

		return (this->_element);
	}

	// static const bool input_iter = true; // Check this ?

//--------------------------------VARIABLES-----------------------------------//

	private:

		pointer		_element;

};

};

#endif