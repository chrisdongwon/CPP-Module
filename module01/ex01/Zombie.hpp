/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:42:52 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 00:36:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  explicit Zombie(const std::string& name = "");

  void announce( void );

 private:
  std::string name_;
};

Zombie* zombieHorde(int N, std::string name);

#endif  // ZOMBIE_HPP_
