/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:00:40 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 10:21:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP_
#define BASE_HPP_

class Base {
 public:
  virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif  // BASE_HPP_
