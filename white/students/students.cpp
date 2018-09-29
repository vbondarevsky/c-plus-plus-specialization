#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
	string first_name;
	string last_name;
	int birth_year;
	int birth_month;
	int birth_day;
};

int main()
{
	int n;
	cin >> n;

	vector<Student> students(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> students[i].first_name
			>> students[i].last_name
			>> students[i].birth_day
			>> students[i].birth_month
			>> students[i].birth_year;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string req;
		int k;

		cin >> req >> k;
		--k;
		if (req == "name" && k >=0 && k < students.size())
		{
			cout << students[k].first_name << " " << students[k].last_name << endl;
		}
		else if (req == "date" && k >= 0 && k < students.size())
		{
			cout << students[k].birth_day << "." << students[k].birth_month << "." << students[k].birth_year << endl;
		}
		else
		{
			cout << "bad request" << endl;
		}
	}

	return 0;
}