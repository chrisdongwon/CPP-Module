#include "PmergeMe.hpp"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : list_(other.list_), vec_(other.vec_) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    list_ = other.list_;
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
    list_.push_back(val);
    vec_.push_back(val);
  }
}

void PmergeMe::process() {
  print("Before", vec_);

  std::vector<int> vecCopy(vec_);
  clock_t start = clock();
  FordJohnson(vecCopy);
  clock_t end = clock();
  double vectorTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

  std::list<int> listCopy = list_;
  start = clock();
  FordJohnson(listCopy);
  end = clock();
  double listTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

  print("After", vecCopy);  // what about listCopy?

  std::cout << std::fixed << std::setprecision(3);
  std::cout << "Time to process a range of\t" << vec_.size()
            << " elements with std::vector: " << vectorTime << " us"
            << std::endl;

  std::cout << "Time to process a range of\t" << list_.size()
            << " elements with std::list: " << listTime << " us" << std::endl;
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

// what if duplicates are found? just call exceoption and exit?
// keep track of the last element if the size is odd
void PmergeMe::FordJohnson(std::vector<int>& seq) {
  if (seq.size() <= 1)
    return;

  // step 1: create pairs, dont forget the straggler
  std::vector<int> input;
  std::vector<Pair> pairs;

  size_t i = 0;

  while (i + 1 < input.size()) {
    int first = input[i];
    int second = input[i + 1];

    if (first < second)
      pairs.push_back(Pair(first, second));
    else
      pairs.push_back(Pair(second, first));
    i += 2;
  }

  bool hasStraggler = (i < input.size());
  int straggler = 0;

  if (hasStraggler)
    straggler = input[i];

  std::vector<int> large;
  for (size_t i = 0; i < pairs.size(); ++i) {
    large.push_back(pairs[i].large);
  }

  // pairs keep the small elements paired with the big elements when sorting
  // step 2: remake the container consisting of the bigger elements
  // step 3: recursive step
  // step 4: merge - jacobsthal insertion order is the optimal implementation
}

void PmergeMe::FordJohnson(std::list<int>& seq) {
  (void)seq;
  std::cout << "nothing done yet" << std::endl;
}
