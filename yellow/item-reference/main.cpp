#include <iostream>
#include <map>

#include "getrefstrict.cpp"

using namespace std;

template <class K, class V>
V& GetRefStrict(map<K, V>& m, const K& key);

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict<int, string>(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue

    try {
        auto& i = GetRefStrict(m, 1);
    } catch (runtime_error&) {
        cout << "exception" << endl;
    }
}