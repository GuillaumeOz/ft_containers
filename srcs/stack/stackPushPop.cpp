/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackPushPop.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:22:59 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 11:30:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	stackPushPop(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//----------------------------PUSHPOP-----------------------------//")
	LOG1("")

	NAMESP::stack<int> stack1;

	LOG1("Pushing in elements")
	for (int i = 0; i < 5; ++i) {

		LOG1(i)
		stack1.push(i);
	}

	LOG1("Popping out elements")
	while (!stack1.empty()) {

		LOG1(stack1.top())
		stack1.pop();
	}
}