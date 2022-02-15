/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorElementAccess.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:06:17 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 12:18:08 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorElementAccess(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//-------------------------ELEMENTACCESS--------------------------//")
	LOG1("")
	NAMESP::vector<int> vect1;

	LOG1("Init vect1 :")
	for (int i = 0; i < 100; ++i) {
		vect1.push_back(i);
	}
	LOG2("Random Access : ", vect1[50])
	LOG2("At function : ", vect1.at(42))
	LOG2("Front function : ", vect1.front())
	LOG2("Back function : ", vect1.back())
}