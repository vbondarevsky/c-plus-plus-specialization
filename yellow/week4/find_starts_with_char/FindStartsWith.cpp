#include <algorithm>
#include <string>

using namespace std;

template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    return {lower_bound(range_begin, range_end, string(1, prefix)),
            lower_bound(range_begin, range_end, string(1, prefix + 1))};
}