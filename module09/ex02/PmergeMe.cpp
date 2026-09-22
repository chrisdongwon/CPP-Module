#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : vec_(other.vec_) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    vec_ = other.vec_;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}
