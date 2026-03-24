/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:01:22 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 14:16:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>

Span::Span(unsigned int N) : maxSize_(N) {}

Span::Span(const Span& other) {
  *this = other;
}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    maxSize_ = other.maxSize_;
    numbers_ = other.numbers_;
  }
  return *this;
}

Span::~Span() {}

const char* Span::FullException::what() const throw() {
  return "Span is full";
}

const char* Span::NoSpanException::what() const throw() {
  return "Not enough numbers to find span";
}

void Span::addNumber(int number) {
  if (numbers_.size() >= maxSize_)
    throw FullException();

  numbers_.push_back(number);
}

int Span::shortestSpan() const {
  if (numbers_.size() < 2)
    throw NoSpanException();

  std::vector<int> temp(numbers_);
  std::sort(temp.begin(), temp.end());

  int minSpan = temp[1] - temp[0];

  for (size_t i = 1; i < temp.size() - 1; i++) {
    int diff = temp[i + 1] - temp[i];
    if (diff < minSpan)
      minSpan = diff;
  }

  return minSpan;
}

int Span::longestSpan() const {
  if (numbers_.size() < 2)
    throw NoSpanException();

  int min = *std::min_element(numbers_.begin(), numbers_.end());
  int max = *std::max_element(numbers_.begin(), numbers_.end());

  return max - min;
}
