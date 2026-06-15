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

void PmergeMe::parse(int argc, char** argv) {
  for (int i = 1; i < argc; ++i) {
    if (!isPositiveInt(argv[i]))
      throw std::runtime_error("Error");

    int val = std::atoi(argv[i]);
    vec_.push_back(val);
    deq_.push_back(val);
  }
}

void PmergeMe::process() {
  print("Before", vec_);

  std::vector<int> vecCopy(vec_);
  clock_t start = clock();
  sort(vecCopy);
  clock_t end = clock();
  double vectorTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

  std::deque<int> deqCopy = deq_;
  start = clock();
  sort(deqCopy);
  end = clock();
  double dequeTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

  print("After", vecCopy);

  std::cout << std::fixed << std::setprecision(3);
  std::cout << "Time to process a range of\t" << vec_.size()
            << " elements with std::vector: " << vectorTime << " us"
            << std::endl;

  std::cout << "Time to process a range of\t" << deq_.size()
            << " elements with std::deque: " << dequeTime << " us" << std::endl;
}

bool PmergeMe::isPositiveInt(const char* arg) {
  if (!arg || *arg == '\0')
    return false;

  long value = 0;

  for (size_t i = 0; arg[i]; ++i) {
    if (!std::isdigit(static_cast<unsigned char>(arg[i])))
      return false;

    int digit = arg[i] - '0';

    if (value > (2147483647 - digit) / 10)
      return false;

    value = value * 10 + digit;
  }

  return value > 0;
}

void PmergeMe::sort(std::vector<int>& seq) {
  if (seq.size() <= 1)
    return;

  std::vector<int> a;
  std::vector<int> b;

  for (size_t i = 0; i + 1 < seq.size(); i += 2) {
    if (seq[i] > seq[i + 1]) {
      a.push_back(seq[i]);
      b.push_back(seq[i + 1]);
    } else {
      a.push_back(seq[i + 1]);
      b.push_back(seq[i]);
    }
  }

  print("a", a);
  print("b", b);



  // seq = result;
}

void PmergeMe::sort(std::deque<int>& seq) {
  if (seq.size() <= 1)
    return;

    // std::deque<std::pair<int, int>> temp;

    // for (size_t i = 0; i + 1 < seq.size(); i += 2) {
       
    // }
  // step 3?
}
