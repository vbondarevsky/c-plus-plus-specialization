#include <algorithm>
#include <vector>

using namespace std;


template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    auto d = distance(range_begin, range_end);
    if (d < 2)
        return;

    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto border1 = (begin(elements) + d / 3);
    auto border2 = (border1 + d / 3);

    MergeSort(begin(elements), border1);
    MergeSort(border1, border2);
    MergeSort(border2, end(elements));

    vector<typename RandomIt::value_type> temp;
    merge(begin(elements), border1, border1, border2, back_inserter(temp));
    merge(begin(temp), end(temp), border2, end(elements), range_begin);
}