/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackConstructor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:43:34 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 12:57:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	stackConstructor(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//---------------------------CONSTRUCTOR--------------------------//")
	LOG1("")
	
	NAMESP::vector<int> vect1(2,200);

	NAMESP::stack<int> stack1;

	NAMESP::stack<int, NAMESP::vector<int> > stack2;
	NAMESP::stack<int, NAMESP::vector<int> > stack3 (vect1);

	LOG2("size of stack1: ", stack1.size())
	LOG2("size of stack2: ", stack2.size())
	LOG2("size of stack3: ", stack3.size())
}