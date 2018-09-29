#include <string>
#include <map>
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
				last_year = max(last_year, i.first);
			}
		}
		
		return last_year;
	}
};