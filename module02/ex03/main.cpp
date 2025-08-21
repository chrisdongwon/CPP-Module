/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:47:09 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 15:47:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2D.hpp"

int main( void ) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    std::cout << "Triangle vertices: A(0,0), B(5,0), C(2.5,5)\n" << std::endl;

    // Test 1: point strictly inside
    Point p1(2.5f, 2.0f);
    std::cout << "Test 1: point (2.5,2.0) inside: " 
              << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;

    // Test 2: point outside
    Point p2(5.0f, 5.0f);
    std::cout << "Test 2: point (5,5) inside: " 
              << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;

    // Test 3: point on edge AB
    Point p3(2.5f, 0.0f);
    std::cout << "Test 3: point (2.5,0) on edge AB: " 
              << (bsp(a, b, c, p3) ? "true" : "false") << std::endl;

    // Test 4: point on edge BC
    Point p4(3.75f, 2.5f);
    std::cout << "Test 4: point (3.75,2.5) on edge BC: " 
              << (bsp(a, b, c, p4) ? "true" : "false") << std::endl;

    // Test 5: point at vertex C
    Point p5(2.5f, 5.0f);
    std::cout << "Test 5: point (2.5,5) at vertex C: " 
              << (bsp(a, b, c, p5) ? "true" : "false") << std::endl;

    // Test 6: another inside point
    Point p6(2.5f, 1.0f);
    std::cout << "Test 6: point (2.5,1) inside: " 
              << (bsp(a, b, c, p6) ? "true" : "false") << std::endl;

    return 0;
}
