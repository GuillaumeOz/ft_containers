/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackRelationalOperators.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:00:29 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 13:10:27 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	stackRelationalOperators(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//-----------------------RELATIONALOPERATOR-----------------------//")
	LOG1("")

    NAMESP::vector<int> vect1(3,100);
    NAMESP::vector<int> vect2(2,200);

	NAMESP::stack<int, NAMESP::vector<int> > stack1(vect1);
	NAMESP::stack<int, NAMESP::vector<int> > stack2(vect2);

    if (stack1 == stack2)
	    LOG1("stack1 and stack2 are equal")
    if (stack1 != stack2)
	    LOG1("stack1 and stack2 are not equal")
    if (stack1 <  stack2)
	    LOG1("stack1 is less than stack2")
    if (stack1 >  stack2)
	    LOG1("stack1 is greater than stack2")
    if (stack1 <= stack2)
	    LOG1("stack1 is less than or equal to stack2")
    if (stack1 >= stack2)
	    LOG1("stack1 is greater than or equal to stack2")
}