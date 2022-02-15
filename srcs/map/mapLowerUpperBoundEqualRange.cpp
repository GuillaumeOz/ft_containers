/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapLowerUpperBoundEqualRange.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:47:08 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 01:16:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	mapLowerUpperBoundEqualRange(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//----------------------------LOWERBOUND--------------------------//")
	LOG1("//----------------------------UPPERBOUND--------------------------//")
	LOG1("//----------------------------EQUALRANGE--------------------------//")
	LOG1("")

	NAMESP::map<char,int> map1;
	NAMESP::map<char,int>::iterator itLower;
	NAMESP::map<char,int>::iterator itUpper;

	map1['a'] = 20;
	map1['b'] = 40;
	map1['c'] = 60;
	map1['d'] = 80;
	map1['e'] = 100;

	itLower = map1.lower_bound ('b');
	itUpper = map1.upper_bound ('d');

	map1.erase(itLower, itUpper);

	LOG1("map1 content:")

	for (NAMESP::map<char,int>::iterator it = map1.begin(); it != map1.end(); ++it) {

		LOG2("First", it->first)
		LOG2("Second", it->second)
	}

	map1['b'] = 20;
	map1['c'] = 30;

	NAMESP::pair<NAMESP::map<char,int>::iterator, NAMESP::map<char,int>::iterator> ret;
	ret = map1.equal_range('b');

	LOG1("lower bound points to: ")
	LOG2("First", ret.first->first)
	LOG2("Second", ret.first->second)

	LOG1("upper bound points to: ")
	LOG2("First", ret.second->first)
	LOG2("Second", ret.second->second)

	// NAMESP::map<char,int> map2;
	// int i = 0;

	// while (i < 1000000) {

	// 	map2.insert(NAMESP::pair<int,int>(i,i));
	// 	i++;
	// }

}
