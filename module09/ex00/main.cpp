/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:41:36 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 14:59:09 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "usage: ./btc input_file" << std::endl;
    return 1;
  }

  BitcoinExchange b;

  b.loadDatabase("data.csv");
  b.processInput(argv[1]);

  return 0;
}
