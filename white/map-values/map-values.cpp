#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set<string> result;
	for (auto item : m)
	{
		result.insert(item.second);
	}

	return result;
}