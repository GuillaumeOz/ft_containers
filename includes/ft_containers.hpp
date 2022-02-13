/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:59:15 by gozsertt          #+#    #+#             */
/*   Updated: 2022/02/13 21:40:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

# include <iostream>
// # include <cstddef>
// # include <limits>
# include <fstream>
# include <limits>

# include <vector>
# include <stack>
# include <map>
# include <set>

# include "lexicographical_compare.hpp"
# include "equal_compare.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "iteratorTraits.hpp"
# include "vectorIterator.hpp"
# include "reverseIterator.hpp"
# include "utils.hpp"
# include "vector.hpp"
# include "stack.hpp"
# include "pair.hpp"
# include "make_pair.hpp"
# include "redBlackIterator.hpp"
# include "map.hpp"
# include "set.hpp"

#if (STD == 1)
	#define NAMESP			std
	#define VECTORNAME		"stdVectorFile"
#else
	#define NAMESP			ft
	#define VECTORNAME		"ftVectorFile"
#endif

# define print(x) std::cout << x << std::endl; //remove later

# define LOG1(x)	outfile << x << std::endl;
# define LOG2(x,y)	outfile << x << y << std::endl;


//-----------------------------------VECTOR-----------------------------------//

void	vectorConstructor(std::ofstream &outfile);
void	vectorAssignation(std::ofstream &outfile);
void	vectorIterators(std::ofstream &outfile);
void	vectorSize(std::ofstream &outfile);
void	vectorResize(std::ofstream &outfile);






//------------------------------------STACK-----------------------------------//


#endif
