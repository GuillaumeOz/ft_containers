/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:11:19 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/13 20:46:45 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	mapIterators(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//--------------------------ITERATORS-----------------------------//")
	LOG1("")
	LOG1("IT")
	NAMESP::map<char,int> map1;

	map1['b'] = 100;
	map1['a'] = 200;
	map1['c'] = 300;

	LOG2("Size = : ", int(map1.size()))

	NAMESP::map<char,int>::iterator it = map1.begin();
	NAMESP::map<char,int>::iterator ite = map1.end();
	LOG1("map1 content:")
	while (it != ite) {

		LOG2("Iterator first = ", it->first)
		LOG2("Iterator second = ", it->second)
		++it;
	}

	LOG1("")
	LOG1("REVERSE IT")
	NAMESP::map<char,int>::reverse_iterator revIt = map1.rbegin();
	NAMESP::map<char,int>::reverse_iterator revIte = map1.rend();

	LOG1("map1 reverse content:")
	while (revIt != revIte) {

		LOG2("Iterator first = ", revIt->first)
		LOG2("Iterator second = ", revIte->second)
		++revIt;
	}
}
