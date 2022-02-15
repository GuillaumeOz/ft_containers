/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorPushPopBack.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:22:59 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 11:30:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorPushPopBack(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//--------------------------PUSHPOPBACK---------------------------//")
	LOG1("")
	NAMESP::vector<int> vect1;
	for (int i = 0; i < 10; i++) {

		vect1.push_back(i);
	}

	LOG2("Size of vect1: ", int(vect1.size()))
    vect1.pop_back();
	LOG2("Size of vect1: ", int(vect1.size()))
}