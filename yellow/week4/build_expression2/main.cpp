#include <vector>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Operation {
    char Op;
    int Number;
    bool NeedBrackets;
};

bool LessPriority(char left, char right) {
    return (left == '+' || left == '-') && (right == '*' || right == '/');
}

int main() {
    int init;
    cin >> init;
    int n;
    cin >> n;
    vector<Operation> operations;

    int counter = 0;
    for (int i = 0; i < n; ++i) {
        Operation op{};
        cin >> op.Op >> op.Number;
        if (!operations.empty()) {
            auto& prev = operations.back();
            if (LessPriority(prev.Op, op.Op)) {
                prev.NeedBrackets = true;
                counter++;
            }
        }
        operations.push_back(op);
    }

    cout << string(counter, '(') << init;
    for (auto& op : operations) {
        cout << ' ' << op.Op << ' ' << op.Number;
        if (op.NeedBrackets) {
            cout << ')';
        }
    }

    return 0;
}
