// https://stackoverflow.com/questions/19072808/using-stdpartition-with-quick-sort
#include "algostuff.hpp"
using namespace std;

using namespace std::placeholders;

template <typename It>
void my_qsort(const It& beg, const It& end)
{
    if (distance(beg, end) < 2)
        return;

    // capture iter == reference capture
    // partition may change *beg value
    // auto pos = stable_partition(beg, end, 
    //                     [beg](decltype(*beg) element) {
    //                         cout << *beg << endl;
    //                         return element < *beg;
    //                     });

    // auto value = *beg;
    // auto pos = stable_partition(beg, end, 
    //                     [value](decltype(value) element) {
    //                         cout << value << endl;
    //                         return element < value;
    //                     });
    auto pos = stable_partition(beg, end, bind(less<>(), _1, *beg));
    my_qsort(beg, pos);
    my_qsort(++pos, end);
}

int main()
{
    vector<int> coll3 = {3, 1, 9, 7, 6, 10, 2};
    my_qsort(coll3.begin(), coll3.end());
    PRINT_ELEMENTS(coll3, "sorted: ");
}

#if 0
template <typename It>
void my_qsort(const It& beg, const It& end)
{
    if (distance(beg, end) > 1) {
        // auto pos = partition(beg, end, 
        //                     [beg](decltype(*beg) element) {
        //                         cout << *beg << endl;
        //                         return element < *beg;
        //                     });
        // cout << *beg << " ";
        auto pos = stable_partition(beg, end, bind(less<>(), _1, *beg));
        // cout << *pos << endl;
        PRINT_ELEMENTS(coll3, "partion: ");
        for_each(beg, pos, [](int element) {cout << element << " ";});
        cout << endl;
        my_qsort(beg, pos);

        for_each(pos, end, [](int element) {cout << element << " ";});
        cout << endl;
        my_qsort(++pos, end);
    }
}
#endif


// template <typename It>
// void quickSort (const It& lowerIt, const It& upperIt) 
// {
//   auto d = upperIt - lowerIt ;
//   if ( d < 2 )
//    return;

//   auto pIt = lowerIt;

//   auto pValue = *pIt; 

//   pIt = std::stable_partition(lowerIt, upperIt, [pValue](int i) { return i < pValue; });

//   quickSort( lowerIt, pIt );
//   quickSort( pIt + 1, upperIt );
// }
