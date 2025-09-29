/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:16:56 by cwon              #+#    #+#             */
/*   Updated: 2025/09/29 14:12:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

static std::string Capitalize(const std::string& input) {
  std::string result;
  result.reserve(input.size());

  for (std::string::size_type i = 0; i < input.size(); ++i) {
    unsigned char c = static_cast<unsigned char>(input[i]);
    result += static_cast<char>(std::toupper(c));
  }
  return result;
}

static void PrintMegaphone(int arg_count, char** arg_values) {
  if (arg_count == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    int i = 1;
    while (i < arg_count - 1) {
      std::cout << Capitalize(arg_values[i++]) << ' ';
    }
    std::cout << Capitalize(arg_values[i]) << std::endl;
  }
}

int main(int argc, char** argv) {
  PrintMegaphone(argc, argv);
  return 0;
}
