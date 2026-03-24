/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:08:39 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 14:09:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Span.hpp"

int main() {
  Span sp(10000);

  srand(time(NULL));

  for (int i = 0; i < 10000; i++) {
    sp.addNumber(rand());
  }

  std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest: " << sp.longestSpan() << std::endl;

  return 0;
}
