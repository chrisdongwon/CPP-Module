/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 17:40:22 by cwon              #+#    #+#             */
/*   Updated: 2026/10/24 17:41:13 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <sys/time.h>

#include <algorithm>
#include <climits>
#include <limits>

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
    deque_.push_back(value);
    vect_.push_back(value);
  }
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : deque_(other.deque_), vect_(other.vect_) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    deque_ = other.deque_;
    vect_ = other.vect_;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortAndDisplay() {
  std::cout << "Before: ";
  print(vect_);

  timeval start, end;

  gettimeofday(&start, NULL);
  sort(vect_);
  gettimeofday(&end, NULL);
  long vectorTime = elapsedMicroseconds(start, end);

  gettimeofday(&start, NULL);
  sort(deque_);
  gettimeofday(&end, NULL);
  long listTime = elapsedMicroseconds(start, end);

  std::cout << "After:  ";
  print(deque_);

  std::cout << "Time to process a range of " << vect_.size()
            << " elements with std::vector : " << vectorTime << " us" << '\n';

  std::cout << "Time to process a range of " << deque_.size()
            << " elements with std::deque : " << listTime << " us" << '\n';
}

size_t PmergeMe::jacobsthal(size_t n) {
  if (n >= std::numeric_limits<size_t>::digits)
    return std::numeric_limits<size_t>::max();

  size_t powerOfTwo = static_cast<size_t>(1) << n;

  if (n % 2 == 0)
    return (powerOfTwo - 1) / 3;
  return (powerOfTwo + 1) / 3;
}

void PmergeMe::sort(std::deque<int> seq) {
  Original<std::deque<int> > o(seq);
  std::deque<int> indices, result;

  for (size_t i = 0; i < seq.size(); ++i)
    indices.push_back(static_cast<int>(i));

  indices = sortIndices(indices, o);

  for (size_t i = 0; i < indices.size(); ++i) {
    result.push_back(seq[indices[i]]);
  }

  deque_ = result;
}

void PmergeMe::sort(std::vector<int> seq) {
  Original<std::vector<int> > o(seq);
  std::vector<int> indices, result;

  for (size_t i = 0; i < seq.size(); ++i)
    indices.push_back(static_cast<int>(i));

  indices = sortIndices(indices, o);

  for (size_t i = 0; i < indices.size(); ++i) {
    result.push_back(seq[indices[i]]);
  }

  vect_ = result;
}

std::deque<int> PmergeMe::sortIndices(const std::deque<int>& indices,
                                      const Original<std::deque<int> >& o) {
  const size_t n = indices.size();

  if (n < 2)
    return indices;

  std::deque<int> a;
  std::deque<int> b(o.values_.size(), -1);

  for (size_t i = 0; i + 1 < n; i += 2) {
    int first = indices[i];
    int second = indices[i + 1];

    if (o.less(first, second))
      std::swap(first, second);

    a.push_back(first);
    b[first] = second;
  }

  bool hasStraggler = (n % 2 != 0);
  int straggler = hasStraggler ? indices[n - 1] : -1;

  std::deque<int> sortedA = sortIndices(a, o);
  std::deque<int> mainPos(sortedA.size());
  std::deque<int> chain;

  chain.push_back(b[sortedA[0]]);

  for (size_t i = 0; i < sortedA.size(); ++i) {
    chain.push_back(sortedA[i]);
    mainPos[i] = static_cast<int>(i + 1);
  }

  std::deque<size_t> order =
      jacobsthalOrder<std::deque<size_t> >(sortedA.size());

  for (size_t i = 0; i < order.size(); ++i) {
    size_t rank = order[i];
    int pending = b[sortedA[rank - 1]];
    size_t bound = static_cast<size_t>(mainPos[rank - 1]);

    std::deque<int>::iterator position =
        std::lower_bound(chain.begin(), chain.begin() + bound, pending,
                         LessThan<std::deque<int> >(&o));
    int insertedAt = static_cast<int>(position - chain.begin());

    chain.insert(position, pending);
    for (size_t j = 0; j < mainPos.size(); ++j)
      if (mainPos[j] >= insertedAt)
        ++mainPos[j];
  }

  if (hasStraggler) {
    std::deque<int>::iterator position = std::lower_bound(
        chain.begin(), chain.end(), straggler, LessThan<std::deque<int> >(&o));
    chain.insert(position, straggler);
  }
  return chain;
}

std::vector<int> PmergeMe::sortIndices(const std::vector<int>& indices,
                                       const Original<std::vector<int> >& o) {
  const size_t n = indices.size();

  if (n < 2)
    return indices;

  std::vector<int> a;
  std::vector<int> b(o.values_.size(), -1);

  for (size_t i = 0; i + 1 < n; i += 2) {
    int first = indices[i];
    int second = indices[i + 1];

    if (o.less(first, second))
      std::swap(first, second);

    a.push_back(first);
    b[first] = second;
  }

  bool hasStraggler = (n % 2 != 0);
  int straggler = hasStraggler ? indices[n - 1] : -1;

  std::vector<int> sortedA = sortIndices(a, o);
  std::vector<int> mainPos(sortedA.size());
  std::vector<int> chain;

  chain.push_back(b[sortedA[0]]);

  for (size_t i = 0; i < sortedA.size(); ++i) {
    chain.push_back(sortedA[i]);
    mainPos[i] = static_cast<int>(i + 1);
  }

  std::vector<size_t> order =
      jacobsthalOrder<std::vector<size_t> >(sortedA.size());

  for (size_t i = 0; i < order.size(); ++i) {
    size_t rank = order[i];
    int pending = b[sortedA[rank - 1]];
    size_t bound = static_cast<size_t>(mainPos[rank - 1]);

    std::vector<int>::iterator position =
        std::lower_bound(chain.begin(), chain.begin() + bound, pending,
                         LessThan<std::vector<int> >(&o));
    int insertedAt = static_cast<int>(position - chain.begin());

    chain.insert(position, pending);
    for (size_t j = 0; j < mainPos.size(); ++j)
      if (mainPos[j] >= insertedAt)
        ++mainPos[j];
  }

  if (hasStraggler) {
    std::vector<int>::iterator position = std::lower_bound(
        chain.begin(), chain.end(), straggler, LessThan<std::vector<int> >(&o));
    chain.insert(position, straggler);
  }
  return chain;
}
