#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string &s) {
    vector<string> result;
    auto begin = s.begin();
    auto it = find(begin, s.end(), ' ');
    result.push_back(string(begin, it));
    while (it != s.end()) {
        begin = ++it;
        it = find(begin, s.end(), ' ');
        result.push_back(string(begin, it));
    }

    return result;
}