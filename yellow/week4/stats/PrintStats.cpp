#include <vector>
#include <iostream>
#include <algorithm>

#ifdef TEST

#include "PrintStats.h"
#include "person.h"

#endif

using namespace std;

void PrintStats(vector<Person> persons) {

    auto genderIt = partition(begin(persons), end(persons), [](Person &p) { return p.gender == Gender::FEMALE; });
    auto femaleEmployedIt = partition(begin(persons), genderIt, [](Person &p) { return p.is_employed; });
    auto maleEmployedIt = partition(genderIt, end(persons), [](Person &p) { return p.is_employed; });

    cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;
    cout << "Median age for females = " << ComputeMedianAge(begin(persons), genderIt) << endl;
    cout << "Median age for males = " << ComputeMedianAge(genderIt, end(persons)) << endl;
    cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), femaleEmployedIt) << endl;
    cout << "Median age for unemployed females = " << ComputeMedianAge(femaleEmployedIt, genderIt) << endl;
    cout << "Median age for employed males = " << ComputeMedianAge(genderIt, maleEmployedIt) << endl;
    cout << "Median age for unemployed males = " << ComputeMedianAge(maleEmployedIt, end(persons)) << endl;
}