#pragma once

#include "date.h"

#include <string>

using namespace std;


struct Entry {
    Date Date;
    string Event;

    Entry(const class Date& date, const string& event);
};


