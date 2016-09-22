/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <functional>
#include <iostream>

int main()
{
    auto plus10 = [] (int i) {
                    return i + 10;
                  };
    std::cout << "+10:    " << plus10(7) << std::endl;

    auto plus10times2 = [] (int i) {
                          return (i + 10) * 2;
                        };
    std::cout << "+10 *2: " << plus10times2(7) << std::endl;

    auto pow3 = [] (int i) {
                  return i * i * i;
                };
    std::cout << "x*x*x:  " << pow3(7) << std::endl;

    auto inversDivide = [] (double d1, double d2) {
                         return d2 / d1;
                        };
    std::cout << "invdiv: " << inversDivide(49,7) << std::endl;

}
