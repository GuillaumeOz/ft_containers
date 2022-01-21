/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:42:56 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/21 16:45:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include "iteratorTraits.hpp"

namespace ft {

template < typename Iterator >
class reverseIterator {

//--------------------------------TYPEDEF-------------------------------------//

	public:

		typedef Iterator													iterator_type;

		// typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		// typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

//-------------------------------CONSTRUCTOR----------------------------------//

		//default
		reverseIterator(void) : _ite(){

		}

		//initialization
		explicit reverseIterator(iterator_type it) : _ite(it){

		}

		//copy
		template<class _Iter>
		reverseIterator(const reverseIterator<_Iter>& revIt) : _ite(revIt.base()) {

		}

		virtual	~reverseIterator() {

		}

//-------------------------ASSIGNATION OPERATOR-------------------------------//

	reverseIterator &operator=(const reverseIterator& rhs) {

		if (this == &rhs)
			return (*this);
		this->_ite = rhs._ite;
		return (*this);
	}

//---------------------------COMP_OPERATORS-----------------------------------//

	// pointer base(void) const {

	// 	return (this->_ite->getElement());
	// }

	// operator	reverseIterator<const value_type>() const {

	// 	return (reverseIterator<const value_type>(this->_ite));
	// };

	//elem == rhs
		friend bool	operator==(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._ite == rhs._ite)
				return (true);
			return (false);
		}

	//elem != rhs
		bool	operator!=(reverseIterator const & rhs) {

			if (this->_ite->getElement() != rhs.getElement())
				return (true);
			return (false);
		}

	//elem < rhs
		friend bool	operator<(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._ite < rhs._ite)
				return (true);
			return (false);
		}

	//elem > rhs
		friend bool	operator>(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._ite > rhs._ite)
				return (true);
			return (false);
		}

	//elem <= rhs
		friend bool	operator<=(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._ite <= rhs._ite)
				return (true);
			return (false);
		}

	//elem >= rhs
		friend bool	operator>=(reverseIterator const & lhs, reverseIterator const & rhs) {

			if (lhs._ite >= rhs._ite)
				return (true);
			return (false);
		}

//---------------------------INCR_OPERATORS-----------------------------------//

	//++elem
		reverseIterator	operator++(void) {

			this->_ite--;
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

			this->_ite++;
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

			return (reverseIterator(this->_ite - rhs));
		}

	// rhs(Integral) + elem
		friend reverseIterator	operator+(difference_type n, const reverseIterator &rhs) {

			return (rhs._ite - n);
		};

	// Iter - Iter
		friend difference_type	operator+(reverseIterator const &lhs, reverseIterator const &rhs) {

			return (lhs._ite - rhs._ite);
		};

	//elem += rhs
		reverseIterator&	operator+=(difference_type const & rhs) {

			(this->_ite -= rhs);
			return(*this);
		}

	//elem - rhs
		reverseIterator	operator-(difference_type const & rhs) const {

			return (this->_ite + rhs);
		}

	// rhs(Integral) - elem
		friend reverseIterator	operator-(difference_type n, reverseIterator const &rhs) {

			return (rhs._ite + n);
		};

	// Iter - Iter
		friend difference_type	operator-(reverseIterator const &lhs, reverseIterator const &rhs) {

			return (lhs._ite + rhs._ite);
		};

	//elem -= rhs
		reverseIterator			operator-=(difference_type const & rhs) {

			(this->_ite += rhs);
			return(*(this));
		}

//-----------------------------VALUES_OPERATORS-------------------------------//

	// elem + rhs
		difference_type		operator+(reverseIterator b) {

			return (this->_ite - b._ite);
		}

	// elem - rhs
		difference_type		operator-(reverseIterator b) {

			return (this->_ite + b._ite);
		}

//------------------DEREFERENCING_AND_RANDOM_ACCESS_OPERATORS-----------------//

	// *elem
		reference	operator*(void) const {

			return (*(this->_ite));
		}

	// elem[]
		reference	operator[](difference_type value) const {

			return (*(this->_ite - value));
		}

	// &elem
		pointer		operator->(void) const {

			return (this->_ite->getElement());
		}

		Iterator base(void) const {

			return this->_ite;
		};

//--------------------------------VARIABLES-----------------------------------//

	private:

		iterator_type			_ite;

};

};

#endif
