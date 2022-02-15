/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorInsertEraseClear.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:31:35 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 11:50:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorInsertEraseClear(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//-----------------------------INSERT-----------------------------//")
	LOG1("//-----------------------------ERASE------------------------------//")
	LOG1("//-----------------------------CLEAR------------------------------//")
	LOG1("")
	NAMESP::vector<int> vect1(10,100);
	NAMESP::vector<int>::iterator it = vect1.begin();;

	vect1.insert(it , 200);

	LOG1("vect1 content:")
	for (it = vect1.begin(); it < vect1.end(); it++) {

		LOG1(*it)
	}

	vect1.erase(vect1.begin() , ++(++(++(vect1.begin()))));

	LOG1("vect1 content:")
	for (it = vect1.begin(); it < vect1.end(); it++) {

		LOG1(*it)
	}
	
	vect1.clear();
	LOG2("Size of vect1: ", int(vect1.size()))
}