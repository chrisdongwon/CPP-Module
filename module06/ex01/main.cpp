/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:36:50 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 09:49:47 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main() {
  Data data;

  data.id = 42;
  data.name = "CPP Module";
  data.value = 3.14;

  Data* originalPtr = &data;

  std::cout << "Data content before:\n";
  std::cout << originalPtr->id << std::endl;
  std::cout << originalPtr->name << std::endl;
  std::cout << originalPtr->value << std::endl;

  uintptr_t raw = Serializer::serialize(originalPtr);
  Data* newPtr = Serializer::deserialize(raw);

  std::cout << "\nOriginal pointer: " << originalPtr << std::endl;
  std::cout << "Serialized value: " << raw << std::endl;
  std::cout << "Deserialized pointer: " << newPtr << std::endl;

  if (originalPtr == newPtr)
    std::cout << "SUCCESS: Pointers match!" << std::endl;
  else
    std::cout << "FAIL: Pointers do not match!" << std::endl;

  std::cout << "\nData content after:\n";
  std::cout << newPtr->id << std::endl;
  std::cout << newPtr->name << std::endl;
  std::cout << newPtr->value << std::endl;

  return 0;
}
