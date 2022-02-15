/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorSwap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:51:26 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/14 12:11:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void	vectorSwap(std::ofstream &outfile)
{

	LOG1("")
	LOG1("//-----------------------------SWAP-----------------------------//")
	LOG1("")
	NAMESP::vector<int> vect1(3,100);
	NAMESP::vector<int> vect2(5,200);

	vect1.swap(vect2);

	LOG1("vect1 content:")
	for (int i = 0; i < (int)vect1.size(); i++) {

		LOG1(vect1[i])
	}

	LOG1("vect2 content:")
	for (int i = 0; i < (int)vect2.size(); i++) {
		
		LOG1(vect2[i])
	}
}