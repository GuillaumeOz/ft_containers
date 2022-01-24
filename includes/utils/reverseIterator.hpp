/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:42:56 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/24 12:43:41 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include "iteratorTraits.hpp"

namespace ft {

template < typename Iterator >
class reverseIterator: public iterator< typename iterator_traits<Iterator>::iterator_category,
										typename iterator_traits<Iterator>::value_type,
										typename iterator_traits<Iterator>::difference_type,
										typename iterator_traits<Iterator>::pointer,
										typename iterator_traits<Iterator>::reference > {

//--------------------------------VARIABLES-----------------------------------//

	private:

		Iterator								current;

		typedef iterator_traits<Iterator>		traits_type;

//--------------------------------TYPEDEF-------------------------------------//

	public:

		typedef Iterator									iterator_type;

		typedef typename traits_type::difference_type		difference_type;
		typedef typename traits_type::pointer				pointer;
		typedef typename traits_type::reference				reference;

//-------------------------------CONSTRUCTOR----------------------------------//

		//default
		reverseIterator() : current() {

		}

		//initialization
		explicit reverseIterator(iterator_type x) : current(x) {

		}

		//copy
		reverseIterator(reverseIterator const & x) : current(x.current) {

		}

		//copy form InputIterator
		template<typename InputIterator>
		reverseIterator(reverseIterator<InputIterator> const & x) : current(x.base()) {

		}

//-----------------------------BASE FUNCTION----------------------------------//

		iterator_type	base() const {

			return current;
		}

//----------------------------MEMBER FUNCTIONS--------------------------------//

		reference	operator*() const {

			Iterator tmp = current;

			return (*(--tmp));
		}

		pointer	operator->() const {

			return (&(operator*()));
		}

		reverseIterator&	operator++() {

			--current;
			return (*this);
		}

		reverseIterator	operator++(int) {

			reverseIterator tmp = (*this);

			--current;
			return (tmp);
		}

		reverseIterator&	operator--() {

			++current;
			return (*this);
		}

		reverseIterator	operator--(int) {

			reverseIterator tmp = (*this);

			++current;
			return (tmp);
		}

		reverseIterator	operator+(difference_type n) const {

			return (reverseIterator(current - n));
		}

		reverseIterator&	operator+=(difference_type n) {

			current -= n;
			return (*this);
		}

		reverseIterator	operator-(difference_type n) const {

			return reverseIterator(current + n);
		}

		reverseIterator&	operator-=(difference_type n) {

			current += n;
			return (*this);
		}

		reference	operator[](difference_type n) const {

			return (*(*this + n));
		}
};

//----------------------NON-MEMBER FUNCTION OVERLOADS-------------------------//

	template<typename InputIterator>
	bool	operator==(const reverseIterator<InputIterator>& x, const reverseIterator<InputIterator>& y) {

		return (x.base() == y.base());
	}

	template<typename InputIterator>
	bool	operator<(const reverseIterator<InputIterator>& x, const reverseIterator<InputIterator>& y) {

		return (y.base() < x.base());
	}

	template<typename InputIterator>
	bool	operator!=(const reverseIterator<InputIterator>& x, const reverseIterator<InputIterator>& y) {

		return !(x == y);
	}

	template<typename InputIterator>
	bool	operator>(const reverseIterator<InputIterator>& x, const reverseIterator<InputIterator>& y) {

		return (y < x);
	}

	template<typename InputIterator>
	bool	operator<=(const reverseIterator<InputIterator>& x, const reverseIterator<InputIterator>& y) {

		return (!(y < x));
	}

	template<typename InputIterator>
	bool	operator>=(const reverseIterator<InputIterator>& x, const reverseIterator<InputIterator>& y) {

		return (!(x < y));
	}

// _GLIBCXX_RESOLVE_LIB_DEFECTS
// DR 280. Comparison of reverseIterator to const reverseIterator.
	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator==(const reverseIterator<InputIteratorL>& x, const reverseIterator<InputIteratorR>& y) {

		return (x.base() == y.base());
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator<(const reverseIterator<InputIteratorL>& x, const reverseIterator<InputIteratorR>& y) {

		return (y.base() < x.base());
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator!=(const reverseIterator<InputIteratorL>& x, const reverseIterator<InputIteratorR>& y) {

		return (!(x == y));
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator>(const reverseIterator<InputIteratorL>& x, const reverseIterator<InputIteratorR>& y) {

		return (y < x);
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator<=(const reverseIterator<InputIteratorL>& x, const reverseIterator<InputIteratorR>& y) {

		return (!(y < x));
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator>=(const reverseIterator<InputIteratorL>& x, const reverseIterator<InputIteratorR>& y) {

		return (!(x < y));
	}

	template<typename InputIterator>
	typename reverseIterator<InputIterator>::difference_type	operator-(const reverseIterator<InputIterator>& x,
		const reverseIterator<InputIterator>& y) {

		return (y.base() - x.base());
	}

	template<typename InputIteratorL, typename InputIteratorR>
	typename reverseIterator<InputIteratorL>::difference_type	operator-(const reverseIterator<InputIteratorL>& x,
		const reverseIterator<InputIteratorR>& y) {

		return (y.base() - x.base());
	}

	template<typename Iterator>
	reverseIterator<Iterator>	operator+(typename reverseIterator<Iterator>::difference_type n,
		const reverseIterator<Iterator>& x) {

		return (reverseIterator<Iterator>(x.base() - n));
	}

};

#endif
