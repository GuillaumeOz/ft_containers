/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:21:48 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/30 18:02:21 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <stack>
# include <map>
# include "ft_containers.hpp"

#define bothvector(x)	vectorFile << x ; ftVectorFile << x ;
#define VECTFILE(x,y)	vectorFile << x << y << std::endl;
#define FTVECTFILE(x,y)	ftVectorFile << x << y << std::endl;

# define print(x) std::cout << x << std::endl;

static void mapTests() {

	print("-----------------------------MAP----------------------------------");
	std::map<int, int> mtest;

	mtest.insert(std::pair<char,int>(4,8));
	mtest.insert(std::pair<char,int>(5,10));
	mtest.insert(std::pair<char,int>(6,2));
	mtest.insert(std::pair<char,int>(3,6));

	std::map<int,int>::iterator it = mtest.begin(), ite = mtest.end();
	std::cout << std::endl << "Content is:" << std::endl;
	for (; it != ite; ++it) {

		std::cout << "|  key: " << it->first << "   |" << std::endl;
		std::cout << "| value: " << it->second << " |" << std::endl;
	}
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

	std::vector<int>					vector1(2);
	vector1.push_back(40);
	vector1.push_back(41);
	vector1.push_back(42);
	std::vector<int>::iterator			beginIteratorVector1 = vector1.begin();
	std::vector<int>::iterator			endIteratorVector1 = vector1.end();
	ft::vector<int>						ftVector1(2);
	ftVector1.push_back(40);
	ftVector1.push_back(41);
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
		VECTFILE("Iterator value = ", *beginIteratorVector1)
		++beginIteratorVector1;
	}
	while (beginIteratorftVector1 != endIteratorftVector1)
	{
		FTVECTFILE("Iterator value = ", *beginIteratorftVector1)
		++beginIteratorftVector1++;
	}

	beginIteratorVector1 = vector1.begin();
	endIteratorVector1 = vector1.end();
	beginIteratorftVector1 = ftVector1.begin();
	endIteratorftVector1 = ftVector1.end();

	bothvector("\n")
	bothvector("Range constructor :\n")
	bothvector("\n")

	std::vector<int>					vector2(beginIteratorVector1, endIteratorVector1);
	vector2.push_back(100);
	std::vector<int>::iterator			beginIteratorVector2 = vector2.begin();
	std::vector<int>::iterator			endIteratorVector2 = vector2.end();
	ft::vector<int>						ftVector2(beginIteratorftVector1, endIteratorftVector1);
	ftVector2.push_back(100);
	ft::vector<int>::iterator			beginIteratorftVector2 = ftVector2.begin();
	ft::vector<int>::iterator			endIteratorftVector2 = ftVector2.end();

	VECTFILE("size = ", vector2.size());
	FTVECTFILE("size = ",ftVector2.size());
	VECTFILE("max_size = ", vector2.max_size());
	FTVECTFILE("max_size = ", ftVector2.max_size());
	VECTFILE("capacity = ", vector2.capacity());
	FTVECTFILE("capacity = ", ftVector2.capacity());
	VECTFILE("empty = ", vector2.empty());
	FTVECTFILE("empty = ", ftVector2.empty());

	while (beginIteratorVector2 != endIteratorVector2)
	{
		VECTFILE("Iterator value = ", *beginIteratorVector2)
		++beginIteratorVector2;
	}
	while (beginIteratorftVector2 != endIteratorftVector2)
	{
		FTVECTFILE("Iterator value = ", *beginIteratorftVector2)
		++beginIteratorftVector2;
	}

	bothvector("\n")
	bothvector("Copy constructor :\n")
	bothvector("\n")

	std::vector<int>					vector3(vector2);
	std::vector<int>::iterator			beginIteratorVector3 = vector3.begin();
	std::vector<int>::iterator			endIteratorVector3 = vector3.end();
	ft::vector<int>						ftVector3(ftVector2);
	ft::vector<int>::iterator			beginIteratorftVector3 = ftVector3.begin();
	ft::vector<int>::iterator			endIteratorftVector3 = ftVector3.end();

	VECTFILE("size = ", vector3.size());
	FTVECTFILE("size = ",ftVector3.size());
	VECTFILE("max_size = ", vector3.max_size());
	FTVECTFILE("max_size = ", ftVector3.max_size());
	VECTFILE("capacity = ", vector3.capacity());
	FTVECTFILE("capacity = ", ftVector3.capacity());
	VECTFILE("empty = ", vector3.empty());
	FTVECTFILE("empty = ", ftVector3.empty());

	while (beginIteratorVector3 != endIteratorVector3)
	{
		VECTFILE("Iterator value = ", *beginIteratorVector3)
		++beginIteratorVector3;
	}
	while (beginIteratorftVector3 != endIteratorftVector3)
	{
		FTVECTFILE("Iterator value = ", *beginIteratorftVector3)
		++beginIteratorftVector3;
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
