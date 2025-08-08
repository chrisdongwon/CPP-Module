/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:30:29 by cwon              #+#    #+#             */
/*   Updated: 2025/08/08 18:03:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_AWESOME_PHONEBOOK_HPP_
#define MY_AWESOME_PHONEBOOK_HPP_

#include "PhoneBook.hpp"

const std::string PromptUserInput(const std::string field_type);
const std::string PromptUserNumber(const std::string field_type);
size_t StringToSizeT(const std::string& str);

void Add(PhoneBook* phonebook);
void Search(PhoneBook* phonebook);

void MyAwesomePhoneBook();

#endif
