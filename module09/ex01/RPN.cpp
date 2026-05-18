/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:17:37 by cwon              #+#    #+#             */
/*   Updated: 2026/05/18 14:35:35 by cwon             ###   ########.fr       */
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

void RPN::process(const std::string& expr) {
  for (size_t i = 0; i < expr.length(); ++i) {
    if (std::isspace(expr[i]))
      continue;

    if (std::isdigit(expr[i])) {
      stack_.push(expr[i] - '0');
    } else if (isOperator(expr[i])) {
      evaluate(expr[i]);
    } else
      throw std::runtime_error("Error");
  }

  if (stack_.size() != 1)
    throw std::runtime_error("Error");

  std::cout << stack_.top() << std::endl;
}

bool RPN::isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::evaluate(char op) {
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
