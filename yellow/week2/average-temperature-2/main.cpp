#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> T(N);
    for (auto &t : T) {
        std::cin >> t;
    }

    int m = std::accumulate(T.begin(), T.end(), 0i64) / N;

    std::vector<int> filteredT;
    for (auto i = 0; i < T.size(); ++i) {
        if (T[i] > m) {
            filteredT.push_back(i);
        }
    }
    std::cout << filteredT.size() << std::endl;
    for (const auto &t : filteredT) {
        std::cout << t << ' ';
    }

    return 0;
}