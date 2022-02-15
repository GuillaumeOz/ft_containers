/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapInsertEraseClear.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:50:27 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 18:22:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	mapInsertEraseClear(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//----------------------------INSERT------------------------------//")
	LOG1("//----------------------------ERASE-------------------------------//")
	LOG1("//----------------------------CLEAR-------------------------------//")
	LOG1("")
	LOG1("//----------------------------INSERT------------------------------//")
	LOG1("")

	NAMESP::map<char,int> map1;

	map1.insert(NAMESP::pair<char,int>('a',100));
	map1.insert(NAMESP::pair<char,int>('z',200));

	NAMESP::pair<NAMESP::map<char,int>::iterator,bool> ret;

	ret = map1.insert(NAMESP::pair<char,int>('z',500));

	if (ret.second == false) {

		LOG1("element 'z' already in")
		LOG2("with a value of", ret.first->second)
	}

	NAMESP::map<char,int>::iterator it = map1.begin();

	map1.insert(it, NAMESP::pair<char,int>('b',300));
	map1.insert(it, NAMESP::pair<char,int>('c',400));

	NAMESP::map<char,int> map2;
	map2.insert(map1.begin(),map1.find('c'));

	LOG1("map1 contains:")
	for (it = map1.begin(); it != map1.end(); ++it) {
		
		LOG2("first value ", it->first)
		LOG2("second value ", it->second)
	}

	LOG1("map2 contains:")
	for (it = map2.begin(); it != map2.end(); ++it) {
		
		LOG2("first value ", it->first)
		LOG2("second value ", it->second)
	}

	LOG1("")
	LOG1("//----------------------------ERASE-------------------------------//")
	LOG1("")

	it = map1.find('b');
	map1.erase (it);

	map1.erase('z');

	for (it = map1.begin(); it != map1.end(); ++it) {

		LOG2("first value ", it->first)
		LOG2("second value ", it->second)
	}

	LOG1("")
	LOG1("//----------------------------CLEAR-------------------------------//")
	LOG1("")

	map1.clear();
	map2.clear();

	LOG1("map1 is empty")
	map1.empty();
	LOG1("map2 is empty")
	map2.empty();
}
