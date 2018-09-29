#include<string>
#include<algorithm>
#include<vector>

using namespace std;

bool IsPalindrom(string s)
{
	string reversed_s(s);
	reverse(reversed_s.begin(), reversed_s.end());

	return s == reversed_s;
}

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> result;
	for (auto s : words)
	{
		if (IsPalindrom(s) && s.size() >= minLength)
		{
			result.push_back(s);
		}
	}

	return result;
}