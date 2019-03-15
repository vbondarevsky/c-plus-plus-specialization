#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
    if (a == 0) {
        if (b == 0)
            return 0;
        else
            return 1;
    } else {
        double D = b * b - 4 * a * c;
        if (D < 0)
            return 0;
        else if (D == 0)
            return 1;
        else
            return 2;
    }
}

void TestQuadraticEquationNoRoot() {
    AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0);
}

void TestQuadraticEquationOneRoot() {
    AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1);
}

void TestQuadraticEquationTwoRoots() {
    AssertEqual(GetDistinctRealRootCount(1, 10, 1), 2);
}

void TestLinearEquationNoRoot() {
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0);
}

void TestLinearEquationOneRoot() {
    AssertEqual(GetDistinctRealRootCount(0, 2, 1), 1);
}

int main() {
    TestRunner runner;
    runner.RunTest(TestQuadraticEquationNoRoot, "TestQuadraticEquationNoRoot");
    runner.RunTest(TestQuadraticEquationOneRoot, "TestQuadraticEquationOneRoot");
    runner.RunTest(TestQuadraticEquationTwoRoots, "TestQuadraticEquationTwoRoots");
    runner.RunTest(TestLinearEquationNoRoot, "TestLinearEquationNoRoot");
    runner.RunTest(TestLinearEquationOneRoot, "TestLinearEquationOneRoot");

    return 0;
}
