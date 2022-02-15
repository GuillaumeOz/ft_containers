/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setLowerUpperBoundEqualRange.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:47:08 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 02:19:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	setLowerUpperBoundEqualRange(std::ofstream &outfile)
{
	LOG1("")
	LOG1("//----------------------------LOWERBOUND--------------------------//")
	LOG1("//----------------------------UPPERBOUND--------------------------//")
	LOG1("//----------------------------EQUALRANGE--------------------------//")
	LOG1("")

	NAMESP::set<int> set1;
	NAMESP::set<int>::iterator itLower;
	NAMESP::set<int>::iterator itUpper;

	set1.insert(20);
	set1.insert(40);
	set1.insert(60);
	set1.insert(80);
	set1.insert(100);

	itLower = set1.lower_bound(40);
	itUpper = set1.upper_bound(80);

	set1.erase(itLower, itUpper);

	LOG1("set1 content:")

	for (NAMESP::set<int>::iterator it = set1.begin(); it != set1.end(); ++it) {

		LOG2("Value", *it)
	}

	set1.insert(150);
	set1.insert(200);

	NAMESP::pair<NAMESP::set<int>::iterator, NAMESP::set<int>::iterator> ret;
	ret = set1.equal_range(150);

	LOG1("lower bound points to: ")
	LOG2("Value", *ret.first)

	LOG1("upper bound points to: ")
	LOG2("Value", *ret.second)

	// NAMESP::set<int> set2;
	// int i = 0;

	// while (i < 1000000) {

	// 	set2.insert(i);
	// 	i++;
	// }

}
