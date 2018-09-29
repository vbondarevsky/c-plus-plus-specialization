#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> temperature(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> temperature[i];
	}
	int avg_t;
	int sum = 0;
	for (auto t : temperature)
	{
		sum += t;
	}
	avg_t = sum / N;

	vector<int> result;
	for (int i = 0; i < temperature.size(); ++i)
	{
		if (temperature[i] > avg_t)
		{
			result.push_back(i);
		}
	}
	cout << result.size() << endl;
	for (auto i : result)
	{
		cout << i << " ";
	}

	return 0;
}
