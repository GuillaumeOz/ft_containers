/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:21:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/12/27 18:34:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

int main() {

  
    // allocator for integer values
    std::allocator<int> myAllocator;
  
    // allocate space for five ints
    int* arr = myAllocator.allocate(5);
  
    // construct arr[0] and arr[3]
	for (int i = 0; i < 5; i++)
	{
    	// myAllocator.construct(arr, i);
		arr[i] = i;
    	std::cout << arr[i] << std::endl;
	}
    // deallocate space for five ints
    myAllocator.deallocate(arr, 5);
	
    return 0;
}

// iterators_traits, reverse_iterator, enable_if,
//  is_integral, equal/lexicographical compare, 
//  std::pair, std::make_pair, doivent être réimplémenté.