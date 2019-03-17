#include <set>
#include <iostream>
#include "FindNearestElement.cpp"

using namespace std;

int main() {
    set<int> numbers = {1, 4, 6};
    cout << *FindNearestElement(numbers, 0) << " ";
    cout << *FindNearestElement(numbers, 3) << " ";
    cout << *FindNearestElement(numbers, 5) << " ";
    cout << *FindNearestElement(numbers, 6) << " ";
    cout << *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}