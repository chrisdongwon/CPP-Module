/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:20:33 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 15:21:42 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  try {
    RPN rpn;
    rpn.process(argv[1]);
  } catch (std::exception& e) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  return 0;
}
