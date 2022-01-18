/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:00:56 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/18 15:11:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template<typename T1, typename T2>
struct pair {

//--------------------------------TYPEDEF-------------------------------------//

	typedef T1 first_type;
	typedef T2 second_type;

//-------------------------------ATTRIBUTES-----------------------------------//

	T1 first;
	T2 second;

//------------------------------CONSTRUCTORS----------------------------------//

	// Default constructor
	pair() : first(), second() {

		
	}

	// Copy constructor	
	template<class U, class V>
	pair (const pair<U,V>& pr) {

		(*this) = pr;
	}

	// Initialization constructor
	pair (const first_type& a, const second_type& b) {

		this->first = a;
		this->second = b;
	}

//-----------------------------MEMBER FUNCTIONS-------------------------------//

	pair& operator= (const pair& pr) {

		this->first = pr.first;
		this->second = pr.second;
		return (*this);
	}

};

//--------------------------RELATIONAL OPERATOR-------------------------------//

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {

		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {

		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {

		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {

		return (!(rhs < lhs));
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {

		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {

		return (!(lhs < rhs));
	}

};

#endif