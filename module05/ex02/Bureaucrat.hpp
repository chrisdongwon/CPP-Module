/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:45:13 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 12:42:22 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <exception>
#include <iostream>

class AForm;

class Bureaucrat {
 public:
  Bureaucrat(const std::string& name = "", int grade = 150);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);
  ~Bureaucrat();

  const std::string& getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

  void signForm(AForm& form);
  void executeForm(AForm const & form) const;

 private:
  const std::string name_;
  int grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif  // BUREAUCRAT_HPP_
