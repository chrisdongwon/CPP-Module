/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:03:08 by cwon              #+#    #+#             */
/*   Updated: 2025/08/26 14:35:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <string>

class Brain {
 public:
  Brain( void );
  Brain(const Brain& other);

  Brain& operator=(const Brain& other);

  ~Brain();

  std::string ideas(int i) const;
  void set_ideas(int i, const std::string& idea);

 private:
  std::string ideas_[100];
};

#endif // BRAIN_HPP_
