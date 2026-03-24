/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:29:04 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 12:43:14 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  try {
    std::vector<int>::iterator it = easyfind(v, 2);
    std::cout << "Found: " << *it << std::endl;

    easyfind(v, 10);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
