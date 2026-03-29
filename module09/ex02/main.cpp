/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:44:01 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 15:44:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Error: no input provided" << std::endl;
    return 1;
  }

  PmergeMe p;

  p.parseArguments(argc, argv);
  p.sortAndDisplay();

  return 0;
}
