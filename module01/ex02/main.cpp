/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:41:12 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 18:15:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main( void ) {
    std::string var = "HI THIS IS BRAIN";
    std::string* stringPTR = &var;
    std::string& stringREF = var;

    std::cout << "The nemory address of the string variable: "
              << &var << std::endl;
    std::cout << "The memory address held by stringPTR: "
              << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: "
              << &stringREF << std::endl;
    std::cout << "The value of the string variable: "
              << var << std::endl;
    std::cout << "The value pointed to by stringPTR: "
              << *stringPTR << std::endl;
    std::cout << "the value pointed to by stringREF: "
              << stringREF << std::endl;

    return 0;
}
