/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:08:39 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 14:19:31 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Span.hpp"

int main() {
  try {
    std::cout << "----- Subject Test -----" << std::endl;

    Span sp(5);

    std::vector<int> v;
    v.push_back(6);
    v.push_back(3);
    v.push_back(17);
    v.push_back(9);
    v.push_back(11);

    sp.addRange(v.begin(), v.end());

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;

    std::cout << "\n----- Full Exception Test -----" << std::endl;

    std::vector<int> extra;
    extra.push_back(100);
    sp.addRange(extra.begin(), extra.end());
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "\n----- 10,000 Numbers Test -----" << std::endl;

    Span bigSpan(10000);
    std::vector<int> randomNumbers;

    srand(time(NULL));

    for (int i = 0; i < 10000; i++) randomNumbers.push_back(rand());

    bigSpan.addRange(randomNumbers.begin(), randomNumbers.end());

    std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "\n----- No Span Test -----" << std::endl;

    Span small(5);
    std::vector<int> oneElement;
    oneElement.push_back(42);

    small.addRange(oneElement.begin(), oneElement.end());

    std::cout << small.shortestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
