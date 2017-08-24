#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& i : v)
	{
		cin >> i;
	}

	sort(begin(v), end(v), [](int i, int j) {return abs(i) < abs(j); });

	for (const auto& i : v)
	{
		cout << i << " ";
	}

	return 0;
}