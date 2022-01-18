/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:59:15 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/18 14:49:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

# include <iostream>
# include <cstddef>
# include <limits>
# include <fstream>
# include <limits>

# include <cstdlib>//remove

#define print(x)	std::cout << x << std::endl;

# include "utils/lexicographical_compare.hpp"
# include "utils/equal_compare.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/iteratorTraits.hpp"
# include "utils/vectorIterator.hpp"
# include "utils/reverseIterator.hpp"
# include "utils/utils.hpp"
# include "vector.hpp"
# include "stack.hpp"
# include "pair.hpp"
# include "make_pair.hpp"
# include "map.hpp"

#endif
