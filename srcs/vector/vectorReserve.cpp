/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorReserve.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:56:15 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 12:20:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorReserve(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//----------------------------RESERVE-----------------------------//")
	LOG1("")
	NAMESP::vector<int> vect1;

	LOG1("making vect1 grow:")
	for (int i = 0; i < 100; ++i) {
		vect1.push_back(i);
	}
	LOG2("Capacity : ", vect1.capacity())
}
