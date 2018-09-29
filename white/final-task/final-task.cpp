#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

const string error = "Wrong date format: ";

class Date {
public:
	void SetYear(int y) {
		year = y;
	}
	int GetYear() const {
		return year;
	}

	void SetMonth(const int& m) {
		if (m < 1 || m > 12) {
			throw invalid_argument("Month value is invalid: " + to_string(m));
		}
		else {
			month = m;
		}
	}
	int GetMonth() const {
		return month;
	}

	void SetDay(const int& d) {
		if (d < 1 || d > 31) {
			throw invalid_argument("Day value is invalid: " + to_string(d));
		}
		else {
			day = d;
		}
	}
	int GetDay() const {
		return day;
	}

	Date() :year(0), month(0), day(0) {}

	Date(const int& year, const int& month, const int& day)
		: year(year), month(month), day(day) {}

private:
	int year;
	int month;
	int day;
};

istream& operator>>(istream& in, Date& date) {
	string str_date;
	in >> str_date;

	stringstream stream(str_date);
	int year = -1, month = -1, day = -1;
	
	stream >> year;
	if (stream.peek() == '-') {
		stream.ignore(1);
	}
	else {
		throw invalid_argument(error + str_date);
	}
	stream >> month;
	if (stream.peek() == '-') {
		stream.ignore(1);
	}
	else {
		throw invalid_argument(error + str_date);
	}
	stream >> day;
	if (stream.peek() != EOF) {
		throw invalid_argument(error + str_date);
	}

	if (year < 0 || year > 9999) {
		throw invalid_argument(error + str_date);
	}
	date.SetYear(year);
	date.SetMonth(month);
	date.SetDay(day);

	return in;
}

ostream& operator<<(ostream& out, const Date& date) {
	out << setfill('0')
		<< setw(4) << date.GetYear() << '-'
		<< setw(2) << date.GetMonth() << '-'
		<< setw(2) << date.GetDay();
	return out;
}

bool operator<(const Date& lhs, const Date& rhs) {
	int d1, d2;
	d1 = lhs.GetYear() * 12 * 31 + lhs.GetMonth() * 31 + lhs.GetDay();
	d2 = rhs.GetYear() * 12 * 31 + rhs.GetMonth() * 31 + rhs.GetDay();

	return d1 < d2;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		set<string> unique_events(events[date].begin(), events[date].end());

		if (unique_events.count(event) == 0) {
			events[date].push_back(event);
			sort(begin(events[date]), end(events[date]));
		}
	}

	bool DeleteEvent(const Date& date, const string& event) {
		if (events.count(date) == 0) {
			return false;
		}
		auto itr = std::find(events.at(date).begin(), events.at(date).end(), event);
		if (itr != events.at(date).end()) {
			events.at(date).erase(itr);
			return true;
		}
		else {
			return false;
		}
	}

	int DeleteDate(const Date& date) {
		size_t counter = 0;
		if (events.count(date) != 0) {
			counter = events.at(date).size();
			events.erase(date);
		}
		return int(counter);
	}

	void Find(const Date& date) const {
		if (events.count(date) != 0) {
			for (auto& e : events.at(date)) {
				cout << e << endl;
			}
		}
	}

	void Print() const {
		for (const auto item : events) {
			for (const auto e : item.second) {
				cout << item.first << " " << e << endl;
			}
		}
	}

	Database() {
		ReadFromFile();
	}

	~Database() {
		WriteToFile();
	}
private:
	map<Date, vector<string>> events;
	
	void ReadFromFile() {
		ifstream file("db.txt");

		string line;
		while (getline(file, line)) {
			stringstream stream(line);
			Date date;
			string event_name;
			stream >> date >> event_name;
			events[date].push_back(event_name);
		}

		for (auto& item : events) {
			sort(begin(item.second), end(item.second));
		}
	}

	void WriteToFile() {
		ofstream file("db.txt", ios_base::trunc);
		for (const auto& item : events) {
			for (const auto& e : item.second) {
				file << item.first << " " << e << endl;
			}
		}
	}
};

int main() {
	Database db;

	try {
		string command;
		while (getline(cin, command)) {
			stringstream stream(command);
			string op;
			Date date;
			stream >> op;
			string event_name;
			if (op == "Add") {
				stream >> date;
				stream >> event_name;
				db.AddEvent(date, event_name);
			}
			else if (op == "Del") {
				stream >> date >> event_name;
				if (event_name.empty()) {
					cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
				}
				else {
					if (db.DeleteEvent(date, event_name)) {
						cout << "Deleted successfully" << endl;
					}
					else {
						cout << "Event not found" << endl;
					}
				}
			}
			else if (op == "Find") {
				stream >> date;
				db.Find(date);
			}
			else if (op == "Print") {
				db.Print();
			}
			else if (op.empty()) {
				continue;
			}
			else {
				throw invalid_argument("Unknown command: " + op);
			}
		}
	}
	catch (invalid_argument& ex) {
		cout << ex.what() << endl;
	}

	return 0;
}