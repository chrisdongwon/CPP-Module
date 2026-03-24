/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:55:21 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 10:56:42 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "iter.hpp"

template <typename T>
static void print(const T& x) {
  std::cout << x << std::endl;
}

static void increment(int& x) {
  x++;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  size_t len = 5;

  std::cout << "Original array:" << std::endl;
  iter(arr, len, print<int>);

  iter(arr, len, increment);

  std::cout << "\nAfter increment:" << std::endl;
  iter(arr, len, print<int>);

  std::string str[] = {"hello", "world", "cpp"};

  std::cout << "\nString array:" << std::endl;
  iter(str, 3, print<std::string>);

  return 0;
}
