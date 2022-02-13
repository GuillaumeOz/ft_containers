/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorSize.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:34:43 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/13 20:46:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorSize(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//-----------------------------SIZE-------------------------------//")
	LOG1("//----------------------------MAXSIZE-----------------------------//")
	LOG1("")
	NAMESP::vector<int> vect1;

	LOG2("0. size: ", vect1.size())

	for (int i = 0; i < 10; i++) 
		vect1.push_back(i);

	LOG2("1. size: ", vect1.size())

	vect1.insert(vect1.end(),10,100);

	LOG2("2. size: ", vect1.size())

	vect1.pop_back();

	LOG2("3. size: ", vect1.size())

	LOG2("max_size = ", vect1.max_size())
}
