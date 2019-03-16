#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &os, vector<int> &v) {
    for (auto &i:v) {
        os << i << ' ';
    }
    return os;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    iota(v.rbegin(), v.rend(), 1);

    do {
        cout << v << endl;
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}
