#include <iostream>
#include <map>
#include <string>

using namespace std;

void change_capital(map <string, string>& capitals, string& country, string& new_capital)
{
	if (!capitals.count(country))
	{
		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
		capitals[country] = new_capital;
	}
	else
	{
		if (capitals[country] == new_capital)
		{
			cout << "Country " << country << " hasn't changed its capital" << endl;
		}
		else
		{
			cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << new_capital << endl;
			capitals[country] = new_capital;
		}
	}
}

void rename(map <string, string>& capitals, string& old_country, string& new_country)
{
	if (old_country == new_country || !capitals.count(old_country) || capitals.count(new_country))
	{
		cout << "Incorrect rename, skip" << endl;
	}
	else
	{
		string capital = capitals[old_country];
		capitals.erase(old_country);
		capitals[new_country] = capital;

		cout << "Country " << old_country << " with capital " << capital << " has been renamed to " << new_country << endl;
	}
}

void about(const map <string, string>& capitals, const string& country)
{
	if (!capitals.count(country))
	{
		cout << "Country " << country << " doesn't exist" << endl;
	}
	else
	{
		cout << "Country " << country << " has capital " << capitals.at(country) << endl;
	}
}

void dump(const map <string, string>& capitals)
{
	if (!capitals.size())
	{
		cout << "There are no countries in the world" << endl;
	}
	else
	{
		for (auto item : capitals)
		{
			cout << item.first << "/" << item.second << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	string query;
	map <string, string> capitals;

	for (int i = 0; i < n; ++i)
	{
		cin >> query;
		if (query == "CHANGE_CAPITAL")
		{
			string country, new_capital;
			cin >> country >> new_capital;
			change_capital(capitals, country, new_capital);
		}
		else if (query == "RENAME")
		{
			string old_country, new_country;
			cin >> old_country >> new_country;
			rename(capitals, old_country, new_country);
		}
		else if (query == "ABOUT")
		{
			string country;
			cin >> country;
			about(capitals, country);
		}
		else if (query == "DUMP")
		{
			dump(capitals);
		}
	}

	return 0;
}