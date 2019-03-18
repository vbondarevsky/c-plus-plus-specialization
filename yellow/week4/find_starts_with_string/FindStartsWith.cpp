#include <algorithm>

using namespace std;

template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string &prefix) {
    string end = prefix;
    end[end.length() - 1]++;
    return {lower_bound(range_begin, range_end, prefix),
            lower_bound(range_begin, range_end, end)};
}