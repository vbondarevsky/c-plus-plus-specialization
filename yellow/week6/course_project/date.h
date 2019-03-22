#pragma once

#include <iostream>

using namespace std;


class Date {
public:
    int Year;
    int Month;
    int Day;

    Date(int year, int month, int day);
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& os, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);