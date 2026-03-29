/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:15:47 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 15:17:31 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP_
#define RPN_HPP_

#include <stack>
#include <string>

class RPN {
 public:
  RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);
  ~RPN();

  void process(const std::string& expression);

 private:
  bool isOperator(char c);
  void calculate(char op);

  std::stack<int> stack_;
};

#endif  // RPN_HPP_
