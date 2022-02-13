/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorResize.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:43:26 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/13 21:39:14 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorResize(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//---------------------------RESIZE-------------------------------//")
	LOG1("")
	NAMESP::vector<int> vect1;

	for (int i = 1; i < 10; i++)
		vect1.push_back(i);

	vect1.resize(5);
	vect1.resize(8, 100);
	vect1.resize(12);

	LOG1("vect1 contains:")
	for (int i = 0; i < vect1.size(); i++)
		LOG1(vect1[i])
}
