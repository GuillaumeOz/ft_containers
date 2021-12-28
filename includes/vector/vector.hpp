/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:37:12 by gozsertt          #+#    #+#             */
/*   Updated: 2021/12/28 18:04:45 by gozsertt         ###   ########.fr       */
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

//--------------------------------TYPEDEF-------------------------------------//

	typedef T												value_type;
	typedef Alloc											allocator_type;
	typedef value_type&										reference;//not used yet
	typedef const value_type&								const_reference;//
	typedef value_type*										pointer;//
	typedef const value_type*								const_pointer;//Same
	typedef ft::vector<value_type>::iterator				iterator;//
	typedef const ft::vector<value_type>::iterator			const_iterator;// C++11 ?
	typedef ft::vector<value_type>::reverse_iterator		reverse_iterator;//
	typedef const ft::vector<value_type>::reverse_iterator	const_reverse_iterator;// C++11 ?
	typedef std::ptrdiff_t									difference_type;//
	typedef size_t											size_type;//

//------------------------------CONSTRUCTORS----------------------------------//

	//default const
	explicit vector (const allocator_type& alloc = std::allocator<T>()) {

		this->_alloc(alloc);
		this->_size = 0;
		this->_capacity = 0;
		this->_start = NULL;
		this->_end = NULL;
	}

	//fill const
	explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) {

		this->_alloc(alloc);
		this->_size = 0;
		this->_capacity = n;//change capacity?
		this->_start = _alloc.allocate(n);
		this->_end = _start;
		for (size_t i = 0; 0 < n; i++) {

			this->_alloc.construct(this->_end, val);
			this->_end++;
		}
	}

	//range const [see enable if] // InputIterator
			// template <class InputIterator>
			// vector (InputIterator first, InputIterator last,
			// 	const allocator_type& alloc = allocator_type()) {



			// }

	//copy const
	vector (const vector& x) {

		this->_alloc(x._alloc);
		this->_start(NULL);
		this->_end(NULL);
		this->_end_capacity(NULL);
		if (this == &x)
			return ();
		this->insert(this->begin(), x.begin(), x.end());
	}

	//destructor
	~vector() {

		// this->clear();
		this->_alloc.deallocate(_start, this->_capacity);
	}






/*******************************************************************************
******************************MEMBER FUNCTIONS**********************************
*******************************************************************************/

//--------------------------ITERATORS FUNCTIONS-------------------------------//

	iterator	begin() const {

		return (this->_start);
	}

	iterator	end() const {

		return (this->_end);
	}

	reverse_iterator	rbegin() const {

		return (this->_start);
	}

	reverse_iterator	rend() const {

		return (this->_end);
	}

//--------------------------CAPACITY FUNCTIONS--------------------------------//

	size_type	size (void) {

		return (this->_start - this->_end);
	}

	size_type	max_size (void) {

		return (0);//allocator_type().max_size();
	}

		//MODIFIER FUNCTIONS

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

		// allocator_type	_alloc;
		// size_type		_size;
		// size_type		_capacity;
		// pointer			_start;
		// pointer			_end;

	vector &operator=(ft::vector<value_type> const & rhs) {

		if (*this == rhs)
			return (*this);
		this->clear();
		this->insert(this->end(), x.begin(), x.end());
		return (*this);
	}

			//ITERATORS

//--------------------------MODIFIERS FUNCTIONS-------------------------------//
//assign
//push_back
//pop_back

// single element (1)
		iterator insert (iterator position, const value_type& val) {

			
		}
// fill (2)
		void insert (iterator position, size_type n, const value_type& val) {

			
		}
// range (3)
		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last);

//erase
//swap
//clear


		private:
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			pointer			_start;
			pointer			_end;

	};



};



#endif