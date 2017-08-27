#include <iostream>
#include "Person.cpp"

using namespace std;

int main() {
	// example 1
	Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;

	// example 2
	Person person2;

	person2.ChangeFirstName(1965, "Polina");
	person2.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person2.GetFullNameWithHistory(year) << endl;
	}

	person2.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person2.GetFullNameWithHistory(year) << endl;
	}

	person2.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person2.GetFullNameWithHistory(year) << endl;
	}

	person2.ChangeFirstName(1990, "Polina");
	person2.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person2.GetFullNameWithHistory(1990) << endl;

	person2.ChangeFirstName(1966, "Pauline");
	cout << person2.GetFullNameWithHistory(1966) << endl;

	person2.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person2.GetFullNameWithHistory(year) << endl;
	}

	person2.ChangeLastName(1961, "Ivanova");
	cout << person2.GetFullNameWithHistory(1967) << endl;

	return 0;
}