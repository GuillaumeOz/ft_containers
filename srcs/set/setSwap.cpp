/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setSwap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:24:45 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 02:02:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	setSwap(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//------------------------------SWAP------------------------------//")
	LOG1("")
	NAMESP::set<std::string> set1;
	NAMESP::set<std::string> set2;

	set1.insert("Salut");
	set1.insert("ca va");
	set1.insert("?");

	set2.insert("Oui");
	set2.insert("Bien");
	set2.insert("Et toi ?");

	set1.swap(set2);

	LOG1("set1 contains:")
	for (NAMESP::set<std::string>::iterator it = set1.begin(); it != set1.end(); ++it) {
		
		LOG2("it value ", *it)
	}

	LOG1("set2 contains:")
	for (NAMESP::set<std::string>::iterator it = set2.begin(); it != set2.end(); ++it) {
		
		LOG2("it value ", *it)
	}
}
