/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorRelationalOperators.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:00:29 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 12:10:41 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorRelationalOperators(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//-----------------------RELATIONALOPERATOR-----------------------//")
	LOG1("")
    
    NAMESP::vector<int> vect1(3,100);
    NAMESP::vector<int> vect2(2,200);

    if (vect1 == vect2)
	    LOG1("vect1 and vect2 are equal")
    if (vect1 != vect2)
	    LOG1("vect1 and vect2 are not equal")
    if (vect1 <  vect2)
	    LOG1("vect1 is less than vect2")
    if (vect1 >  vect2)
	    LOG1("vect1 is greater than vect2")
    if (vect1 <= vect2)
	    LOG1("vect1 is less than or equal to vect2")
    if (vect1 >= vect2)
	    LOG1("vect1 is greater than or equal to vect2")
}