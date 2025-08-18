/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:16:30 by cwon              #+#    #+#             */
/*   Updated: 2025/08/18 16:41:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>

Replacer::Replacer(const std::string &filename,
                   const std::string &s1,
                   const std::string &s2)
    : filename_(filename),
      s1_(s1),
      s2_(s2) {
  if (s1.empty()) {
    throw std::invalid_argument("s1 cannot be empty");
  }
}

void Replacer::Process( void ) {
  Read();
  Replace();
  Write();
}

void Replacer::Read( void ) {
  std::ifstream infile(filename_.c_str());

  if (!infile) {
    throw std::runtime_error("Cannot open input file: " + filename_);
  }
  content_.assign((std::istreambuf_iterator<char>(infile)),
                  std::istreambuf_iterator<char>());
  infile.close();
}

void Replacer::Replace( void ) {
  std::string result;
  size_t pos = 0, found;

  while ((found = content_.find(s1_, pos)) != std::string::npos) {
    result.append(content_, pos, found - pos);
    result.append(s2_);
    pos = found + s1_.length();
  }
  result.append(content_, pos, std::string::npos);
  content_.swap(result);
}

void Replacer::Write( void ) const {
  std::ofstream outfile((filename_ + ".replace").c_str());
  
  if (!outfile) {
    throw std::runtime_error("Cannot open output file: " + filename_+ ".replace");
  }
  outfile << content_;
  outfile.close();
}

void RunReplacer(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "usage: " << argv[0] << " filename s1 s2\n";
    exit(EXIT_FAILURE);
  }

  std::string filename = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];

  try {
    Replacer(filename, s1, s2).Process();
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    exit(EXIT_FAILURE);
  }
}
