#include "date.h"

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;


Date::Date(const int year, const int month, const int day) : Year(year), Month(month), Day(day) {}

ostream& operator<<(ostream& out, const Date& date) {
    out << setfill('0')
        << setw(4) << date.Year << '-'
        << setw(2) << date.Month << '-'
        << setw(2) << date.Day;
    return out;
}

bool operator<(const Date& left, const Date& right) {
    return (left.Year * 12 * 31 + left.Month * 31 + left.Day)
           < (right.Year * 12 * 31 + right.Month * 31 + right.Day);
}

bool operator==(const Date& left, const Date& right) {
    return (left.Year * 12 * 31 + left.Month * 31 + left.Day)
           == (right.Year * 12 * 31 + right.Month * 31 + right.Day);
}

bool operator<=(const Date& left, const Date& right) {
    return (left < right) || (left == right);
}

bool operator!=(const Date& left, const Date& right) {
    return !(left == right);
}

bool operator>(const Date& left, const Date& right) {
    return !(left <= right);
}

bool operator>=(const Date& left, const Date& right) {
    return (left > right) || (left == right);
}

Date ParseDate(istream& is) {
    string str_date;
    is >> str_date;

    stringstream ss(str_date);

    int y, m, d;
    ss >> y;
    ss.ignore(1);
    ss >> m;
    ss.ignore(1);
    ss >> d;

    return Date(y, m, d);
}