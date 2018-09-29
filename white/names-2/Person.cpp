#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		last_names[year] = last_name;
	}
	string GetFullName(int year) {
		int first_year = GetYear(first_names, year);
		int last_year = GetYear(last_names, year);

		bool first_name_changed = first_names.count(first_year);
		bool last_name_changed = last_names.count(last_year);

		if (first_name_changed && last_name_changed)
		{
			return first_names[first_year] + " " + last_names[last_year];
		}
		else if (first_name_changed && !last_name_changed)
		{
			return first_names[first_year] + " with unknown last name";
		}
		else if (!first_name_changed && last_name_changed)
		{
			return last_names[last_year] + " with unknown first name";
		}
		else
		{
			return "Incognito";
		}
	}
	string GetFullNameWithHistory(int year) {
		auto f_names = GetNames(first_names, year);
		auto l_names = GetNames(last_names, year);

		if (!f_names.size() && !l_names.size())
		{
			return "Incognito";
		}
		else if (!f_names.size() && l_names.size())
		{
			return GetName(l_names) + " with unknown first name";
		}
		else if (f_names.size() && !l_names.size())
		{
			return GetName(f_names) + " with unknown last name";
		}
		else if (f_names.size() && l_names.size())
		{
			return GetName(f_names) + " " + GetName(l_names);
		}
	}

private:
	map<int, string> first_names;
	map<int, string> last_names;

	int GetYear(map<int, string>& m, int year)
	{
		int last_year = 0;
		for (auto& i : m)
		{
			if (i.first <= year)
			{
				last_year = i.first;
			}
			else
			{
				break;
			}
		}

		return last_year;
	}

	vector<string> GetNames(const map<int, string>& m, int year)
	{
		vector<string> names;
		for (const auto& i : m)
		{
			if (i.first <= year)
			{
				names.push_back(i.second);
			}
			else
			{
				break;
			}
		}

		reverse(begin(names), end(names));

		return names;
	}

	string GetName(const vector<string>& names)
	{
		string result = names[0];
		string prev = names[0];

		string s;
		for (int i = 1; i < names.size(); ++i)
		{
			if (prev != names[i])
			{
				if (!s.empty())
				{
					s += ", ";
				}
				prev = names[i];
				s += names[i];
			}
		}

		if (!s.empty())
		{
			result = result + " (" + s + ")";
		}

		return result;
	}
};