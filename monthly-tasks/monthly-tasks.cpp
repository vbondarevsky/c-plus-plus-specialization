#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int month = 0;
	int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<vector<string>> tasks(31);

	int Q;
	cin >> Q;

	string op;
	int day;
	string task;

	int next_month;
	for (int i = 0; i < Q; ++i)
	{
		cin >> op;
		if (op == "ADD")
		{
			cin >> day >> task;
			tasks[day - 1].push_back(task);
		}
		else if (op == "NEXT")
		{
			next_month = (month + 1) % 12;
			if (days_in_month[next_month] > days_in_month[month])
			{
				tasks.resize(days_in_month[next_month]);
			}
			else if (days_in_month[next_month] < days_in_month[month])
			{
				for (int i = days_in_month[next_month]; i < days_in_month[month]; ++i)
				{
					while (!tasks[i].empty())
					{
						tasks[days_in_month[next_month] - 1].push_back(tasks[i].back());
						tasks[i].pop_back();
					}
				}
				tasks.resize(days_in_month[next_month]);
			}
			month = next_month;
		}
		else if (op == "DUMP")
		{
			cin >> day;
			cout << tasks[day - 1].size();
			for (auto t : tasks[day - 1])
			{
				cout << " " << t;
			}
			cout << endl;
		}
	}

	return 0;
}