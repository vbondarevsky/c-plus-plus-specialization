#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;

void add(map<string, set<string>>& synonyms, string s1, string s2)
{
	synonyms[s1].insert(s2);
	synonyms[s2].insert(s1);
}

void count(map<string, set<string>>& synonyms, string s)
{
	cout << synonyms[s].size() << endl;
}

void check(map<string, set<string>>& synonyms, string s1, string s2)
{
	if (synonyms.count(s1) == 1 && synonyms[s1].count(s2) == 1)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	string op;
	map<string, set<string>> synonyms;
	for (int i = 0; i < n; ++i)
	{
		cin >> op;
		if (op == "ADD")
		{
			string s1, s2;
			cin >> s1 >> s2;
			add(synonyms, s1, s2);
		}
		else if (op == "COUNT")
		{
			string s;
			cin >> s;
			count(synonyms, s);
		}
		else if (op == "CHECK")
		{
			string s1, s2;
			cin >> s1 >> s2;
			check(synonyms, s1, s2);
		}
	}

	return 0;
}