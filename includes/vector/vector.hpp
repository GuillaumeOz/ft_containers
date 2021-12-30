/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:37:12 by gozsertt          #+#    #+#             */
/*   Updated: 2021/12/30 11:08:46 by gozsertt         ###   ########.fr       */
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

	//default constructor
	explicit vector (const allocator_type& alloc = allocator_type()) {

		this->_alloc = alloc;//why with assignation
		this->_size = 0;
		this->_capacity = 0;
		this->_start = NULL;
		this->_end = NULL;
	}

	//fill constructor
	explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) {

		this->_alloc = alloc;
		this->_size = n;
		this->_capacity = n;//change capacity?
		this->_start = this->_alloc.allocate(n);
		this->_end = this->_start;

		for (size_t i = 0; i < n; i++) {

			this->_alloc.construct(this->_end, val);
			this->_end++;
		}
	}

	// range constructor
	template <class InputIterator>
	vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type()) {

		this->_alloc = alloc;
		this->_size = 0;
		this->_capacity = first - last;//see this, test capacity value
		this->_start = this->_start;

		while (first != last) {

			this->push_back(*first);
			++first;
		}
	}

	// copy const
	vector (const vector& x) {

		this->_alloc(x._alloc);
		this->_capacity =  x.begin() - x.end();
		this->_size = 0;
		this->_start(NULL);
		this->_end(NULL);
		if (this == &x)
			return ;
		this->insert(this->begin(), x.begin(), x.end());
	}

	// destructor
	~vector() {

		// this->clear();//see this utility
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

// resize
// Change size (public member function )

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
			newEnd++;
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
			newEnd++;
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
		this->_alloc = newAlloc;
		this->_size++;
		this->_start = newStart;
		this->_end = newEnd;
	}

	vector &operator=(ft::vector<value_type> const & rhs) {

		if (*this == rhs)
			return (*this);
		this->clear();
		this->insert(this->end(), rhs.begin(), rhs.end());
		return (*this);
	}

			//ITERATORS

//--------------------------MODIFIERS FUNCTIONS-------------------------------//
//assign
//push_back
//pop_back

// single element (1)
		iterator insert (iterator position, const value_type& val) {

			(void)position;
			(void)val;
		}
// fill (2)
		void insert (iterator position, size_type n, const value_type& val) {

			(void)position;
			(void)val;
			(void)n;
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