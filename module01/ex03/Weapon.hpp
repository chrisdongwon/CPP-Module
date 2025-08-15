/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:54:35 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 01:10:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <string>

class Weapon {
 public:
  explicit Weapon(const std::string& type = "");

  const std::string& getType() const;
  void setType(const std::string& type);

 private:
  std::string type_;
};

#endif  // WEAPON_HPP_
