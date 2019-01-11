#include <map>

using namespace std;

template <class K, class V>
V& GetRefStrict(map<K, V>& m, const K& key) {
    if (m.count(key) == 0) {
        throw runtime_error("something wrong");
    }
    return m.at(key);
}