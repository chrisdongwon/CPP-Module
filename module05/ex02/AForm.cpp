/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:55:35 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 10:56:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int s, int e)
    : name(name), isSigned(false), gradeToSign(s), gradeToExecute(e) {
  if (s < 1 || e < 1)
    throw GradeTooHighException();
  if (s > 150 || e > 150)
    throw GradeTooLowException();
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat& b) {
  if (b.getGrade() > gradeToSign)
    throw GradeTooLowException();
  isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const {
  if (!isSigned)
    throw FormNotSignedException();
  if (executor.getGrade() > gradeToExecute)
    throw GradeTooLowException();
  executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
  return "Form not signed";
}
