/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:48:19 by cwon              #+#    #+#             */
/*   Updated: 2025/08/20 07:52:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
#define HARL_HPP_

#include <string>

class Harl {
 public:
  void complain(std::string level);

 private:
  void debug( void );
  void error( void );
  void info ( void );
  void warning( void );
};

#endif
