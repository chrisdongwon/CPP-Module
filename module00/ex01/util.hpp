/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:09:04 by cwon              #+#    #+#             */
/*   Updated: 2025/08/14 17:14:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <string>

const std::string PromptUserInput(const std::string field_type);
const std::string PromptUserNumber(const std::string field_type);
size_t StringToSizeT(const std::string& str);

#endif // UTIL_HPP_
