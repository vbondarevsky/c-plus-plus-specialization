#include <set>
#include <algorithm>

using namespace std;


set<int>::const_iterator FindNearestElement(const set<int> &numbers, int border) {

    const auto it = numbers.lower_bound(border);

    if (it == numbers.begin())
        return it;
    else if (it == numbers.end())
        return prev(it);
    else {
        const auto p = prev(it);
        if ((border - *p) <= (*it - border))
            return p;
    }

    return it;
}
