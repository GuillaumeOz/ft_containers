/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setSizeMaxSizeEmpty.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:34:43 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 01:53:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	setSizeMaxSizeEmpty(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//-----------------------------SIZE-------------------------------//")
	LOG1("//----------------------------MAXSIZE-----------------------------//")
	LOG1("//-----------------------------EMPTY------------------------------//")
	LOG1("")
	NAMESP::set<int> set1;

	LOG2("empty = ", set1.empty())

	set1.insert(100);
	set1.insert(200);
	set1.insert(300);

	LOG2("0. size: ", set1.size())

	set1.insert(42);

	LOG2("1. size: ", set1.size())

	set1.insert(43);

	LOG2("2. size: ", set1.size())

	LOG2("max_size = ", set1.max_size())
	LOG2("empty = ", set1.empty())
}
