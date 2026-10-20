/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:35:54 by cwon              #+#    #+#             */
/*   Updated: 2026/10/20 18:49:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <iostream>
#include <list>
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
  static void print(const Container& container) {
    typename Container::const_iterator it = container.begin();
    while (it != container.end()) {
      std::cout << *it;
      ++it;
      if (it != container.end())
        std::cout << ' ';
    }
    std::cout << '\n';
  }
  
  void sort(std::list<int> seq);
  void sort(std::vector<int> seq);

  std::list<int> list_;
  std::vector<int> vect_;
};

#endif  // PMERGEME_HPP_
