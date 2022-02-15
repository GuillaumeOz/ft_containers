/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapSwap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:24:45 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 02:00:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	mapSwap(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//------------------------------SWAP------------------------------//")
	LOG1("")
	NAMESP::map<char,std::string> map1;
	NAMESP::map<char,std::string> map2;

	map1['a'] = "Salut";
	map1['b'] = "ca va";
	map1['c'] = "?";

	map2['a'] = "Oui";
	map2['b'] = "Bien";
	map2['c'] = "Et toi ?";

	map1.swap(map2);

	LOG1("map1 contains:")
	for (NAMESP::map<char,std::string>::iterator it = map1.begin(); it != map1.end(); ++it) {
		
		LOG2("first value ", it->first)
		LOG2("second value ", it->second)
	}

	LOG1("map2 contains:")
	for (NAMESP::map<char,std::string>::iterator it = map2.begin(); it != map2.end(); ++it) {
		
		LOG2("first value ", it->first)
		LOG2("second value ", it->second)
	}
}
