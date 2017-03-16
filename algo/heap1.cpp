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
#include "algostuff.hpp"
#include <functional>
using namespace std;

// template< class RandomIt >
// void push_heap( RandomIt first, RandomIt last ); (1)
// template< class RandomIt, class Compare >
// void push_heap( RandomIt first, RandomIt last, Compare comp ); (2)
// Inserts the element at the position last-1 into the max heap
// defined by the range [first, last-1). The first version of the
// function uses operator< to compare the elements, the second uses
// the given comparison function comp.

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll,3,7);
    INSERT_ELEMENTS(coll,5,9);
    INSERT_ELEMENTS(coll,1,4);

    PRINT_ELEMENTS(coll, "on entry:           ");

    // convert collection into a heap
    make_heap(coll.begin(), coll.end());

    // make smallest heap
    // make_heap(coll.begin(), coll.end(), greater<int>());

    PRINT_ELEMENTS(coll, "after make_heap():  ");

    // pop next element out of the heap
    pop_heap(coll.begin(), coll.end());
    coll.pop_back();

    PRINT_ELEMENTS (coll, "after pop_heap():   ");

    // push new element into the heap
    coll.push_back(17);
    push_heap(coll.begin(), coll.end());

    PRINT_ELEMENTS (coll, "after push_heap():  ");

    // convert heap into a sorted collection
    // - NOTE: after the call it is no longer a heap
    sort_heap(coll.begin(), coll.end());

    PRINT_ELEMENTS (coll, "after sort_heap():  ");
}


// int main()
// {
//     std::vector<int> v { 3, 1, 4, 1, 5, 9 };

//     std::cout << "initially, v: ";
//     for (auto i : v)
//         std::cout << i << ' ';
//     std::cout << '\n';

//     std::make_heap(v.begin(), v.end());

//     std::cout << "after make_heap, v: ";
//     for (auto i : v)
//         std::cout << i << ' ';
//     std::cout << '\n';

//     std::pop_heap(v.begin(), v.end());
//     auto largest = v.back();
//     v.pop_back();
//     std::cout << "largest element: " << largest << '\n';

//     std::cout << "after removing the largest element, v: ";
//     for (auto i : v)
//         std::cout << i << ' ';
//     std::cout << '\n';
// }
