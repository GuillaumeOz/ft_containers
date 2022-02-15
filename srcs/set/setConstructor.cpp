/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setConstructor.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:53 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 01:23:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	setConstructor(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//------------------------CONSTRUCTORS----------------------------//")
	LOG1("")
	LOG1("DEFAUT CONST")
	NAMESP::set<int>		set1;

	LOG2("size = ", set1.size())
	LOG2("max_size = ", set1.max_size())
	LOG2("capacity = ", set1.empty())

	set1.insert(40);
	set1.insert(41);
	set1.insert(42);
	set1.insert(43);
	set1.insert(44);

	LOG1("")
	LOG1("RANGE CONST")
	NAMESP::set<int>		set2(set1.begin(), set1.end());
	
	LOG2("size = ", set2.size())
	LOG2("max_size = ", set2.max_size())
	LOG2("capacity = ", set2.empty())

	NAMESP::set<int>::iterator			it = set2.begin();
	NAMESP::set<int>::iterator			ite = set2.end();

	while (it != ite) {

		LOG2("Iterator value = ", *it)
		++it;
	}

	LOG1("")
	LOG1("COPY CONST")
	NAMESP::set<int>		set3(set2);

	LOG2("size = ", set3.size())
	LOG2("max_size = ", set3.max_size())
	LOG2("capacity = ", set3.empty())

	it = set3.begin();
	ite = set3.end();
	while (it != ite) {

		LOG2("Iterator value = ", *it)
		++it;
	}
}
