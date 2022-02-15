/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapKeyValueComp.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:56:11 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 00:34:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	mapKeyValueComp(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//---------------------------KEYCOMP------------------------------//")
	LOG1("//--------------------------VALUECOMP-----------------------------//")
	LOG1("")
	NAMESP::map<char,int> map1;
	NAMESP::map<char,int>::key_compare comp = map1.key_comp();

	map1['a'] = 100;
	map1['b'] = 200;
	map1['c'] = 300;

	char lastKey = map1.rbegin()->first;
	LOG1("map1 content:")
	NAMESP::map<char,int>::iterator it = map1.begin();
	while (comp((*it).first, lastKey)) {

		LOG2("first value ", it->first)
		LOG2("second value ", it->second)
		++it;
	}//value
}
