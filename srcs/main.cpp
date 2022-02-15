/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:21:48 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/15 02:26:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_containers.hpp"

static void	vectorTests() {

	std::ofstream outfile;

	outfile.open(VECTORNAME);

	vectorConstructor(outfile);
	vectorAssignation(outfile);
	vectorIterators(outfile);
	vectorSizeMaxSizeCapacityEmpty(outfile);
	vectorResize(outfile);
	vectorReserve(outfile);
	vectorElementAccess(outfile);
	vectorAssign(outfile);
	vectorPushPopBack(outfile);
	vectorInsertEraseClear(outfile);
	vectorSwap(outfile);
	vectorRelationalOperators(outfile);
	
	outfile.close();
}

static void stackTests() {

	std::ofstream outfile;

	outfile.open(STACKNAME);

	stackConstructor(outfile);
	stackEmptySizeTop(outfile);
	stackPushPop(outfile);
	stackRelationalOperators(outfile);

	outfile.close();
}

static void mapTests() {

	std::ofstream outfile;

	outfile.open(MAPNAME);

	mapConstructor(outfile);
	mapAssignation(outfile);
	mapIterators(outfile);
	mapSizeMaxSizeEmpty(outfile);
	mapElementAccess(outfile);
	mapInsertEraseClear(outfile);
	mapSwap(outfile);
	mapKeyValueComp(outfile);
	mapFindCount(outfile);
	mapLowerUpperBoundEqualRange(outfile);

	outfile.close();
}

static void setTests() {

	std::ofstream outfile;

	outfile.open(SETNAME);

	setConstructor(outfile);
	setAssignation(outfile);
	setIterators(outfile);
	setSizeMaxSizeEmpty(outfile);
	setInsertEraseClear(outfile);
	setSwap(outfile);
	setKeyValueComp(outfile);
	setFindCount(outfile);


	outfile.close();
}

int main(int ac, char **av) {

	std::string input;

	if (ac != 2)
		return (0);
	input = av[1];
	if (input.compare("vector") == 0)
		vectorTests();
	else if (input.compare("stack") == 0)
		stackTests();
	else if (input.compare("map") == 0)
		mapTests();
	else if (input.compare("set") == 0)
		setTests();
	return (0);
}
