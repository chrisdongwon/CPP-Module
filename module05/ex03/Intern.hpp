/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:08:15 by cwon              #+#    #+#             */
/*   Updated: 2026/03/20 11:08:43 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <string>

#include "AForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern& other);
  Intern& operator=(const Intern& other);
  ~Intern();

  AForm* makeForm(const std::string& name, const std::string& target);

 private:
  AForm* createShrubbery(const std::string& target);
  AForm* createRobotomy(const std::string& target);
  AForm* createPardon(const std::string& target);
};

#endif  // INTERN_HPP_
