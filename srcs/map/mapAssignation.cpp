/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapAssignation.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:46:50 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 14:19:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	mapAssignation(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//------------------------CONSTRUCTORS----------------------------//")
	LOG1("")

	NAMESP::map<char,int> map1;
	NAMESP::map<char,int> map2;

	map1['x'] = 8;
	map1['y'] = 16;
	map1['z'] = 32;

	map2 = map1;
	map1 = NAMESP::map<char,int>();

	LOG2("Size of map1: ", map1.size())
	LOG2("Size of map2: ", map2.size())
}
