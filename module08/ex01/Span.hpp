/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:44:32 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 14:01:53 by cwon             ###   ########.fr       */
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

 private:
  unsigned int maxSize_;
  std::vector<int> numbers_;
};

#endif  // SPAN_HPP_
