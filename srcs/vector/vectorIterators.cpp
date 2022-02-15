/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:11:19 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 10:44:39 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorIterators(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//--------------------------ITERATORS-----------------------------//")
	LOG1("")
	NAMESP::vector<int> vect1;
	for (int i = 0; i < 5; i++) {

		vect1.push_back(i);
	}

	LOG2("Size = : ", int(vect1.size()))

	NAMESP::vector<int>::iterator it = vect1.begin();
	NAMESP::vector<int>::const_iterator ite = vect1.end();
	LOG1("vect1 content:")
	while (it != ite) {

		LOG1(*it)
		++it;
	}

	LOG1("")
	LOG1("REVERSE IT")
	NAMESP::vector<int>::reverse_iterator revIt = vect1.rbegin();
	NAMESP::vector<int>::reverse_iterator revIte = vect1.rend();

	LOG1("vect1 reverse content:")
	while (revIt != revIte) {

		LOG1(*revIt)
		++revIt;
	}
}
