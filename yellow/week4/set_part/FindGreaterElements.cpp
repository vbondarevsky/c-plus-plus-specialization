#include <set>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
vector<T> FindGreaterElements(const set<T> &elements, const T &border) {
    auto it = find_if(elements.begin(), elements.end(), [&border](const T &element) { return element > border; });
    return {it, elements.end()};
}