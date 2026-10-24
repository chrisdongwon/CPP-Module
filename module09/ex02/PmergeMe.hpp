/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:35:54 by cwon              #+#    #+#             */
/*   Updated: 2026/10/24 17:39:46 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(int argc, char** argv);
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void sortAndDisplay();

 private:
  template <typename Container>
  struct Original {
    explicit Original(const Container& input) : values_(input) {}

    bool less(int lhs, int rhs) const {
      return values_[lhs] < values_[rhs];
    }

    const Container& values_;
  };

  template <typename Container>
  struct LessThan {
    explicit LessThan(const Original<Container>* original)
        : original_(original) {}

    bool operator()(int lhs, int rhs) const {
      return original_->less(lhs, rhs);
    }

    const Original<Container>* original_;
  };

  template <typename Container>
  static Container jacobsthalOrder(size_t count) {
    Container result;
    size_t prev = 1;
    size_t n = 3;

    while (prev < count) {
      size_t upper = std::min(jacobsthal(n), count);

      for (size_t rank = upper; rank > prev; --rank) {
        result.push_back(rank);
      }

      prev = upper;
      ++n;
    }
    return result;
  }

  template <typename Container>
  static void print(const Container& c) {
    typename Container::const_iterator it = c.begin();
    while (it != c.end()) {
      std::cout << *it;
      ++it;
      if (it != c.end())
        std::cout << ' ';
    }
    std::cout << '\n';
  }

  static size_t jacobsthal(size_t n);
  static std::vector<int> sortIndices(const std::vector<int>& indices,
                                      const Original<std::vector<int> >& o);
  static std::deque<int> sortIndices(const std::deque<int>& indices,
                                     const Original<std::deque<int> >& o);

  void sort(std::deque<int> seq);
  void sort(std::vector<int> seq);

  std::deque<int> deque_;
  std::vector<int> vect_;
};

#endif  // PMERGEME_HPP_
