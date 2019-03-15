#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <class T>
vector<T> operator*(const vector<T>&, const vector<T>&);

template <class First, class Second>
pair<First, Second> operator*(const pair<First, Second>&, const pair<First, Second>&);

template <class Key, class Value>
map<Key, Value> operator*(const map<Key, Value>&, const map<Key, Value>&);

template <class T>
T Sqr(T);

template <class T>
vector<T> operator*(const vector<T>& v1, const vector<T>& v2) {
    vector<T> v(v1);
    for (auto& x : v) {
        x = Sqr(x);
    }
    return v;
}

template <class First, class Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2) {
    return {Sqr(p1.first), Sqr(p1.second)};
}

template <class Key, class Value>
map<Key, Value> operator*(const map<Key, Value>& m1, const map<Key, Value>& m2) {
    map<Key, Value> m;
    for (auto& p : m1) {
        m[p.first] = Sqr(p.second);
    }
    return m;
}

template <class T>
T Sqr(T x) {
    return x * x;
}
