#include<vector>

using namespace std;

vector<int> Reversed(const vector<int>& v)
{
	vector<int> result;
	for (auto it = v.rbegin(); it != v.rend(); ++it)
	{
		result.push_back(*it);
	}

	return result;
}