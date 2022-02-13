/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAssignation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:24:00 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/13 19:10:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorAssignation(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//-------------------------ASSIGNATION----------------------------//")
	std::vector<int> vect1(2, 0);
	std::vector<int> vect2(8, 0);

	vect1 = vect2;

	LOG2("Size = : ", int(vect1.size()))
	LOG2("Size = : ", int(vect2.size()))
}
