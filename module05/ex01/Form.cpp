/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:47:02 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 10:47:28 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : isSigned_(false),
      gradeToExecute_(gradeToExecute),
      gradeToSign_(gradeToSign),
      name_(name) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

Form::Form(const Form& other)
    : isSigned_(other.isSigned_),
      gradeToExecute_(other.gradeToExecute_),
      gradeToSign_(other.gradeToSign_),
      name_(other.name_) {}

Form& Form::operator=(const Form& other) {
  if (this != &other)
    this->isSigned_ = other.isSigned_;
  return *this;
}

Form::~Form() {}

bool Form::getIsSigned() const { return isSigned_; }

const std::string& Form::getName() const { return name_; }

int Form::getGradeToExecute() const { return gradeToExecute_; }

int Form::getGradeToSign() const { return gradeToSign_; }

void Form::beSigned(const Bureaucrat& b) {
  if (b.getGrade() > gradeToSign_)
    throw GradeTooLowException();
  isSigned_ = true;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
  os << "Form " << f.getName()
     << ", signed: " << (f.getIsSigned() ? "yes" : "no")
     << ", grade to sign: " << f.getGradeToSign()
     << ", grade to execute: " << f.getGradeToExecute();
  return os;
}
