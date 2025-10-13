/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:37:58 by cwon              #+#    #+#             */
/*   Updated: 2025/10/13 15:32:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Harl.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
    return EXIT_FAILURE;
  }

  Harl h(argv[1]);

  return h.HarlFilter();
}
