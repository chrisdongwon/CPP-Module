/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:55:53 by cwon              #+#    #+#             */
/*   Updated: 2025/10/14 11:43:13 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void ) {
  Harl h;

  h.complain("DEBUG");
  h.complain("INFO");
  h.complain("WARNING");
  h.complain("ERROR");
  return 0;
}
