/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:21:48 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/13 20:44:21 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_containers.hpp"

static void	vectorTests() {

	std::ofstream outfile;

	outfile.open(VECTORNAME);

	vectorConstructor(outfile);
	vectorAssignation(outfile);
	vectorIterators(outfile);
	vectorSize(outfile);
	vectorResize(outfile);



	
	outfile.close();
}

static void setTests() {

	print("-----------------------------SET----------------------------------");
	ft::set<int> set;
//   std::set<int> myset;

//   for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

//   std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
//   ret = myset.equal_range(30);

//   std::cout << "the lower bound points to: " << *ret.first << '\n';
//   std::cout << "the upper bound points to: " << *ret.second << '\n';

//   return 0;

}

static void mapTests() {

	print("-----------------------------MAP----------------------------------");
	ft::map<int, int> map;

	map.insert(ft::pair<int,int>(1,8));
	map.insert(ft::pair<int,int>(7,6));
	map.insert(ft::pair<int,int>(3,8));
	map.insert(ft::pair<int,int>(4,8));
	map.insert(ft::pair<int,int>(5,8));
	map.insert(ft::pair<int,int>(2,8));
	map.insert(ft::pair<int,int>(6,2));

	ft::map<int,int>::const_iterator it = map.begin(), ite = map.end();
	std::cout << std::endl << "Content is:" << std::endl;
	for (; it != ite; ++it) {

		std::cout << "|  key: " << it->first << "   " << "value: " << it->second << "  |" << std::endl;
	}

	ft::map<int, int> map2(map.begin(), map.end());
	

	std::cout << "size: " << map2.size() << std::endl;
	std::cout << "max_size: " << map2.max_size() << std::endl;

	ft::map<int,int>::const_iterator it2 = map2.begin(), ite2 = map2.end();
	std::cout << std::endl << "Content is:" << std::endl;
	for (; it2 != ite2; ++it2) {

		std::cout << "|  key: " << it2->first << "   " << "value: " << it2->second << "  |" << std::endl;
	}

	std::cout << "###############################################" << std::endl;

	// ft::map<int,int>::iterator it = map.begin(), ite = map.end();
	// std::cout << std::endl << "Content is:" << std::endl;
	// for (; it != ite; ++it) {

	// 	std::cout << "|  key: " << it->first << "   " << "value: " << it->second << "  |" << std::endl;
	// }

	// map.clear();

	print("")

	// ft::map<char, float>	map2;

	// map2['a'] = 2.3;
	// map2['b'] = 1.4;
	// map2['c'] = 0.3;
	// map2['d'] = 4.2;

	// ft::map<char, float>::const_iterator itBegin = map2.begin();
	// ft::map<char, float>::const_iterator itBegin2 = map2.begin();

	// ft::map<char,float>::iterator it5 = map2.begin();
	// bool res[2];

	// for (ft::map<char, float>::const_iterator itBegin = map2.begin(); itBegin != map2.end(); ++itBegin) {

	// 	for (ft::map<char, float>::const_iterator itBegin2 = map2.begin(); itBegin2 != map2.end(); ++itBegin2){


	// 		std::cout << "\t-- [" << ++i << "] --" << std::endl;
	// 		res[0] = map2.key_comp()(itBegin->first, itBegin2->first);
	// 		res[1] = map2.value_comp()(*itBegin, *itBegin2);
	// 		std::cout << "with [" << itBegin->first << " and " << itBegin2->first << "]: ";
	// 		std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
	// 	}
	// }



}

static void stackTests() {

	print("----------------------------STACK---------------------------------");
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
