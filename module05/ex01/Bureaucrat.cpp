/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:56:13 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 10:47:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name_(name), grade_(grade) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other)
    this->grade_ = other.grade_;
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::incrementGrade() {
  if (grade_-- <= 1)
    throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
  if (grade_++ >= 150)
    throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return os;
}

void Bureaucrat::signForm(Form& form) {
  try {
    form.beSigned(*this);
    std::cout << getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << getName() << " couldn’t sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}
