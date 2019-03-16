#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int> &numbers) {
    auto it = find_if(numbers.begin(), numbers.end(), [](const int &number) { return number < 0; });

    while (it != numbers.begin()) {
        it--;
        cout << *it << " ";
    }
}