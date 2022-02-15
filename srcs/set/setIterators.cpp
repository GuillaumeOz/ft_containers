/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setIterators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:11:19 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/13 20:46:45 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	setIterators(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//--------------------------ITERATORS-----------------------------//")
	LOG1("")
	LOG1("IT")
	NAMESP::set<int> set1;

	set1.insert(100);
	set1.insert(200);
	set1.insert(300);

	LOG2("Size = : ", int(set1.size()))

	NAMESP::set<int>::iterator it = set1.begin();
	NAMESP::set<int>::iterator ite = set1.end();
	LOG1("set1 content:")
	while (it != ite) {

		LOG2("Iterator value = ", *it)
		++it;
	}

	LOG1("")
	LOG1("REVERSE IT")
	NAMESP::set<int>::reverse_iterator revIt = set1.rbegin();
	NAMESP::set<int>::reverse_iterator revIte = set1.rend();

	LOG1("set1 reverse content:")
	while (revIt != revIte) {

		LOG2("Iterator value = ", *revIt)
		++revIt;
	}
}
