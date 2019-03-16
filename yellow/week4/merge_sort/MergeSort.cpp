#include <algorithm>
#include <vector>

using namespace std;


template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    auto d = distance(range_begin, range_end);
    if (d < 2)
        return;

    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto middle = (begin(elements) + d / 2);
    MergeSort(begin(elements), middle);
    MergeSort(middle, end(elements));
    merge(begin(elements), middle, middle, end(elements), range_begin);
}