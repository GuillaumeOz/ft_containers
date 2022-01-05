/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:21:48 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 21:42:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <limits>
#include "utils.hpp"
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
	ft::vector<int>::iterator			endIteratorftVector3 = ftVector2.end();

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
	

	// std::numeric_limits<int>

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


	// typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
	// typedef Alloc																	allocator_type;
	// typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
	// typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
	// typedef const typename ft::iterator<random_access_iterator_tag, T>::pointer		const_pointer;//
	// typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
	// typedef const typename ft::iterator<random_access_iterator_tag, T>::reference	const_reference;
	// typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		iterator;
	// typedef const typename ft::iterator<random_access_iterator_tag, T>::value_type	const_iterator;
	// typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;


	// typedef typename ft::reverseIterator<value_type>			reverse_iterator;
	// typedef const typename ft::reverseIterator<value_type>		const_reverse_iterator;
	// typedef std::ptrdiff_t										difference_type;//
	// typedef size_t												size_type;