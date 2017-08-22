#include <iostream>
#include <map>
#include <string>

using namespace std;

map <char, int> build_char_counters(const string& s)
{
	map <char, int> result;
	for (auto c : s)
	{
		++result[c];
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	string s1, s2;
	for (int i = 0; i < n; ++i)
	{
		cin >> s1 >> s2;
		if (build_char_counters(s1) == build_char_counters(s2))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}