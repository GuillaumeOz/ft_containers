/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapSizeMaxSizeEmpty.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:34:43 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 14:40:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	mapSizeMaxSizeEmpty(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//-----------------------------SIZE-------------------------------//")
	LOG1("//----------------------------MAXSIZE-----------------------------//")
	LOG1("//-----------------------------EMPTY------------------------------//")
	LOG1("")
	NAMESP::map<char,int> map1;

	LOG2("empty = ", map1.empty())

	map1['b'] = 100;
	map1['a'] = 200;
	map1['c'] = 300;

	LOG2("0. size: ", map1.size())

	map1.insert(NAMESP::pair<char,int>('g', 42));

	LOG2("1. size: ", map1.size())

	map1.insert(NAMESP::pair<char,int>('i', 21));

	LOG2("2. size: ", map1.size())

	LOG2("max_size = ", map1.max_size())
	LOG2("empty = ", map1.empty())
}
