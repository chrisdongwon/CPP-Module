/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:08:33 by cwon              #+#    #+#             */
/*   Updated: 2025/08/20 14:31:35 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

Harl::Harl(const char *level): level_(level) {
  levels_.insert(std::make_pair("DEBUG", DEBUG));
  levels_.insert(std::make_pair("INFO", INFO));
  levels_.insert(std::make_pair("WARNING", WARNING));
  levels_.insert(std::make_pair("ERROR", ERROR));
}

int Harl::HarlFilter( void ) const {
  if (levels_.count(level_) == 0) {
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
    return 1;
  }
  switch (levels_.at(level_)) {
    case DEBUG:
      Debug();
      // fall through
    case INFO:
      Info();
      // fall through
    case WARNING:
      Warning();
      // fall through
    case ERROR:
      Error();
      break;
  }
  return 0;
}

void Harl::Debug( void ) const {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "I love having extra bacon for my "
            << "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
            << "I really do!\n" << std::endl;
}

void Harl::Info ( void ) const {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money.\n"
            << "You didn't put enough bacon in my burger! "
            << "If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::Warning( void ) const {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free.\n"
            << "I've been coming for years, whereas you started working here "
            << "just last month.\n" << std::endl;
}

void Harl::Error( void ) const {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now.\n"
            << std::endl;
}
