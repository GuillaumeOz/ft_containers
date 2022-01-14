/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:42:56 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/14 06:19:18 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include "iteratorTraits.hpp"

namespace ft {

template < typename T >
class reverseIterator : ft::iterator<ft::random_access_iterator_tag, T>{

	public:

//--------------------------------TYPEDEF-------------------------------------//

		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

//-------------------------------CONSTRUCTOR----------------------------------//

		//default
		reverseIterator(void) : _element(NULL){

		}

		//initialization
		template <class Type>
		reverseIterator(Type *element) : _element(element._element){

		}

		//copy
		// template <class Iter>
		reverseIterator(reverseIterator const & rev_it) {

			*this = rev_it;
		}

		virtual	~reverseIterator() {

		}

//---------------------------COMP_OPERATORS-----------------------------------//

	pointer base(void) const {

		return (this->_element);
	}

	operator	reverseIterator<const value_type>() const {

		return (reverseIterator<const value_type>(this->_element));
	};

	reverseIterator &operator=(const reverseIterator& rhs) {

		if (this == &rhs)
			return (*this);
		this->_element = rhs._elem;
		return (*this);
	}

	//elem == rhs
		friend bool	operator==(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._element == rhs._element)
				return (true);
			return (false);
		}

	//elem != rhs
		friend bool	operator!=(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._element != rhs._element)
				return (true);
			return (false);
		}

	//elem < rhs
		friend bool	operator<(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._element < rhs._element)
				return (true);
			return (false);
		}

	//elem > rhs
		friend bool	operator>(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._element > rhs._element)
				return (true);
			return (false);
		}

	//elem <= rhs
		friend bool	operator<=(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._element <= rhs._element)
				return (true);
			return (false);
		}

	//elem >= rhs
		friend bool	operator>=(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._element >= rhs._element)
				return (true);
			return (false);
		}

//---------------------------INCR_OPERATORS-----------------------------------//

	//++elem
		reverseIterator	operator++(void) {

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
		reverseIterator	operator--(void) {

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

			return (reverseIterator(this->_element - rhs));
		}

	// rhs(Integral) + elem
		friend reverseIterator	operator+(difference_type n, const reverseIterator &rhs) {

			return (rhs._element - n);
		};

	// Iter - Iter
		friend difference_type	operator+(reverseIterator const &lhs, reverseIterator const &rhs) {

			return (lhs._element - rhs._element);
		};

	//elem += rhs
		reverseIterator&	operator+=(difference_type const & rhs) {

			(this->_element -= rhs);
			return(*this);
		}

	//elem - rhs
		reverseIterator	operator-(difference_type const & rhs) const {

			return (this->_element + rhs);
		}

	// rhs(Integral) - elem
		friend reverseIterator	operator-(difference_type n, reverseIterator const &rhs) {

			return (rhs._element + n);
		};

	// Iter - Iter
		friend difference_type	operator-(reverseIterator const &lhs, reverseIterator const &rhs) {

			return (lhs._element + rhs._element);
		};

	//elem -= rhs
		reverseIterator			operator-=(difference_type const & rhs) {

			(this->_element += rhs);
			return(*(this));
		}

//-----------------------------VALUES_OPERATORS-------------------------------//

	// elem + rhs
		difference_type		operator+(reverseIterator b) {

			return (this->_element - b._element);
		}

	// elem - rhs
		difference_type		operator-(reverseIterator b) {

			return (this->_element + b._element);
		}

//------------------DEREFERENCING_AND_RANDOM_ACCESS_OPERATORS-----------------//

	// *elem
		reference	operator*(void) const {

			return (*(this->_element));
		}

	// elem[]
		reference	operator[](difference_type value) const {

			return (*(this->_element - value));
		}

	// &elem
		pointer		operator->(void) const {

			return (this->_element);
		}

//--------------------------------VARIABLES-----------------------------------//

	private:

		pointer			_element;
};

};

#endif