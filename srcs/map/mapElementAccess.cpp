/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapElementAccess.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:41:08 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 14:48:53 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	mapElementAccess(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//-------------------------ELEMENTACCESS--------------------------//")
	LOG1("")
    NAMESP::map<char,std::string> map1;

    map1['a'] = "Salut";
    map1['b'] = "Coucou";
    map1['c'] = map1['b'];

	LOG2("map1['a'] is ", map1['a'])
	LOG2("map1['b'] is ", map1['b'])
	LOG2("map1['c'] is ", map1['c'])
	LOG2("map1['d'] is ", map1['d'])

	LOG2("map1 size is", map1.size())
}
