/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setKeyValueComp.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:56:11 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 02:07:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	setKeyValueComp(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//---------------------------KEYCOMP------------------------------//")
	LOG1("//--------------------------VALUECOMP-----------------------------//")
	LOG1("")
	NAMESP::set<int> set1;
	NAMESP::set<int>::key_compare comp = set1.key_comp();

	set1.insert(100);
	set1.insert(200);
	set1.insert(300);

	char highvalue = *set1.rbegin();
	LOG1("set1 content:")
	NAMESP::set<int>::iterator it = set1.begin();
	while (comp((*it), highvalue)) {

		LOG2("until high value ", *it)
		++it;
	}//value
}
