/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapConstructor.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:53 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 13:54:58 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	mapConstructor(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//------------------------CONSTRUCTORS----------------------------//")
	LOG1("")
	LOG1("DEFAUT CONST")
	NAMESP::map<int, int>		map1;

	LOG2("size = ", map1.size())
	LOG2("max_size = ", map1.max_size())
	LOG2("capacity = ", map1.empty())

	map1.insert(NAMESP::pair<int,int>(1,40));
	map1.insert(NAMESP::pair<int,int>(2,41));
	map1.insert(NAMESP::pair<int,int>(3,42));
	map1.insert(NAMESP::pair<int,int>(4,43));
	map1.insert(NAMESP::pair<int,int>(5,44));

	LOG1("")
	LOG1("RANGE CONST")
	NAMESP::map<int, int>		map2(map1.begin(), map1.end());
	
	LOG2("size = ", map2.size())
	LOG2("max_size = ", map2.max_size())
	LOG2("capacity = ", map2.empty())

	NAMESP::map<int, int>::iterator			it = map2.begin();
	NAMESP::map<int, int>::iterator			ite = map2.end();

	while (it != ite) {

		LOG2("Iterator first = ", it->first)
		LOG2("Iterator second = ", it->second)
		++it;
	}

	LOG1("")
	LOG1("COPY CONST")
	NAMESP::map<int, int>		map3(map2);

	LOG2("size = ", map3.size())
	LOG2("max_size = ", map3.max_size())
	LOG2("capacity = ", map3.empty())

	it = map3.begin();
	ite = map3.end();
	while (it != ite) {

		LOG2("Iterator first = ", it->first)
		LOG2("Iterator second = ", it->second)
		++it;
	}
}
