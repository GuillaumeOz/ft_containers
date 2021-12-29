/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:21:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/12/29 18:17:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
// #include "utils.hpp"
#include <vector>
#include "vector.hpp"

#define bothvector(x)	vectorFile << x ; ftVectorFile << x ;
#define VECTFILE(x,y)	vectorFile << x << y << std::endl;
#define FTVECTFILE(x,y)	ftVectorFile << x << y << std::endl;

# define print(x) std::cout << x << std::endl;

static void mapTests() {

	print("-----------------------------MAP----------------------------------");
}

static void stackTests() {

	print("----------------------------STACK---------------------------------");
}

static void	vectorTests() {

	std::ofstream vectorFile;
	std::ofstream ftVectorFile;

	vectorFile.open ("vectorLog.txt");
	ftVectorFile.open ("ftVectorLog.txt");

//------------------------------CONSTRUCTORS----------------------------------//

	bothvector("**********CONSTRUCTOR BASIC TESTS**********\n")
	bothvector("\n")
	bothvector("Default constructor values :\n")
	bothvector("\n")
	std::vector<int>		vector;
	ft::vector<int>			ftVector;

	VECTFILE("size = ", vector.size());
	FTVECTFILE("size = ",ftVector.size());
	VECTFILE("max_size = ", vector.max_size());
	FTVECTFILE("max_size = ", ftVector.max_size());
	VECTFILE("capacity = ", vector.capacity());
	FTVECTFILE("capacity = ", ftVector.capacity());
	VECTFILE("empty = ", vector.empty());
	FTVECTFILE("empty = ", ftVector.empty());

	bothvector("\n")
	bothvector("Fill constructor :\n")
	bothvector("\n")
	std::vector<int>					vector1(4);
	vector1.push_back(42);
	std::vector<int>::iterator			beginIteratorVector1 = vector1.begin();
	std::vector<int>::iterator			endIteratorVector1 = vector1.end();
	ft::vector<int>						ftVector1(4);
	ftVector1.push_back(42);
	ft::vector<int>::iterator			beginIteratorftVector1 = ftVector1.begin();
	ft::vector<int>::iterator			endIteratorftVector1 = ftVector1.end();

	VECTFILE("size = ", vector1.size());
	FTVECTFILE("size = ",ftVector1.size());
	VECTFILE("max_size = ", vector1.max_size());
	FTVECTFILE("max_size = ", ftVector1.max_size());
	VECTFILE("capacity = ", vector1.capacity());
	FTVECTFILE("capacity = ", ftVector1.capacity());
	VECTFILE("empty = ", vector1.empty());
	FTVECTFILE("empty = ", ftVector1.empty());

	while (beginIteratorVector1 != endIteratorVector1)
	{
		print(*beginIteratorVector1)
		beginIteratorVector1++;
	}
	while (beginIteratorftVector1 != endIteratorftVector1)
	{
		print(*beginIteratorftVector1)
		beginIteratorftVector1++;
	}

	vectorFile.close();
	ftVectorFile.close();
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

	return (0);
}
