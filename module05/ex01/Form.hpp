/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:34:39 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 10:47:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
#define FORM_HPP_

#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
 public:
  Form(const std::string& name, int gradeToSign, int gradeToExecute);
  Form(const Form& other);
  Form& operator=(const Form& other);
  ~Form();

  bool getIsSigned() const;
  const std::string& getName() const;
  int getGradeToExecute() const;
  int getGradeToSign() const;

  void beSigned(const Bureaucrat& b);

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

 private:
  bool isSigned_;
  const int gradeToExecute_;
  const int gradeToSign_;
  const std::string name_;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif  // FORM_HPP_
