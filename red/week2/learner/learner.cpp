#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Learner {
private:
    set<string> dict;

public:
    int Learn(const vector<string>& words) {
        auto old_size = dict.size();
        dict.insert(begin(words), end(words));
        return dict.size() - old_size;
    }

    vector<string> KnownWords() {
        return {begin(dict), end(dict)};
    }
};

