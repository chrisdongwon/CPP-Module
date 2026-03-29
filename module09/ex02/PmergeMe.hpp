/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:35:54 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 15:52:07 by cwon             ###   ########.fr       */
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
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void parseArguments(int argc, char** argv);
  void sortAndDisplay();

 private:
  bool validateArg(const char* arg);
  void mergeInsertSortVector(std::vector<int>& seq);
  void mergeInsertSortDeque(std::deque<int>& seq);
  void insertSortedVector(std::vector<int>& sorted, int value);
  void insertSortedDeque(std::deque<int>& sorted, int value);

  std::deque<int> deq_;
  std::vector<int> vec_;
};

#endif  // PMERGEME_HPP_
