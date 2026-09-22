#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <vector>

class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

 private:
  std::vector<int> vec_;
};

#endif  // PMERGEME_HPP_
