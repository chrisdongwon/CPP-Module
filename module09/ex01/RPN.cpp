/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:17:37 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 15:24:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cstdlib>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN& other) : stack_(other.stack_) {}

RPN& RPN::operator=(const RPN& other) {
  if (this != &other) {
    stack_ = other.stack_;
  }
  return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::calculate(char op) {
  if (stack_.size() < 2)
    throw std::runtime_error("Error");

  int b = stack_.top();
  stack_.pop();

  int a = stack_.top();
  stack_.pop();

  int result;

  if (op == '+')
    result = a + b;
  else if (op == '-')
    result = a - b;
  else if (op == '*')
    result = a * b;
  else {
    if (b == 0)
      throw std::runtime_error("Error");
    result = a / b;
  }

  stack_.push(result);
}

void RPN::process(const std::string& expression) {
  for (size_t i = 0; i < expression.length(); ++i) {
    if (expression[i] == ' ')
      continue;

    if (isdigit(expression[i])) {
      stack_.push(expression[i] - '0');
    } else if (isOperator(expression[i])) {
      calculate(expression[i]);
    } else
      throw std::runtime_error("Error");
  }

  if (stack_.size() != 1)
    throw std::runtime_error("Error");

  std::cout << stack_.top() << std::endl;
}
