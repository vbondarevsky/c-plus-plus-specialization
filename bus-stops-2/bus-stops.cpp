#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	map<vector<string>, int> routes;
	for (int i = 0; i < n; ++i)
	{
		int n_stop;
		cin >> n_stop;
		vector<string> stops(n_stop);
		for (string& stop : stops)
		{
			cin >> stop;
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