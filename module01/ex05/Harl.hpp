/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:48:19 by cwon              #+#    #+#             */
/*   Updated: 2025/10/13 15:06:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
#define HARL_HPP_

#include <string>

class Harl {
 public:
  Harl( void );
  void complain(std::string level);

 private:
  void debug( void );
  void error( void );
  void info ( void );
  void warning( void );

  struct Level {
    const std::string name;
    void (Harl::*func)( void );
  };
  
  static const Level levels_[4];
};

#endif // HARL_HPP_
