/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:53:02 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 12:53:02 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void FixedClassTest()
{
    std::cout << "=== Fixed Class Test ===\n";

    Fixed a;
    Fixed b(10);
    Fixed c(3.14159f);
    Fixed d(b);

    std::cout << "a (default): " << a.toFloat() << std::endl;
    std::cout << "b (int 10): " << b.toFloat() << std::endl;
    std::cout << "c (float 3.14159): " << c.toFloat() << std::endl;
    std::cout << "d (copy of b): " << d.toFloat() << std::endl;

    a = c;
    std::cout << "a after assignment a = c: " << a << std::endl;

    std::cout << "b > c ? " << (b > c) << std::endl;
    std::cout << "b < c ? " << (b < c) << std::endl;
    std::cout << "b >= d ? " << (b >= d) << std::endl;
    std::cout << "b <= d ? " << (b <= d) << std::endl;
    std::cout << "b == d ? " << (b == d) << std::endl;
    std::cout << "b != c ? " << (b != c) << std::endl;

    Fixed sum = b + c;
    Fixed diff = b - c;
    Fixed prod = b * c;
    Fixed quot = b / c;

    std::cout << "b + c = " << sum << std::endl;
    std::cout << "b - c = " << diff << std::endl;
    std::cout << "b * c = " << prod << std::endl;
    std::cout << "b / c = " << quot << std::endl;

    Fixed inc = b;
    std::cout << "inc: " << inc << std::endl;
    std::cout << "++inc: " << (++inc) << std::endl;
    std::cout << "inc++: " << (inc++) << std::endl;
    std::cout << "after inc++: " << inc << std::endl;

    Fixed dec = c;
    std::cout << "dec: " << dec << std::endl;
    std::cout << "--dec: " << (--dec) << std::endl;
    std::cout << "dec--: " << (dec--) << std::endl;
    std::cout << "after dec--: " << dec << std::endl;

    Fixed e(2.5f);
    Fixed f(7.75f);

    std::cout << "min(e, f) = " << Fixed::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << Fixed::max(e, f) << std::endl;

    std::cout << "const min/max test\n";
    const Fixed g(5.5f), h(1.25f);
    std::cout << "min(g,h) = " << Fixed::min(g,h) << std::endl;
    std::cout << "max(g,h) = " << Fixed::max(g,h) << std::endl;

    Fixed rawTest;
    rawTest.setRawBits(12345);
    std::cout << "rawTest.getRawBits() = " << rawTest.getRawBits() << std::endl;
}

int main( void ) {
  {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
  }
  FixedClassTest();

  return 0;
}
