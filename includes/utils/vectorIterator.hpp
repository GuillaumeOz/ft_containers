/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:29:51 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/12 19:42:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

namespace ft {

template < class T >
class vectorIterator : public ft::iterator<random_access_iterator_tag, T> {


//--------------------------------TYPEDEF-------------------------------------//

	public :

		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

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

			return (vectorIterator<const value_type>(this->_element));
		};

	//elem = rhs
		vectorIterator &operator=(const vectorIterator& rhs) {

			if (this == &rhs)
				return (*this);
			this->_element = rhs._element;
			return (*this);
		}

	//elem == rhs
		friend bool	operator==(vectorIterator const & lhs, vectorIterator const & rhs) {

			if (lhs._element == rhs._element)
				return (true);
			return (false);
		}

	//elem != rhs
		friend bool	operator!=(vectorIterator const & lhs, vectorIterator const & rhs) {

			if (lhs._element != rhs._element)
				return (true);
			return (false);
		}

	//elem < rhs
		friend bool	operator<(vectorIterator const & lhs, vectorIterator const & rhs) {

			if (lhs._element < rhs._element)
				return (true);
			return (false);
		}

	//elem > rhs
		friend bool	operator>(vectorIterator const & lhs, vectorIterator const & rhs) {

			if (lhs._element > rhs._element)
				return (true);
			return (false);
		}

	//elem <= rhs
		friend bool	operator<=(vectorIterator const & lhs, vectorIterator const & rhs) {

			if (lhs._element <= rhs._element)
				return (true);
			return (false);
		}

	//elem >= rhs
		friend bool	operator>=(vectorIterator const & lhs, vectorIterator const & rhs) {

			if (lhs._element >= rhs._element)
				return (true);
			return (false);
		}

//---------------------------INCR_OPERATORS-----------------------------------//

	//++elem
		vectorIterator	operator++(void) {

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
		vectorIterator&	operator--(void) {

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

	// rhs(Integral) + elem
		friend vectorIterator	operator+(difference_type n, vectorIterator const &rhs) {

			return (rhs._element + n);//redo this function
		};

	// Iter - Iter
		friend difference_type	operator+(vectorIterator const &lhs, vectorIterator const &rhs) {

			return (lhs._element + rhs._element);
		};

	//elem += rhs
		vectorIterator			operator+=(difference_type rhs) {

			return(vectorIterator(this->_element += rhs));
		}

	//elem - rhs
		vectorIterator	operator-(difference_type const & rhs) const {

			return (this->_element - rhs);
		}

	// rhs(Integral) - elem
		friend vectorIterator	operator-(difference_type n, vectorIterator const &rhs) {

			return (rhs._element - n);
		};

	// Iter - Iter
		friend difference_type	operator-(vectorIterator const &lhs, vectorIterator const &rhs) {

			return (lhs._element - rhs._element);
		};

	//elem -= rhs
		vectorIterator			operator-=(difference_type const & rhs) {

			return(vectorIterator(this->_element -= rhs));
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
		reference	operator*(void) const {

			return (*(this->_element));
		}

	// elem[]
		reference	operator[](difference_type value) const {

			return (*(this->_element + value));
		}

	// &elem
		pointer		operator->(void) const {

			return (this->_element);
		}

//--------------------------------VARIABLES-----------------------------------//

	private:

		pointer		_element;

};


};

#endif


