/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:35:54 by cwon              #+#    #+#             */
/*   Updated: 2026/09/24 15:42:23 by cwon             ###   ########.fr       */
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
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void parse(int argc, char** argv);
  void process();

 private:
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
