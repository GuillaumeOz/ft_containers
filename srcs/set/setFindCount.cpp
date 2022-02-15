/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setFindCount.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:30:04 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 02:13:41 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	setFindCount(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//------------------------------FIND------------------------------//")
	LOG1("//------------------------------COUNT-----------------------------//")
	LOG1("")

	NAMESP::set<int> set1;

	set1.insert(100);
	set1.insert(200);
	set1.insert(300);

	NAMESP::set<int>::iterator it;

	it = set1.find(200);
	if (it != set1.end())
		set1.erase (it);

	LOG1("elements in set1:")
	LOG2("set1 first value ", *set1.begin())
	LOG2("set1 last value ", *set1.rbegin())

	it = set1.begin();
	NAMESP::set<int>::iterator ite = set1.end();

	while (it != ite) {

		if (set1.count(100) > 0)
			LOG1("find in set")
		else
			LOG1("not find")
		++it;
	}
}
