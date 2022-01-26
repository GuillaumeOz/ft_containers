/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:20:21 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/26 18:16:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

// #include "ft_containers.hpp"

#include "./vector.hpp"

namespace ft {

template < class T, class Container = ft::vector<T> >
class stack {

//--------------------------------TYPEDEF-------------------------------------//

	public:

	typedef Container								container_type;
	typedef typename Container::value_type			value_type;
	typedef typename Container::reference			reference;
	typedef typename Container::const_reference		const_reference;
	typedef typename Container::size_type			size_type;

//--------------------------PROTECTED ATTRIBUTES------------------------------//

	protected:

	container_type	_container;

//------------------------------CONSTRUCTORS----------------------------------//

	public:

	explicit stack (const container_type& ctnr = container_type()) : _container(ctnr){

	}

	virtual ~stack(void) {

	}

//-----------------------------MEMBER FUNCTIONS-------------------------------//

	bool empty() const {

		return (this->_container.empty());
	}

	void pop() {

		this->_container.pop_back();
	}

	void push (const value_type& val) {

		this->_container.push_back(val);
	}

	size_type size() const {

		return (this->_container.size());
	}

	reference top() {

		return (this->_container.back());
	}
	
	const_reference top() const {

		return (this->_container.back());
	}

	// Operator ==
	friend	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

		return (lhs._container == rhs._container);
	}

	// Operator <
	friend bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

		return (lhs._container < rhs._container);
	}

};

//-----------------------------  MEMBER FUNCTIONS-------------------------------//

	// Operator !=
	// a!=b -> !(a==b)
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

		return (!(lhs == rhs));
	}

	// Operator <=
	// a<=b -> !(b<a)
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

		return (!(rhs < lhs));
	}

	// Operator >
	// a>b -> b<a
	template <class T, class Container>
	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

		return (rhs < lhs);
	}

	// Operator >=
	// a>=b -> !(a<b)
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

		return (!(lhs < rhs));
	}

};

#endif
