/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 17:40:22 by cwon              #+#    #+#             */
/*   Updated: 2026/10/20 18:51:57 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <sys/time.h>

#include <climits>

static int parsePositiveInt(const char* str) {
  if (str == NULL || *str == '\0')
    throw std::runtime_error("Error");

  int value = 0;

  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] < '0' || str[i] > '9')
      throw std::runtime_error("Error");

    int digit = str[i] - '0';

    if (value > (INT_MAX - digit) / 10)
      throw std::runtime_error("Error");

    value = value * 10 + digit;
  }

  if (value <= 0)
    throw std::runtime_error("Error");

  return value;
}

static long elapsedMicroseconds(const timeval& start, const timeval& end) {
  return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** argv) {
  if (argc < 2)
    throw std::runtime_error("Error");

  for (int i = 1; i < argc; ++i) {
    int value = parsePositiveInt(argv[i]);
    list_.push_back(value);
    vect_.push_back(value);
  }
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : list_(other.list_), vect_(other.vect_) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    list_ = other.list_;
    vect_ = other.vect_;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortAndDisplay() {
  timeval start, end;
  
  std::cout << "Before: ";
  print(vect_);

  gettimeofday(&start, NULL);
  sort(vect_);
  gettimeofday(&end, NULL);
  long vectorTime = elapsedMicroseconds(start, end);

  gettimeofday(&start, NULL);
  sort(list_);
  gettimeofday(&end, NULL);
  long listTime = elapsedMicroseconds(start, end);

  std::cout << "After:  ";
  print(list_);

  std::cout << "Time to process a range of " << vect_.size()
            << " elements with std::vector : " << vectorTime << " us" << '\n';

  std::cout << "Time to process a range of " << list_.size()
            << " elements with std::list : " << listTime << " us" << '\n';
}

void PmergeMe::sort(std::list<int> seq) {
  (void)seq;
  std::cout << "sort list here" << std::endl;
}

void PmergeMe::sort(std::vector<int> seq) {
  (void)seq;
  std::cout << "sort vector here" << std::endl;
}
