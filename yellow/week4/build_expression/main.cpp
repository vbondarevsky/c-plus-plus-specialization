#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    stringstream expression;
    string init;
    cin >> init;

    int n;
    cin >> n;
    expression << string(n, '(') << init;

    for (int i = 0; i < n; ++i) {
        string op;
        string number;
        cin >> op >> number;
        expression << ") " << op + " " << number;
    }

    cout << expression.str() << endl;

    return 0;
}
