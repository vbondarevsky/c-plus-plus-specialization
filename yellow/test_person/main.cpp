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

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        int first_year = GetYear(first_names, year);
        int last_year = GetYear(last_names, year);

        bool first_name_changed = first_names.count(first_year);
        bool last_name_changed = last_names.count(last_year);

        if (first_name_changed && last_name_changed) {
            return first_names[first_year] + " " + last_names[last_year];
        } else if (first_name_changed && !last_name_changed) {
            return first_names[first_year] + " with unknown last name";
        } else if (!first_name_changed && last_name_changed) {
            return last_names[last_year] + " with unknown first name";
        } else {
            return "Incognito";
        }
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;

    int GetYear(map<int, string>& m, int year) {
        int last_year = 0;
        for (auto& i : m) {
            if (i.first <= year) {
                last_year = max(last_year, i.first);
            }
        }

        return last_year;
    }
};

void TestAll() {
    Person person;
    AssertEqual(person.GetFullName(2000), "Incognito");
    person.ChangeLastName(2000, "Petrov");
    AssertEqual(person.GetFullName(1999), "Incognito");
    AssertEqual(person.GetFullName(2001), "Petrov with unknown first name");
    person.ChangeLastName(2002, "Ivanov");
    AssertEqual(person.GetFullName(2002), "Ivanov with unknown first name");
    person.ChangeFirstName(1989, "Fedor");
    AssertEqual(person.GetFullName(1999), "Fedor with unknown last name");
    AssertEqual(person.GetFullName(2005), "Fedor Ivanov");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestAll, "TestAll");
    return 0;
}
