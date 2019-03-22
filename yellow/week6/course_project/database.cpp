#include "database.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

ostream& operator<<(ostream& os, const Entry entry) {
    os << entry.Date << ' ' << entry.Event;
    return os;
}

void Database::Add(const Date& date, const string& event) {
    auto& events = db_[date];
    if (events.second.find(event) == events.second.end()) {
        events.first.push_back(event);
        events.second.insert(event);
    }
}

void Database::Print(ostream& os) const {
    for (auto& row : db_) {
        for (auto& event : row.second.first) {
            os << Entry{row.first, event} << endl;
        }
    }
}

Entry Database::Last(const Date& date) const {
    auto it = db_.upper_bound(date);
    if (it == db_.begin()) {
        throw invalid_argument("");
    }
    --it;
    return {it->first, it->second.first[it->second.first.size() - 1]};
}
