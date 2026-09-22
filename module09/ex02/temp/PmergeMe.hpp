/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:35:54 by cwon              #+#    #+#             */
/*   Updated: 2026/08/08 09:57:52 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <iostream>
#include <list>
#include <vector>

// suggestion if i choose to use std pair
// typedef std::pair<int, int> Pair;

class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void parse(int argc, char** argv);
  void process();

 private:
  typedef struct Pair {
    int small;
    int large;
    Pair(int s, int l) : small(s), large(l) {}
  } Pair;
  
  bool isPositiveInt(const char* arg);

  void FordJohnson(std::list<int>& seq);
  void FordJohnson(std::vector<int>& seq);

  template <typename Container>
  void print(const std::string& label, const Container& container) {
    std::cout << label << ": ";

    typename Container::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;
  };

  std::list<int> list_;
  std::vector<int> vec_;
};

#endif  // PMERGEME_HPP_
