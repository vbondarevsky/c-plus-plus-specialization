#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SortedStrings
{
public:
	void AddString(const string& s)
	{
		strings.push_back(s);
	}

	vector<string> GetSortedStrings()
	{
		vector<string> result(strings);
		sort(begin(result), end(result));

		return result;
	}

private:
	vector<string> strings;
};