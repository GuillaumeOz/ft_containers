/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:37:12 by gozsertt          #+#    #+#             */
/*   Updated: 2021/12/30 16:58:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# define print(x) std::cout << x << std::endl;

# include <iostream>
# include "vectorIterator.hpp"
# include "vectorReverseIterator.hpp"
// # include <tgmath.h>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {

	public:

//--------------------------------TYPEDEF-------------------------------------//

	typedef T													value_type;
	typedef Alloc												allocator_type;
	typedef value_type&											reference;//not used yet
	typedef const value_type&									const_reference;//
	typedef value_type*											pointer;//
	typedef const value_type*									const_pointer;//Same
	typedef typename ft::vectorIterator<value_type>				iterator;//
	typedef const typename ft::vectorIterator<value_type>		const_iterator;// C++11 ?
	typedef typename ft::vectorReveseIterator<value_type>		reverse_iterator;//
	typedef const typename ft::vectorReveseIterator<value_type>	const_reverse_iterator;// C++11 ?
	typedef std::ptrdiff_t										difference_type;//
	typedef size_t												size_type;//

//------------------------------CONSTRUCTORS----------------------------------//

	// Default constructor
	explicit vector (const allocator_type& alloc = allocator_type()) {

		this->_alloc = alloc;//why with assignation
		this->_size = 0;
		this->_capacity = 0;
		this->_start = NULL;
		this->_end = NULL;
	}

	// Fill constructor
	explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) {

		this->_alloc = alloc;
		this->_size = n;
		this->_capacity = n;
		this->_start = this->_alloc.allocate(n);
		this->_end = this->_start;

		for (size_t i = 0; i < n; i++) {

			this->_alloc.construct(this->_end, val);
			this->_end++;
		}
	}

	// Range constructor
	template <class InputIterator>
	// typename ft::enable_if<InputIt::input_iter, InputIt>::type = NULL)
	vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type()) {

		this->_alloc = alloc;
		this->_size = last - first;
		this->_capacity = this->_size;
		this->_start = this->_alloc.allocate(this->_capacity);
		this->_end = this->_start;

		while (first != last) {

			this->_alloc.construct(this->_end, *first);
			++first;
			this->_end++;
		}
	}

	// Copy const
	vector (const vector& src) {

		(*this) = src;
	}
//-------------------------------DESTRUCTOR-----------------------------------//

	// Default Destructor
	~vector() {

		// this->clear();//see this utility
		this->_alloc.deallocate(_start, this->_capacity);
	}

//--------------------------ASSIGNATION OPERATOR------------------------------//

	vector &operator=(ft::vector<value_type> const & rhs) {

		if (*this == rhs)
			return (*this);
		this->clear();
		this->insert(this->end(), rhs.begin(), rhs.end());
		return (*this);
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

		return (this->_start);//end
	}

	reverse_iterator	rend() const {

		return (this->_end);//start ?
	}

//--------------------------CAPACITY FUNCTIONS--------------------------------//

	size_type	size (void) const {

		return (this->_size);
	}

	size_type	max_size (void) const {

		return (allocator_type().max_size());
	}

// n
// New container size, expressed in number of elements.
// Member type size_type is an unsigned integral type.

// val
// Object whose content is copied to the added elements in case that n is greater than the current container size.
// If not specified, the default constructor is used instead.
// Member type value_type is the type of the elements in the container, defined in vector as an alias of the first template parameter (T).

	void resize (size_type n, value_type val = value_type()) {

		
	}

	size_type	capacity(void) const {

		return (this->_capacity);
	}

	bool		empty() const {

		if (this->_size == 0)
			return (true);
		return (false);
	}

// reserve
// Request a change in capacity (public member function )


//---------------------------MODIFIER FUNCTIONS-------------------------------//

//assign

	void push_back (const value_type& val) {

		allocator_type	newAlloc;
		size_type		newCapacity;
		pointer			newStart;
		pointer			newEnd;
		pointer			tmpStart;

		newCapacity = this->_capacity == 0 ? 1 : this->_capacity * 2;
		if (newCapacity == 1) {

			newStart = newAlloc.allocate(newCapacity);
			newEnd = newStart;
			newAlloc.construct(newStart, val);
			this->_alloc.deallocate(this->_start, this->_capacity);
			this->_capacity++;
		}
		else if(this->_size == this->_capacity) {

			newStart = newAlloc.allocate(newCapacity);
			newEnd = newStart;
			tmpStart = this->_start;
			while (tmpStart != this->_end) {

				newAlloc.construct(newEnd, *(tmpStart));
				tmpStart++;
				newEnd++;
			}
			newAlloc.construct(newEnd, val);
			this->_alloc.deallocate(this->_start, this->_capacity);
			this->_capacity = newCapacity;
		}
		else {

			tmpStart = this->_start + this->_size;
			newAlloc.construct(tmpStart, val);
			this->_size++;
			this->_end++;
			return ;
		}
		newEnd++;
		this->_alloc = newAlloc;
		this->_size++;
		this->_start = newStart;
		this->_end = newEnd;
	}

//pop_back

// Position in the vector where the new elements are inserted.
// iterator is a member type, defined as a random access iterator type 
// that points to elements.

// Value to be copied (or moved) to the inserted elements.
// Member type value_type is the type of the elements in the container, 
// defined in deque as an alias of its first template parameter (T).

// Insert single element (1)
		iterator insert (iterator position, const value_type& val) {

			(void)position;
			(void)val;
		}

// Insert fill (2)
		void insert (iterator position, size_type n, const value_type& val) {

			(void)position;
			(void)val;
			(void)n;
		}

// Insert range (3)
		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last);

	void clear(void) {

		std::vector<int>::iterator	itBegin = this->begin();
		std::vector<int>::iterator	itEnd = this->end();

		if (this->_size > 0) {

			while (itBegin != itEnd) {

				this->_alloc.destroy(itBegin);//test this
				++itBegin;
			}
			this->size = 0;
		}
	}

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