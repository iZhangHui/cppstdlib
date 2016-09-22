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
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// function that prints the passed argument
void print(int elem)
{
    cout << elem << ' ';
}

// void print(const string& elem)
// {
//     cout << elem << ' ';
// }

int main()
{
    vector<int> coll;
    // vector<string> str_coll = {"c++", "std", "lib"};

    // insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    // print all elements
    for_each(coll.cbegin(), coll.cend(),  // range
             print);                      // operation
    cout << endl;

    // print all elements
    // for_each(str_coll.cbegin(), str_coll.cend(),  // range
    //           print);                             // operation
    // cout << endl;
}
