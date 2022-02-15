/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAssign.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:16:20 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 11:29:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorAssign(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//-----------------------------ASSIGN-----------------------------//")
	LOG1("")
	NAMESP::vector<int> vect1(10);

    vect1.assign(7,100);

	LOG2("Size of vect1: ", int(vect1.size()))

    NAMESP::vector<int>::iterator it = vect1.begin();
    NAMESP::vector<int>::iterator ite = vect1.end();
    while (it != ite) {
        	
        LOG1(*it)
        ++it;
    }
}
