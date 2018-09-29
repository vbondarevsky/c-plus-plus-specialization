#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	map<set<string>, int> routes;
	for (int i = 0; i < n; ++i)
	{
		int n_stop;
		cin >> n_stop;
		set<string> stops;
		string stop;
		for (int j = 0; j < n_stop; ++j)
		{
			cin >> stop;
			stops.insert(stop);
		}
		if (!routes.count(stops))
		{
			int size = routes.size();
			routes[stops] = size + 1;
			cout << "New bus " << routes[stops] << endl;
		}
		else
		{
			cout << "Already exists for " << routes[stops] << endl;
		}
	}

	return 0;
}