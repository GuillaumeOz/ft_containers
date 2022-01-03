/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorReverseIterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:42:56 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/03 11:27:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORREVERSEITERATOR_HPP
# define VECTORREVERSEITERATOR_HPP

#include <iostream>

namespace ft {

template <class T, class Pointer = T*, class Reference = T&, class Distance = std::ptrdiff_t>
class vectorReveseIterator {

	public:
//--------------------------------TYPEDEF-------------------------------------//

		typedef T			value_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Distance	difference_type;
		//add const ptr? for member function return

//-------------------------------CONSTRUCTOR----------------------------------//

		vectorReveseIterator(void) : _element(NULL){

		}

		vectorReveseIterator(pointer element) : _element(element){

		}

		vectorReveseIterator(vectorReveseIterator const & src) {

			*this = src;
		}

		virtual	~vectorReveseIterator() {

		}

//---------------------------COMP_OPERATORS-----------------------------------//

	//elem == rhs
		bool	operator==(vectorReveseIterator const & rhs) const {

			if (this->_element == rhs._element)
				return (true);
			return (false);
		}

	//elem != rhs
		bool	operator!=(vectorReveseIterator const & rhs) const {

			if (this->_element != rhs._element)
				return (true);
			return (false);
		}

	//elem < rhs
		bool	operator<(vectorReveseIterator const & rhs) const {

			if (this->_element < rhs._element)
				return (true);
			return (false);
		}

	//elem > rhs
		bool	operator>(vectorReveseIterator const & rhs) const {

			if (this->_element > rhs._element)
				return (true);
			return (false);
		}

	//elem <= rhs
		bool	operator<=(vectorReveseIterator const & rhs) const {

			if (this->_element <= rhs._element)
				return (true);
			return (false);
		}

	//elem >= rhs
		bool	operator>=(vectorReveseIterator const & rhs) const {

			if (this->_element >= rhs._element)
				return (true);
			return (false);
		}

//---------------------------INCR_OPERATORS-----------------------------------//

	//++elem
		vectorReveseIterator	operator++() {

			this->_element--;
			return (*this);
		}

	//elem++
		vectorReveseIterator	operator++(int) {

			vectorReveseIterator	tmp = (*this);

			--(*this);
			return (tmp);
		}

	//--elem
		vectorReveseIterator	operator--() {

			this->_element++;
			return (*this);
		}

	//elem--
		vectorReveseIterator	operator--(int) {

			vectorReveseIterator	tmp = (*this);

			++(*this);
			return (tmp);
		}

	//elem + rhs
		vectorReveseIterator	operator+(difference_type const & rhs) const {

			return (this->_element - rhs);
		}

	//elem += rhs
		void			operator+=(difference_type const & rhs) {

			this->_element += rhs;
		}

	//elem - rhs
		vectorReveseIterator	operator-(difference_type const & rhs) const {

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