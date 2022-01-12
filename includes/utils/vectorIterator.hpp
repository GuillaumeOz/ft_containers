/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:29:51 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/12 07:03:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iteratorTraits.hpp"

namespace ft {

template < class T >
class vectorIterator: public ft::iterator<random_access_iterator_tag, T> {

	public :

//--------------------------------TYPEDEF-------------------------------------//

		// typedef typename ft::iterator<random_access_iterator_tag, T>::iterator			iterator_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

		// typedef const value_type*		const_iterator;

//-------------------------------CONSTRUCTOR----------------------------------//

		vectorIterator(void) : _element(NULL){

		}

		vectorIterator(pointer element) : _element(element){

		}

		vectorIterator(vectorIterator const & src) {

			this->_element = src._element;
		}

		virtual	~vectorIterator() {

		}

//---------------------------COMP_OPERATORS-----------------------------------//

	operator	vectorIterator<const value_type>() const {

		return (this->_element);
	};

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
		vectorIterator&	operator++(void) {

			++(this->_element);
			return (*this);
		}

	//elem++
		vectorIterator	operator++(int) {

			vectorIterator	tmp = (*this);

			++(*this);
			return (tmp);
		}

	//--elem
		vectorIterator&	operator--() {

			--(this->_element);
			return (*this);
		}

	//elem--
		vectorIterator	operator--(int) {

			vectorIterator	tmp(*this);

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

			// friend difference_type operator- (const reverse_iterator<Iterator>& lhs,
			// 	const reverse_iterator<Iterator>& rhs) {
			// 	return rhs.base() - lhs.base();
			// }

			// template < class _IteratorR >
			// friend difference_type operator- (const reverse_iterator<Iterator>& lhs,
			// 	const reverse_iterator<_IteratorR>& rhs) {
			// 	return rhs.base() - lhs.base();
			// }

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
	friend difference_type		operator-(vectorIterator a, vectorIterator b) {

		return (a._element - b._element);//remove friend word, try non member function
	}

//------------------DEREFERENCING_AND_RANDOM_ACCESS_OPERATORS-----------------//

	// *elem
	reference	operator*() const {

		return (*(this->_element));
	}

	// elem[]
	reference	operator[](difference_type value) const {

		return (this->_element + value);
	}

	// &elem
	pointer		operator->() const {

		return (this->_element);
	}

//--------------------------------VARIABLES-----------------------------------//

	private:

		pointer		_element;

};

};

#endif


