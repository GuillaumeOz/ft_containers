/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:21:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/12/28 18:00:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
// #include "utils.hpp"
#include "vector.hpp"

int main(int ac, char **av) {

	std::vector<int>		vector {0, 1, 2, 3, 4};
	ft::vector<int>			myVector {0, 1, 2, 3, 4};

	auto rv = std::reverse_iterator {v.rbegin()};
	std::cout << *(++rv) << ' '; // 3
	std::cout << *(--rv) << ' '; // 4
	std::cout << *(rv + 3) << ' '; // 1
	rv += 3;
	std::cout << rv[0] << ' '; // 1
	rv -= 3;
	std::cout << rv[0] << '\n'; // 4
 
	std::list l {5, 6, 7, 8};
	auto rl = std::reverse_iterator {l.rbegin()};
	std::cout << *(++rl) << ' '; // OK: 3
	std::cout << *(--rl) << ' '; // OK: 4
	
	return 0;
}

// iterators_traits, reverse_iterator, enable_if,
//  is_integral, equal/lexicographical compare, 
//  std::pair, std::make_pair, doivent être réimplémenté.