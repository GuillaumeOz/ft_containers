/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:56:59 by gozsertt          #+#    #+#             */
/*   Updated: 2021/12/28 18:00:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include <iostream>

namespace ft {

template <class T, class Pointer = T*, class Reference = T&, class Distance = ptrdiff_t>
class vectorIterator {

	public:
	
//--------------------------------TYPEDEF-------------------------------------//

		typedef T			value_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Distance	difference_type;
		//add const ptr?

//-------------------------------CONSTRUCTOR----------------------------------//

		vectorIterator(void) : _element(NULL){

		}

		vectorIterator(pointer element) : _element(element){

		}

		vectorIterator(vectorIterator cosnt & src) {

			*this = src;
		}

		virtual	~vectorIterator() {

		}

//---------------------------COMP_OPERATORS-----------------------------------//

	//elem == rhs
		bool	operator==(vectorIterator const & rhs) const {

			if (this->_element == rhs._element)
				return (true);
			return (false);
		}

	//elem != rhs
		bool	operator!=(vectorIterator const & rhs) const {

			if (this->_element != rhs._element)
				return (true);
			return (false);
		}

	//elem < rhs
		bool	operator<(vectorIterator const & rhs) const {

			if (this->_element < rhs._element)
				return (true);
			return (false);
		}

	//elem > rhs
		bool	operator>(vectorIterator const & rhs) const {

			if (this->_element > rhs._element)
				return (true);
			return (false);
		}

	//elem <= rhs
		bool	operator<=(vectorIterator const & rhs) const {

			if (this->_element <= rhs._element)
				return (true);
			return (false);
		}

	//elem >= rhs
		bool	operator>=(vectorIterator const & rhs) const {

			if (this->_element >= rhs._element)
				return (true);
			return (false);
		}

//---------------------------INCR_OPERATORS-----------------------------------//

	//++elem
		vectorIterator	operator++() {

			this->_element++;
			return (*this);
		}

	//elem++
		vectorIterator	operator++(int) {

			vectorIterator	tmp = (*this);

			++(*this);
			return (tmp);
		}

	//--elem
		vectorIterator	operator--() {

			this->_element--;
			return (*this);
		}

	//elem--
		vectorIterator	operator--(int) {

			vectorIterator	tmp = (*this);

			--(*this);
			return (tmp);
		}

	//elem + rhs
		vectorIterator	operator+(difference_type const & rhs) const {

			return (this->_element + rhs);
		}

	//elem += rhs
		void			operator+=(difference_type const & rhs) {

			this->_element += rhs;
		}

	//elem - rhs
		vectorIterator	operator-(difference_type const & rhs) const {

			return (this->_element - rhs);
		}

	//elem -= rhs
		void			operator-=(difference_type const & rhs) {

			this->_element -= rhs;
		}

//-----------------------------VALUES_OPERATORS-------------------------------//

	// elem + rhs
	difference_type		operator+(vectorIterator b) {

		return (this->_element + b._element);
	}

	// elem - rhs
	difference_type		operator-(vectorIterator b) {

		return (this->_element - b._element);
	
	}

//------------------DEREFERENCING_AND_RANDOM_ACCESS_OPERATORS-----------------//

	// *elem
	reference	operator*() const {

		return (*(this->_element));
	}

	// elem[]
	reference	operator[](difference_type value) const {

		return ((this->_element + value));
	}

	// &elem
	pointer		operator->() const {

		return (this->_element)
	}

	// static const bool input_iter = true; // Check this ?

//--------------------------------VARIABLES-----------------------------------//

	private:

		pointer		_element;

};
	
};

#endif


