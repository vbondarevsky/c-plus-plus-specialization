#include "airline_ticket.h"
#include "test_runner.h"
#include <sstream>
#include <tuple>
#include <iostream>

using namespace std;

#define UPDATE_FIELD(ticket, field, values) \
    {                                       \
        auto it = values.find(#field);      \
        if (it != values.end()) {           \
            istringstream is(it->second);   \
            is >> ticket.field;             \
        }                                   \
    }

istream& operator>>(istream& is, Date& date) {
    is >> date.year;
    is.ignore(1);
    is >> date.month;
    is.ignore(1);
    is >> date.day;
    return is;
}

istream& operator>>(istream& is, Time& time) {
    is >> time.hours;
    is.ignore(1);
    is >> time.minutes;
    return is;
}

bool operator==(const Date& left, const Date& right) {
    return tie(left.year, left.month, left.day) == tie(right.year, right.month, right.day);
}

bool operator==(const Time& left, const Time& right) {
    return tie(left.hours, left.minutes) == tie(right.hours, right.minutes);
}

ostream& operator<<(ostream& os, const Date& date) {
    return os << date.year << '-' << date.month << '-' << date.day;
}

ostream& operator<<(ostream& os, const Time& time) {
    return os << time.hours << ':' << time.minutes;
}

void TestUpdate() {
    AirlineTicket t;
    t.price = 0;

    const map<string, string> updates1 = {
            {"departure_date", "2018-2-28"},
            {"departure_time", "17:40"},
    };
    UPDATE_FIELD(t, departure_date, updates1);
    UPDATE_FIELD(t, departure_time, updates1);
    UPDATE_FIELD(t, price, updates1);

    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 0);

    const map<string, string> updates2 = {
            {"price",        "12550"},
            {"arrival_time", "20:33"},
    };
    UPDATE_FIELD(t, departure_date, updates2);
    UPDATE_FIELD(t, departure_time, updates2);
    UPDATE_FIELD(t, arrival_time, updates2);
    UPDATE_FIELD(t, price, updates2);

    // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
    // значения этих полей не должны измениться
    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 12550);
    ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestUpdate);
}
