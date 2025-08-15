/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:09:11 by cwon              #+#    #+#             */
/*   Updated: 2025/08/14 17:27:19 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  explicit Zombie(const std::string& name);
  ~Zombie( void );

  void announce( void );

 private:
  std::string name_;
};

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

#endif  // ZOMBIE_HPP_
