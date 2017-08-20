#include<vector>

using namespace std;

void Reverse(vector<int>& v)
{
	vector<int> temp(v);
	v.clear();
	for (auto it = temp.rbegin(); it != temp.rend(); ++it)
	{
		v.push_back(*it);
	}
}