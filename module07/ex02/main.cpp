/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:04:23 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 11:44:47 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Array.hpp"

#define MAX_VAL 10

int main() {
  std::cout << "===== Default Constructor Test =====\n";
  Array<int> empty;
  std::cout << "Size: " << empty.size() << std::endl;

  std::cout << "\n===== Constructor with Size =====\n";
  Array<int> numbers(MAX_VAL);

  for (unsigned int i = 0; i < numbers.size(); i++)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;

  std::cout << "\n===== Assign Values =====\n";
  for (unsigned int i = 0; i < numbers.size(); i++) numbers[i] = i * 5;

  for (unsigned int i = 0; i < numbers.size(); i++)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;

  std::cout << "\n===== Copy Constructor =====\n";
  Array<int> copy(numbers);

  for (unsigned int i = 0; i < copy.size(); i++) std::cout << copy[i] << " ";
  std::cout << std::endl;

  std::cout << "\nModify copy[0] = 999\n";
  copy[0] = 999;

  std::cout << "Original:\n";
  for (unsigned int i = 0; i < numbers.size(); i++)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;

  std::cout << "Copy:\n";
  for (unsigned int i = 0; i < copy.size(); i++) std::cout << copy[i] << " ";
  std::cout << std::endl;

  std::cout << "\n===== Assignment Operator =====\n";
  Array<int> assign;
  assign = numbers;

  for (unsigned int i = 0; i < assign.size(); i++)
    std::cout << assign[i] << " ";
  std::cout << std::endl;

  std::cout << "\nModify assign[1] = 777\n";
  assign[1] = 777;

  std::cout << "Original:\n";
  for (unsigned int i = 0; i < numbers.size(); i++)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;

  std::cout << "Assigned:\n";
  for (unsigned int i = 0; i < assign.size(); i++)
    std::cout << assign[i] << " ";
  std::cout << std::endl;

  std::cout << "\n===== Const Array Test =====\n";
  const Array<int> constArr(numbers);

  for (unsigned int i = 0; i < constArr.size(); i++)
    std::cout << constArr[i] << " ";
  std::cout << std::endl;

  std::cout << "\n===== String Array Test =====\n";
  Array<std::string> words(3);

  words[0] = "hello";
  words[1] = "cpp";
  words[2] = "templates";

  for (unsigned int i = 0; i < words.size(); i++) std::cout << words[i] << " ";
  std::cout << std::endl;

  std::cout << "\n===== Exception Test =====\n";
  try {
    std::cout << numbers[100] << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception caught: out of bounds access" << std::endl;
  }

  std::cout << "\n===== Empty Array Access Test =====\n";
  try {
    std::cout << empty[0] << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception caught: empty array access" << std::endl;
  }

  std::cout << "\n===== All Tests Completed =====\n";

  return 0;
}
