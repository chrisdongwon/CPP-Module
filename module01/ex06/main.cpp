/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:37:58 by cwon              #+#    #+#             */
/*   Updated: 2025/08/20 13:56:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
    return 1;
  }

  Harl h(argv[1]);

  return h.HarlFilter();
}
