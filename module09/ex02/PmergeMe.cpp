#include "PmergeMe.hpp"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : deq_(other.deq_), vec_(other.vec_) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    deq_ = other.deq_;
    vec_ = other.vec_;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::validateArg(const char* arg) {
  if (!arg || *arg == '\0')
    return false;

  for (size_t i = 0; arg[i]; i++) {
    if (!isdigit(arg[i]))
      return false;
  }

  long val = std::atol(arg);
  if (val <= 0 || val > 2147483647)
    return false;

  return true;
}

void PmergeMe::parseArguments(int argc, char** argv) {
  for (int i = 1; i < argc; ++i) {
    if (!validateArg(argv[i])) {
      std::cerr << "Error: invalid argument '" << argv[i] << "'" << std::endl;
      exit(1);
    }

    int val = std::atoi(argv[i]);
    vec_.push_back(val);
    deq_.push_back(val);
  }
}

void PmergeMe::insertSortedVector(std::vector<int>& sorted, int value) {
  std::vector<int>::iterator it =
      std::lower_bound(sorted.begin(), sorted.end(), value);
  sorted.insert(it, value);
}

void PmergeMe::insertSortedDeque(std::deque<int>& sorted, int value) {
  std::deque<int>::iterator it =
      std::lower_bound(sorted.begin(), sorted.end(), value);
  sorted.insert(it, value);
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& seq) {
  if (seq.size() <= 1)
    return;

  std::vector<int> sorted;

  for (size_t i = 0; i + 1 < seq.size(); i += 2) {
    if (seq[i] > seq[i + 1])
      std::swap(seq[i], seq[i + 1]);
    sorted.push_back(seq[i + 1]);
  }

  if (seq.size() % 2)
    sorted.push_back(seq.back());

  std::sort(sorted.begin(), sorted.end());

  for (size_t i = 0; i + 1 < seq.size(); i += 2)
    insertSortedVector(sorted, seq[i]);

  seq = sorted;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& seq) {
  if (seq.size() <= 1)
    return;

  std::deque<int> sorted;

  for (size_t i = 0; i + 1 < seq.size(); i += 2) {
    if (seq[i] > seq[i + 1])
      std::swap(seq[i], seq[i + 1]);
    sorted.push_back(seq[i + 1]);
  }

  if (seq.size() % 2)
    sorted.push_back(seq.back());

  std::sort(sorted.begin(), sorted.end());

  for (size_t i = 0; i + 1 < seq.size(); i += 2)
    insertSortedDeque(sorted, seq[i]);

  seq = sorted;
}

void PmergeMe::sortAndDisplay() {
  std::cout << "Before: ";
  for (size_t i = 0; i < vec_.size(); i++) {
    std::cout << vec_[i] << " ";
  }
  std::cout << std::endl;

  std::vector<int> vecCopy = vec_;
  clock_t start = clock();
  mergeInsertSortVector(vecCopy);
  clock_t end = clock();
  double vectorTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

  std::deque<int> deqCopy = deq_;
  start = clock();
  mergeInsertSortDeque(deqCopy);
  end = clock();
  double dequeTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

  std::cout << "After: ";
  for (size_t i = 0; i < vecCopy.size(); i++) std::cout << vecCopy[i] << " ";
  std::cout << std::endl;

  std::cout << std::fixed << std::setprecision(3);
  std::cout << "Time to process a range of " << vec_.size()
            << " elements with std::vector: " << vectorTime << " us"
            << std::endl;

  std::cout << "Time to process a range of " << deq_.size()
            << " elements with std::deque: " << dequeTime << " us" << std::endl;
}
