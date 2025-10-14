/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:08:33 by cwon              #+#    #+#             */
/*   Updated: 2025/10/14 11:39:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <cstdlib>
#include <iostream>

const Harl::Level Harl::levels_[4] = {
  {"DEBUG", DEBUG},
  {"INFO", INFO},
  {"WARNING", WARNING},
  {"ERROR", ERROR}
};

Harl::Harl(const char *level): level_(level) {}

int Harl::HarlFilter( void ) {
  switch (GetLevel(level_)) {
    case DEBUG:
      debug();
      // fall through
    case INFO:
      info();
      // fall through
    case WARNING:
      warning();
      // fall through
    case ERROR:
      error();
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]"
                << std::endl;
      return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

Harl::HarlLevel Harl::GetLevel(const std::string& level) const
{
  for (int i = 0; i < 4; ++i) {
    if (levels_[i].name == level) {
      return levels_[i].harl_level;
    }
  }
  return NONE;
}

void Harl::debug( void ) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "I love having extra bacon for my "
            << "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
            << "I really do!\n" << std::endl;
}

void Harl::info ( void ) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money.\n"
            << "You didn't put enough bacon in my burger! "
            << "If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning( void ) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free.\n"
            << "I've been coming for years, whereas you started working here "
            << "just last month.\n" << std::endl;
}

void Harl::error( void ) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now.\n"
            << std::endl;
}
