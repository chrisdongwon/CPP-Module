/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:44:32 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 14:27:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <exception>
#include <vector>

class Span {
 public:
  Span(unsigned int N);
  Span(const Span& other);
  Span& operator=(const Span& other);
  ~Span();

  void addNumber(int number);
  int shortestSpan() const;
  int longestSpan() const;

  class FullException : public std::exception {
   public:
    const char* what() const throw();
  };

  class NoSpanException : public std::exception {
   public:
    const char* what() const throw();
  };

  template <typename Iterator>
  void addRange(Iterator begin, Iterator end);

 private:
  unsigned int maxSize_;
  std::vector<int> numbers_;
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
  if (numbers_.size() + std::distance(begin, end) > maxSize_)
    throw FullException();

  numbers_.insert(numbers_.end(), begin, end);
}

#endif  // SPAN_HPP_
