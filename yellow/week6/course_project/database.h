#pragma once

#include "date.h"
#include "node.h"
#include "entry.h"

#include <memory>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;


ostream& operator<<(ostream& os, Entry entry);

class Database {
public:
    void Add(const Date& date, const string& event);

    void Print(ostream& os) const;

    template<class Predicate>
    int RemoveIf(Predicate predicate) {
        int del_counter = 0;
        vector<Date> del;
        for (auto& i : db_) {
            for (auto it = --i.second.first.end();;) {
                if (predicate(i.first, *it)) {
                    i.second.second.erase(*it);
                    i.second.first.erase(it);
                    del_counter++;
                }
                if (it == i.second.first.begin()) break;
                it--;
            }
            if (i.second.first.empty()) {
                del.push_back(i.first);
            }
        }

        for (auto& date: del) {
            db_.erase(date);
        }

        return del_counter;
    }

    template<class Predicate>
    vector<Entry> FindIf(Predicate predicate) const {
        vector<Entry> result;
        for (auto& i : db_) {
            for (auto& event: i.second.first) {
                if (predicate(i.first, event)) {
                    result.push_back(Entry{i.first, event});
                }
            }
        }
        return result;
    }

    Entry Last(const Date& date) const;

private:
    map<Date, pair<vector<string>, set<string>>> db_;
};
