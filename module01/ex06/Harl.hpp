/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:08:39 by cwon              #+#    #+#             */
/*   Updated: 2025/08/20 13:56:52 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
#define HARL_HPP_

#include <map>
#include <string>

class Harl {
 public:
  explicit Harl(const char *level);
  int HarlFilter( void ) const;

 private:
  enum Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR
  };

  void Debug( void ) const;
  void Info ( void ) const;
  void Warning( void ) const;
  void Error( void ) const;

  std::map<std::string, Level> levels_;
  std::string level_;
};

#endif
