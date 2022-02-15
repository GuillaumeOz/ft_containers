/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setInsertEraseClear.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:50:27 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 02:02:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	setInsertEraseClear(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//----------------------------INSERT------------------------------//")
	LOG1("//----------------------------ERASE-------------------------------//")
	LOG1("//----------------------------CLEAR-------------------------------//")
	LOG1("")
	LOG1("//----------------------------INSERT------------------------------//")
	LOG1("")

	NAMESP::set<int> set1;

	set1.insert(100);
	set1.insert(200);

	NAMESP::pair<NAMESP::set<int>::iterator,bool> ret;

	ret = set1.insert(200);

	if (ret.second == false) {

		LOG1("element 200 already in")
	}

	NAMESP::set<int>::iterator it = set1.begin();

	set1.insert(300);
	set1.insert(400);

	NAMESP::set<int> set2;
	set2.insert(set1.begin(),set1.find('c'));

	LOG1("set1 contains:")
	for (it = set1.begin(); it != set1.end(); ++it) {
		
		LOG2("it value ", *it)
	}

	LOG1("set2 contains:")
	for (it = set2.begin(); it != set2.end(); ++it) {
		
		LOG2("it value ", *it)
	}

	LOG1("")
	LOG1("//----------------------------ERASE-------------------------------//")
	LOG1("")

	it = set1.find(200);
	set1.erase (it);

	set1.erase(400);

	for (it = set1.begin(); it != set1.end(); ++it) {

		LOG2("it value ", *it)
	}

	LOG1("")
	LOG1("//----------------------------CLEAR-------------------------------//")
	LOG1("")

	set1.clear();
	set2.clear();

	LOG1("set1 is empty")
	set1.empty();
	LOG1("set2 is empty")
	set2.empty();
}
