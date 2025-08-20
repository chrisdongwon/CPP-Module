/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:48:19 by cwon              #+#    #+#             */
/*   Updated: 2025/08/20 15:23:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
#define HARL_HPP_

#include <map>
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

  std::map<std::string, void (Harl::*)(void)> methods_;
};

#endif // HARL_HPP_
