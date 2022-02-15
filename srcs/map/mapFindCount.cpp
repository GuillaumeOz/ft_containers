/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapFindCount.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:30:04 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 00:46:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	mapFindCount(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//------------------------------FIND------------------------------//")
	LOG1("//------------------------------COUNT-----------------------------//")
	LOG1("")

	NAMESP::map<char,int> map1;

	map1['a'] = 100;
	map1['b'] = 200;
	map1['c'] = 300;

	NAMESP::map<char,int>::iterator it;

	it = map1.find('b');
	if (it != map1.end())
		map1.erase (it);

	LOG1("elements in map1:")
	LOG2("a => ", map1.find('a')->second)
	LOG2("c => ", map1.find('c')->second)

	it = map1.begin();
	NAMESP::map<char,int>::iterator ite = map1.end();

	while (it != ite) {

		if (map1.count('c') > 0)
			LOG1("find in map")
		else
			LOG1("not find")
		++it;
	}
}
