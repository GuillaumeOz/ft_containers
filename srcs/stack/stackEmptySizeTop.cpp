/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackEmptySizeTop.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:58:15 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 13:29:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	stackEmptySizeTop(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//------------------------------EMPTY-----------------------------//")
	LOG1("//------------------------------SIZE------------------------------//")
	LOG1("//------------------------------TOP-------------------------------//")
	LOG1("")
	
	NAMESP::stack<int> stack1;

	stack1.push(10);
	stack1.push(20);

	stack1.top() -= 5;

	LOG2("stack1 top is now ", stack1.top())
	LOG2("stack1 is empty ? ", stack1.empty())
	LOG2("size of stack1: ", stack1.size())
}