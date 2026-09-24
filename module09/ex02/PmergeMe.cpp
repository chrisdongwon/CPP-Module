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

void PmergeMe::FordJohnson(std::vector<int>& seq) {
  (void)seq;
  std::cout << "Nothing to do here yet" << std::endl;
}

void PmergeMe::FordJohnson(std::list<int>& seq) {
  (void)seq;
  std::cout << "Nothing to do here yet" << std::endl;
}
