/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:37:12 by gozsertt          #+#    #+#             */
/*   Updated: 2021/12/22 22:56:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# define print(x) std::cout << x << std::endl;

# include <iostream>
// # include <tgmath.h>

# include <vector>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {


	public:

	typedef T				value_type;//The first template parameter (T)
	typedef Alloc			allocator_type;//The second template parameter (Alloc)
	typedef size_t			size_type;//

	//see later
	typedef std::ptrdiff_t	difference_type;
	typedef T*				pointer;
	typedef const T*		const_pointer;
	typedef T&				reference;
	typedef const T&		const_reference;


// reference	allocator_type::reference	for the default allocator: value_type&
// const_reference	allocator_type::const_reference	for the default allocator: const value_type&
// pointer	allocator_type::pointer	for the default allocator: value_type*
// const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*

// iterator	a random access iterator to value_type	convertible to const_iterator
// const_iterator	a random access iterator to const value_type	
// reverse_iterator	reverse_iterator<iterator>	
// const_reverse_iterator	reverse_iterator<const_iterator>	
// difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
// size_type	an unsigned integral type that can represent any non-negative value of difference_type

		//CONSTRUCTOR

//default const
		explicit vector (const allocator_type& alloc = std::allocator<T>()) {

				_alloc(alloc);
				_start(NULL);
				_end(NULL);
		}
// //fill const
// 		explicit vector (size_type n, const value_type& val = value_type(),
// 			const allocator_type& alloc = allocator_type());
// //range const [see enable if]
// 		template <class InputIterator>
// 		vector (InputIterator first, InputIterator last,
// 			const allocator_type& alloc = allocator_type());
// //copy const
// 		vector (const vector& x);

//destructor
	~vector() {

		// this->clear();
		_alloc.deallocate(_start, this->_capacity);
	}

		//MEMBER FUNCTIONS

	void push_back (const value_type& val) {

		//SRC CODE TAKE USEFULL INFORMATIONS
	// if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	//   {
	//     _GLIBCXX_ASAN_ANNOTATE_GROW(1);
	//     _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
	// 			     __x);
	//     ++this->_M_impl._M_finish;
	//     _GLIBCXX_ASAN_ANNOTATE_GREW(1);
	//   }
	// else
	//   _M_realloc_insert(end(), __x);

		(void)val;
		std::allocator<T> test = std::allocator<T>();

	
	}

		//OVERLOAD OPERATOR
	// operator++() {
		
		
	// }

	// ++operator() {
		
		
	// }
		//ITERATORS
	

	private:
		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;
		value_type*		_vect;
		pointer			_start;
		pointer			_end;

};



};



#endif