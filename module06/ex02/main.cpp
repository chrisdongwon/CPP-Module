/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:22:17 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 10:22:35 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Base.hpp"

int main() {
  Base* obj = generate();

  std::cout << "\nIdentify by pointer: ";
  identify(obj);

  std::cout << "Identify by reference: ";
  identify(*obj);

  delete obj;

  return 0;
}
