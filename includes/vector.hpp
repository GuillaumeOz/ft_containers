/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:37:12 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/06 20:20:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

// # define print(x) std::cout << x << std::endl;


namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {

	public:

//--------------------------------TYPEDEF-------------------------------------//

	typedef T													value_type;
	typedef Alloc												allocator_type;
	typedef value_type&											reference;
	typedef const value_type&									const_reference;
	typedef value_type*											pointer;
	typedef const value_type*									const_pointer;//
	typedef typename ft::vectorIterator<value_type>				iterator;
	typedef const typename ft::vectorIterator<value_type>		const_iterator;
	typedef typename ft::reverseIterator<value_type>			reverse_iterator;
	typedef const typename ft::reverseIterator<value_type>		const_reverse_iterator;
	typedef std::ptrdiff_t										difference_type;//
	typedef size_t												size_type;

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

// typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL

	// Range constructor
	template < class InputIterator >
	vector (InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr) {

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
	virtual ~vector() {

		this->clear();
		this->_alloc.deallocate(_start, this->_capacity);
	}

//--------------------------ASSIGNATION OPERATOR------------------------------//

	vector &operator=(const vector& rhs) {

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

	iterator	begin() {

		return (this->_start);
	}

	const_iterator begin() const {

		return (this->_start);
	}

	iterator	end() {

		return (this->_end);
	}

	const_iterator end() const {

		return (this->_end);
	}

	reverse_iterator	rbegin() {

		return ((--(this->end())));
	}

	const_reverse_iterator	rbegin() const {

		return ((--(this->end())));
	}

	reverse_iterator	rend() {

		return ((--(this->begin())));//check pointer position
	}

	const_reverse_iterator	rend() const {

		return ((--(this->begin())));
	}

//--------------------------CAPACITY FUNCTIONS--------------------------------//

	size_type	size (void) const {

		return (this->_size);
	}

	size_type	max_size (void) const {

		return (allocator_type().max_size());
	}

	void resize (size_type n, value_type val = value_type()) {

		allocator_type	newAlloc;
		pointer			newStart;
		pointer			newEnd;
		

		newStart = newAlloc.allocate(n);
		if (this->_size < n) {

			for (size_t i = 0; i < this->_size; i++) {

				newAlloc.construct(newStart + i, *(this->_start + i));
				newEnd = newStart + i;
			}
			for (size_t i = 0; i < n - this->_size; i++) {

				newAlloc.construct(newStart + this->_size + i, val);
			}
		}
		else {

			for (size_t i = 0; i < n; i++) {

				newAlloc.construct(newStart + i, *(this->_start + i));
				newEnd = newStart + i;
			}
		}
		if (this->_size > 0) {
			this->_alloc.destroy(this->_start);
			this->_alloc.deallocate(this->_start, this->_capacity);
		}
		this->_alloc = newAlloc;
		this->_size = n;
		this->_capacity = n;
		this->_start = newStart;
		this->_end = newEnd;
	}

	size_type	capacity(void) const {

		return (this->_capacity);
	}

	bool		empty() const {

		if (this->_size == 0)
			return (true);
		return (false);
	}

	void reserve (size_type n) {

		allocator_type	newAlloc;
		pointer			newStart;
		pointer			newEnd;

		if (this->_capacity < n) {

			newStart = newAlloc.allocate(n);
			for (size_t i = 0; i < this->_size; i++) {

				newAlloc.construct(newStart + i, *(this->_start + i));
				newEnd = newStart + i;
			}
			if (this->_size > 0) {

				this->_alloc.destroy(this->_start);
				this->_alloc.deallocate(this->_start, this->_capacity);
			}
			this->_alloc = newAlloc;
			this->_capacity = n;
			this->_start = newStart;
			this->_end = newEnd;
		}
	}

//------------------------ELEMENT ACCESS FUNCTIONS----------------------------//

	operator	vectorIterator<const value_type>() const {
		return _element;
	};//test this

	reference operator[] (size_type n) {

		return (this->_start[n]);
	}

	const_reference operator[] (size_type n) const {

		return (this->_start[n]);
	}

	reference at (size_type n) {

		try {
			// n >= this->_size
			reference ret = this->_start[n];
			return (ret);
		}
		catch (const std::out_of_range& rangeErr) {

			std::cerr << "Out of Range error: " << rangeErr.what() << std::endl;
		}
	}

	const_reference at (size_type n) const {

		try {
			// n >= this->_size
			reference ret = this->_start[n];
			return (ret);
		}
		catch (const std::out_of_range& rangeErr) {

			std::cerr << "Out of Range error: " << rangeErr.what() << std::endl;
		}
	}

	reference front() {

		return (*(this->_start));
	}

	const_reference front() const {

		return (*(this->_start));
	}

	reference back() {

		return (*(this->_end));
	}

	const_reference back() const {

		return (*(this->_end));
	}

//---------------------------MODIFIER FUNCTIONS-------------------------------//

	template <class InputIterator>
	void assign(InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr >) {
		
		this->clear();
		while (first != last) {

			this->push_back(*first);
			++first;
		}
	}

	// Fill Assign	
	void assign (size_type n, const value_type& val) {

		this->clear();
		while (n-- != 0) {

			this->push_back(val);
		}
	}

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

	void pop_back() {

		if (this->empty() == false) {

			this->_alloc.destroy(this->_end);
			this->_size--;
		}
	}

	// Insert single element
	iterator insert (iterator position, const value_type& val) {

		vector				newVector(this->begin(), position);
		iterator			newPosIterator;
		size_type			newDistanceIterator = 0;

		for (iterator it = this->begin(); it != position; ++it)
			newDistanceIterator++;
		newVector.push_back(val);
		newDistanceIterator++;
		newPosIterator = this->begin() + newDistanceIterator;
		while (newPosIterator != this->end()) {

			newVector.push_back((*newPosIterator));
			++newPosIterator;
		}
		this = newVector;
	}

	// Insert fill
	void insert (iterator position, size_type n, const value_type& val) {

		vector				newVector(this->begin(), position);
		iterator			newPosIterator;
		size_type			newDistanceIterator = 0;

		for (iterator it = this->begin(); it != position; ++it)
			newDistanceIterator++;
		for (size_type i = 0; i < n; i++) {

			newVector.push_back(val);
			newDistanceIterator++;
		}
		newPosIterator = this->begin() + newDistanceIterator;
		while (newPosIterator != this->end()) {

			newVector.push_back((*newPosIterator));
			++newPosIterator;
		}
		(*this) = newVector;
	}

	// Insert range
	template < class InputIterator >
	void insert(iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr) {

		vector				newVector(this->begin(), position);
		iterator			newPosIterator;
		size_type			newDistanceIterator = 0;

		for (iterator it = this->begin(); it != position; ++it)
			newDistanceIterator++;
		while (first != last) {

			newVector.push_back(*first);
			++first;
			newDistanceIterator++;
		}
		newPosIterator = this->begin() + newDistanceIterator;
		while (newPosIterator != this->end()) {

			newVector.push_back(*newPosIterator);
			++newPosIterator;
		}
		(*this) = newVector;
	}

	// Iterator erase
	iterator erase (iterator position) {

		iterator	newPostion = (position + 1);
		vector		tmp(newPostion, this->_end);

		for (size_t i = 0; i < tmp.size(); i++)
			this->pop_back();
		this->pop_back();
		for (iterator it = tmp.begin(); it != tmp.end(); it++)
			this->push_back(*it);
		return (position);
	}

	// Range erase
	iterator erase (iterator first, iterator last) {//test this

		while (first != last)
		{
			erase(first);
			++first;
		}
		return (first);
	}

	void swap (vector& x) {

		allocator_type	tmpAlloc;
		size_type		tmpSize;
		size_type		tmpCapacity;
		pointer			tmpStart;
		pointer			tmpEnd;

		tmpAlloc = this->_alloc;
		tmpSize = this->_size;
		tmpCapacity = this->_capacity;
		tmpStart = this->_start;
		tmpEnd = this->_end;

		this->_alloc = x._alloc;
		this->_size = x._size;
		this->_capacity = x._capacity;
		this->_start = x._start;
		this->_end = x._end;

		x._alloc = tmpAlloc;
		x._size = tmpSize;
		x._capacity = tmpCapacity;
		x._start = tmpStart;
		x._end = tmpEnd;
	}

	void clear(void) {

		iterator	itBegin = this->begin();
		iterator	itEnd = this->end();

		if (this->empty() == false) {

			while (itBegin != itEnd) {

				this->_alloc.destroy((&(*itBegin)));
				++itBegin;
			}
			this->_size = 0;
		}
	}

//---------------------------ALLOCATOR FUNCTION-------------------------------//

	// allocator_type get_allocator() const {//have to do this ?

		
	// }

	private:
		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;
		pointer			_start;
		pointer			_end;

};

//--------------------------RELATIONAL OPERATOR-------------------------------//

	// Operator ==
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {// const ?

		typename ft::vector<T>::iterator	itLhsBegin = lhs.begin();
		typename ft::vector<T>::iterator	itLhsEnd = lhs.end();
		typename ft::vector<T>::iterator	itRhsBegin = rhs.begin();
		typename ft::vector<T>::iterator	itRhsEnd = rhs.end();

		if (lhs.size() == rhs.size()) {

			return (ft::equal(itLhsBegin, itLhsEnd, itRhsBegin));
		}
		return (false);
	}

	// Operator !=
	// a!=b -> !(a==b)
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		return (!(lhs == rhs));
	}

	// Operator <
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		typename ft::vector<T>::iterator	itLhsBegin = lhs.begin();
		typename ft::vector<T>::iterator	itLhsEnd = lhs.end();
		typename ft::vector<T>::iterator	itRhsBegin = rhs.begin();
		typename ft::vector<T>::iterator	itRhsEnd = rhs.end();

		if (lhs == rhs)
			return (false);//test this change for lhs != rhs
		return (ft::lexicographical_compare(itLhsBegin, itLhsEnd, itRhsBegin, itRhsEnd));
	}

	// Operator <=
	// a<=b -> !(b<a)
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		if (lhs == rhs)
			return (true);
		return (!(rhs < lhs));
	}

	// Operator >
	// a>b -> b<a
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		if (lhs == rhs)
			return (false);//test this change for lhs != rhs
		return (rhs < lhs);
	}

	// Operator >=
	// a>=b -> !(a<b)
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		if (lhs == rhs)
			return (true);
		return (!(lhs < rhs));
	}

	// No member Swap overload
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {

		x.swap(y);
	}

};

#endif