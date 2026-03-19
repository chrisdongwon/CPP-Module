/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:52:52 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 12:42:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP_
#define AFORM_HPP_

#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
 public:
  AForm(const std::string& name = "", int sign = 150, int exec = 150);
  AForm(const AForm& other);
  AForm& operator=(const AForm& other);
  virtual ~AForm();

  bool getIsSigned() const;
  const std::string& getName() const;
  int getGradeToExecute() const;
  int getGradeToSign() const;

  void beSigned(const Bureaucrat& b);
  void execute(Bureaucrat const& executor) const;

  virtual void executeAction() const = 0;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

  class FormNotSignedException : public std::exception {
   public:
    const char* what() const throw();
  };

 private:
  bool isSigned_;
  const int gradeToExecute_;
  const int gradeToSign_;
  const std::string name_;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif  // AFORM_HPP_
