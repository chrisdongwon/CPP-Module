/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:08:39 by cwon              #+#    #+#             */
/*   Updated: 2025/10/13 15:36:04 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
#define HARL_HPP_

#include <string>

class Harl {
 public:
  explicit Harl(const char *level);
  int HarlFilter( void );

 private:
  enum HarlLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    NONE
  };

  struct Level {
    const std::string name;
    enum HarlLevel harl_level;
  };

  HarlLevel GetLevel(const std::string& level) const;

  void debug( void );
  void info ( void );
  void warning( void );
  void error( void );

  static const Level levels_[4];
  std::string level_;
};

#endif // HARL_HPP_
