/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:53:18 by cwon              #+#    #+#             */
/*   Updated: 2025/08/18 16:40:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP_
#define REPLACER_HPP_

#include <string>

class Replacer {
 public:
  Replacer(const std::string &filename,
           const std::string &s1,
           const std::string &s2);

  void Process( void );

 private:
  void Read( void );
  void Replace( void );
  void Write( void ) const;

  std::string filename_;
  std::string s1_;
  std::string s2_;
  std::string content_;
};

void RunReplacer(int argc, char **argv);

#endif  // REPLACER_HPP_
