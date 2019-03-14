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

class Rational {
public:
    // Вы можете вставлять сюда различные реализации,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный

    Rational() {}

    Rational(int numerator, int denominator) {}

    int Numerator() const {
    }

    int Denominator() const {
    }
};

void TestDefaultConstructor() {
    Rational rational;
    AssertEqual(rational.Numerator(), 0, "Numerator should equal to 1");
    AssertEqual(rational.Denominator(), 1, "Denominator should equal to 1");
}

void TestReduceNumeratorAndDenominator() {
    Rational rational(5, 10);
    AssertEqual(rational.Numerator(), 1, "Numerator should be reduced");
    AssertEqual(rational.Denominator(), 2, "Denominator should be reduced");
}

void TestNegativeRational() {
    {
        Rational rational(-1, 2);
        AssertEqual(rational.Numerator(), -1, "Numerator should be negative");
        AssertEqual(rational.Denominator(), 2, "Denominator should be positive");
    }
    {
        Rational rational(1, -2);
        AssertEqual(rational.Numerator(), -1, "Numerator should be negative");
        AssertEqual(rational.Denominator(), 2, "Denominator should be positive");
    }
}

void TestPositiveRational() {
    {
        Rational rational(-1, -2);
        AssertEqual(rational.Numerator(), 1, "Numerator should be positive");
        AssertEqual(rational.Denominator(), 2, "Denominator should be positive");
    }
    {
        Rational rational(1, 2);
        AssertEqual(rational.Numerator(), 1, "Numerator should be positive");
        AssertEqual(rational.Denominator(), 2, "Denominator should be positive");
    }
}

void TestZero() {
    Rational rational(0, -2);
    AssertEqual(rational.Numerator(), 0, "Numerator should equal to 0");
    AssertEqual(rational.Denominator(), 1, "Denominator should equal to 1");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
    runner.RunTest(TestReduceNumeratorAndDenominator, "TestReduceNumeratorAndDenominator");
    runner.RunTest(TestNegativeRational, "TestNegativeRational");
    runner.RunTest(TestPositiveRational, "TestPositiveRational");
    runner.RunTest(TestZero, "TestZero");

    return 0;
}
