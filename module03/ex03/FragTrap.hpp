/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:15:03 by cwon              #+#    #+#             */
/*   Updated: 2025/08/24 15:29:33 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
  explicit FragTrap(const std::string& name);
  FragTrap(const FragTrap& other);

  FragTrap& operator=(const FragTrap& other);

  ~FragTrap();

  void highFivesGuys( void );
};

#endif  // FRAGTRAP_HPP_
