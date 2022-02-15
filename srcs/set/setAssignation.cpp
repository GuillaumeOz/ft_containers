/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setAssignation.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:46:50 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 01:44:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	setAssignation(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//------------------------CONSTRUCTORS----------------------------//")
	LOG1("")

	NAMESP::set<int> set1;
	NAMESP::set<int> set2;

	set1.insert(8);
	set1.insert(16);
	set1.insert(32);

	set2 = set1;
	set1 = NAMESP::set<int>();

	LOG2("Size of set1: ", set1.size())
	LOG2("Size of set2: ", set2.size())
}
