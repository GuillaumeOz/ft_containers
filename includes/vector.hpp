/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:37:12 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/21 16:27:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

// #include "ft_containers.hpp"

# include "utils/lexicographical_compare.hpp"
# include "utils/equal_compare.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/iteratorTraits.hpp"
# include "utils/vectorIterator.hpp"
# include "utils/reverseIterator.hpp"
# include "utils/utils.hpp"

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {

//--------------------------------TYPEDEF-------------------------------------//

	public:

	typedef T													value_type;
	typedef Alloc												allocator_type;

	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;//
	typedef typename ft::vectorIterator<value_type>				iterator;
	typedef typename ft::vectorIterator<const value_type>		const_iterator;
	typedef typename ft::reverseIterator<iterator>				reverse_iterator;
	typedef typename ft::reverseIterator<const_iterator>		const_reverse_iterator;
	typedef typename allocator_type::difference_type			difference_type;//
	typedef size_t												size_type;

//------------------------------CONSTRUCTORS----------------------------------//

	// Default constructor
	explicit vector (const allocator_type& alloc = allocator_type()) {

		this->_alloc = alloc;
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
	template < class InputIterator >
	vector (InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

		this->_alloc = alloc;
		this->_size = ft::itDiff(first, last);
		this->_capacity = this->_size;
		this->_start = this->_alloc.allocate(this->_capacity);
		this->_end = this->_start;

		while (first != last) {

			this->_alloc.construct(this->_end, *first);
			++first;
			this->_end++;
		}
	}

	// Copy constructor
	vector (const vector& src) {

		size_type	n = src.size();
		pointer		tmp;

		this->_start = this->_alloc.allocate(n);
		this->_end = this->_start;
		this->_size = n;
		this->_capacity = n;
		tmp = src._start;

		while (0 < n) {

			this->_alloc.construct(this->_end++, *tmp++);
			n--;
		}
	}

//-------------------------------DESTRUCTOR-----------------------------------//

	// Default Destructor
	virtual ~vector() {

		this->clear();
		this->_alloc.deallocate(this->_start, this->_capacity);
	}

//--------------------------ASSIGNATION OPERATOR------------------------------//

	vector &operator=(const vector& rhs) {

		if (*this == rhs)
			return (*this);//remove this?
		this->clear();
		this->insert(this->end(), rhs.begin(), rhs.end());
		return (*this);
	}

//--------------------------ITERATORS FUNCTIONS-------------------------------//

	iterator	begin() {

		return (iterator(this->_start));
	}

	const_iterator begin() const {

		return (const_iterator(this->_start));
	}

	iterator	end() {

		return (iterator(this->_end));
	}

	const_iterator end() const {

		return (const_iterator(this->_end));
	}

	reverse_iterator	rbegin() {

		return (reverse_iterator(this->_end));
	}

	const_reverse_iterator	rbegin() const {

		return (const_reverse_iterator(this->_end));
	}

	reverse_iterator	rend() {

		return (reverse_iterator(this->_start));
	}

	const_reverse_iterator	rend() const {

		return (reverse_iterator(this->_start));
	}

//--------------------------CAPACITY FUNCTIONS--------------------------------//

	size_type	size (void) const {

		return (this->_size);
	}

	size_type	max_size (void) const {

		return (allocator_type().max_size());
	}

	void resize (size_type size, value_type val = value_type()) {//check value type

		if (size < this->_size) {

			while (size < this->_size) {

				this->_size--;
				this->_alloc.destroy((this->_start + this->_size));
			}
		}
		else {

			if (size <= this->_capacity)
				;
			else if (size <= this->_size * 2)
				this->reserve(this->_size * 2);
			else
				this->reserve(size);
			while (this->_size < size) {

				this->_alloc.construct(this->_start + this->_size, val);
				this->_size++;
			}
		}
		this->_end = this->_start + this->_size;
	}

	size_type	capacity(void) const {

		return (this->_capacity);
	}

	bool		empty() const {

		if (this->_size == 0)
			return (true);
		return (false);
	}

	void reserve (size_type capacity) {

		vector		res;
		iterator	itBegin = this->begin();
		iterator	itEnd = this->end();

		if (capacity > this->max_size())
			throw std::length_error("Error : Alloc size is greater than max_size");
		if (capacity <= this->capacity())
			return ;
		difference_type len = ft::itDiff(itBegin, itEnd);
		if (capacity < (size_t)len || capacity < 0)
			throw std::bad_alloc();
		res._alloc = this->_alloc;
		res._size = len;
		res._capacity = capacity;
		res._start = res._alloc.allocate(capacity);
		res._end = res._start + res._size;
		for (size_type i = 0; itBegin != itEnd; ++itBegin) {

			res._alloc.construct(res._start + i, *itBegin);
			i++;
		}
		if (this->_start != NULL) {

			this->clear();
			this->_alloc.deallocate(this->_start, this->_capacity);
			this->_start = NULL;
			this->_size = 0;
			this->_capacity = 0;
		}
		this->_alloc = res._alloc;
		this->_start = res._start;
		this->_end = res._end;
		this->_size = res._size;
		this->_capacity = res._capacity;
		res._start = NULL;
		res._size = 0;
		res._capacity = 0;
	}

//------------------------ELEMENT ACCESS FUNCTIONS----------------------------//

	reference operator[] (size_type n) {

		return (this->_start[n]);
	}

	const_reference operator[] (size_type n) const {

		return (this->_start[n]);
	}

	reference at (size_type n) {

		if (n >= this->size()) {

			throw std::out_of_range("Error : at out of range error");
		}
		return (this->_start[n]);
	}

	const_reference at (size_type n) const {

		if (n >= this->size()) {

			throw std::out_of_range("Error : at out of range error");
		}
		return (this->_start[n]);
	}

	reference front() {

		return (*(this->_start));
	}

	const_reference front() const {

		return (*(this->_start));
	}

	reference back() {

		return (*(this->_end - 1));
	}

	const_reference back() const {

		return (*(this->_end - 1));
	}

//---------------------------MODIFIER FUNCTIONS-------------------------------//

	// Range Assign
	template <class InputIterator>
	void assign(InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

		this->clear();
		difference_type n = ft::itDiff(first, last);
		reserve(n);
		while (first != last) {

			this->_alloc.construct(this->_start + this->_size, *first);
			++first;
			this->_size++;
		}
		this->_end = this->_start + this->_size;
	}

	// Fill Assign
	void assign (size_type n, const value_type& val) {

		this->clear();
		reserve(n);
		while (n != 0) {

			this->_alloc.construct(this->_start + this->_size, val);
			this->_size++;
			n--;
		}
		this->_end = this->_start + this->_size;
	}

	void push_back (const value_type& val) {

		if (this->_size == this->_capacity)
			this->resize(this->_size + 1, val);
		else {

			this->_alloc.construct(this->_start + this->_size, val);
			this->_size++;
		}
		this->_end = this->_start + this->_size;
	}

	void pop_back() {

		if (this->empty() == false) {

			this->_alloc.destroy(this->_end);
			this->_size--;
			this->_end--;
		}
	}

	// Insert single element
	iterator insert (iterator position, const value_type& val) {

		difference_type			newSize = ft::itDiff(this->begin(), position);

		insert(position, 1, val);
		return iterator(this->begin() + newSize);
	}

	// Insert fill
	void insert (iterator position, size_type n, const value_type& val) {

		difference_type			beginToPosition = ft::itDiff(this->begin(), position);
		difference_type			beginToEnd = ft::itDiff(this->begin(), this->end());
		difference_type			newSize = n;
		iterator				previousEnd;
		iterator				end;

		this->resize(this->_size + newSize);

		previousEnd = this->begin() + beginToEnd;
		position = this->begin() + beginToPosition;
		end = this->_start + this->_size;
		this->_end = this->_start + this->_size;
		while (previousEnd != position) {

			*(--end) = *(--previousEnd);
		}
		while (0 < n) {

			*position++ = val;
			n--;
		}
	}

	// Insert range
	template < class InputIterator >
	void insert(iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

		difference_type			beginToPosition = ft::itDiff(this->begin(), position);
		difference_type			beginToEnd = ft::itDiff(this->begin(), this->end());
		difference_type			newSize = ft::itDiff(first, last);
		iterator				previousEnd;
		iterator				end;

		this->resize(this->_size + newSize);

		previousEnd = this->begin() + beginToEnd;
		position = this->begin() + beginToPosition;
		end = this->end();
		while (previousEnd != position) {

			*(--end) = *(--previousEnd);
		}
		while (first != last) {

			*position = *first;
			position++;
			first++;
		}
		this->_end = this->_start + this->_size;
	}

	// Iterator erase
		iterator erase (iterator position) {

		return (this->erase(position, position + 1));
	}

	// Range erase
	iterator erase (iterator first, iterator last) {

		size_type	rangeToDelete = ft::itDiff(first, last);
		iterator	tmp = first;

		while (last != this->end()) {

			*first = *last;
			++first;
			++last;
		}
		for (size_type i = 0; i < rangeToDelete; i++) {

			this->_alloc.destroy((this->_start + this->_size));
			this->_size--;
			this->_end--;
		}
		return (tmp);
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

		size_type len = this->size();

		for (size_type i = 0; i < len; i++) {

			this->_end--;
			this->_alloc.destroy(this->_end);
		}
		this->_size = 0;
	}

//---------------------------ALLOCATOR FUNCTION-------------------------------//

	allocator_type get_allocator() const {

		return (this->_alloc);
	}

//---------------------------PRIVATE ATTRIBUTES-------------------------------//

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
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		if (lhs.size() == rhs.size()) {

			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
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

		if (lhs != rhs) {

			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
		return (false);
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
			return (false);
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