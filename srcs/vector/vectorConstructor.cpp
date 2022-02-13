/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorConstructor.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:59:13 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/13 18:23:45 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorConstructor(std::ofstream &outfile) {


	LOG1("")
	LOG1("//------------------------CONSTRUCTORS----------------------------//")

	LOG1("")
	LOG1("DEFAUT CONST")
	NAMESP::vector<int>		vect1;

	LOG2("size = ", vect1.size())
	LOG2("max_size = ", vect1.max_size())
	LOG2("capacity = ", vect1.capacity())
	LOG2("capacity = ", vect1.empty())

	LOG1("")
	LOG1("FILL CONST")
	NAMESP::vector<int>		vect2(2);
	
	LOG2("size = ", vect2.size())
	LOG2("max_size = ", vect2.max_size())
	LOG2("capacity = ", vect2.capacity())
	LOG2("capacity = ", vect2.empty())

	vect2.push_back(40);
	vect2.push_back(41);
	vect2.push_back(42);
	vect2.push_back(43);
	vect2.push_back(44);

	NAMESP::vector<int>::iterator			it = vect2.begin();
	NAMESP::vector<int>::iterator			ite = vect2.end();

	while (it != ite) {

		LOG2("Iterator value = ", *it)
		++it;
	}

	LOG2("size = ", vect2.size())
	LOG2("max_size = ", vect2.max_size())
	LOG2("capacity = ", vect2.capacity())
	LOG2("capacity = ", vect2.empty())

	LOG1("")
	LOG1("RANGE CONST")
	it = vect2.begin();
	ite = vect2.end();
	NAMESP::vector<int>		vect3(it, ite);

	LOG2("size = ", vect3.size())
	LOG2("max_size = ", vect3.max_size())
	LOG2("capacity = ", vect3.capacity())
	LOG2("capacity = ", vect3.empty())

	it = vect3.begin();
	ite = vect3.end();
	while (it != ite) {

		LOG2("Iterator value = ", *it)
		++it;
	}

	LOG1("")
	LOG1("COPY CONST")
	NAMESP::vector<int>		vect4(vect2);

	LOG2("size = ", vect4.size())
	LOG2("max_size = ", vect4.max_size())
	LOG2("capacity = ", vect4.capacity())
	LOG2("capacity = ", vect4.empty())

	it = vect4.begin();
	ite = vect4.end();
	while (it != ite) {

		LOG2("Iterator value = ", *it)
		++it;
	}

}