/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:55:35 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 11:53:21 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int s, int e)
    : isSigned_(false), gradeToExecute_(e), gradeToSign_(s), name_(name) {
  if (s < 1 || e < 1)
    throw GradeTooHighException();
  if (s > 150 || e > 150)
    throw GradeTooLowException();
}

AForm::~AForm() {}

bool AForm::getIsSigned() const {
  return isSigned_;
}

const std::string& AForm::getName() const {
  return name_;
}

int AForm::getGradeToExecute() const {
  return gradeToExecute_;
}

int AForm::getGradeToSign() const {
  return gradeToSign_;
}

void AForm::beSigned(const Bureaucrat& b) {
  if (b.getGrade() > gradeToSign_)
    throw GradeTooLowException();
  isSigned_ = true;
}

void AForm::execute(Bureaucrat const& executor) const {
  if (!isSigned_)
    throw FormNotSignedException();
  if (executor.getGrade() > gradeToExecute_)
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
