#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void new_bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops,
	const string& bus, const vector<string>& add_stops)
{
	buses[bus].reserve(add_stops.size());
	buses[bus].insert(buses[bus].end(), add_stops.begin(), add_stops.end());

	for (auto stop : add_stops)
	{
		stops[stop].push_back(bus);
	}
}

void buses_for_stop(map<string, vector<string>>& stops, const string& stop)
{
	if (!stops.count(stop))
	{
		cout << "No stop" << endl;
	}
	else
	{
		for (auto bus : stops[stop])
		{
			cout << bus << " ";
		}
		cout << endl;
	}
}

void stops_for_bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops, const string& bus)
{
	if (!buses.count(bus))
	{
		cout << "No bus" << endl;
	}
	else
	{
		for (auto stop : buses[bus])
		{
			cout << "Stop " << stop << ":";
			if (stops[stop].size() == 1)
			{
				cout << " no interchange" << endl;
			}
			else
			{
				for (auto bus_name : stops[stop])
				{
					if (bus_name != bus)
					{
						cout << " " << bus_name;
					}
				}
				cout << endl;
			}
		}
	}
}

void all_buses(map<string, vector<string>>& buses)
{
	if (!buses.size())
	{
		cout << "No buses" << endl;
	}
	else
	{
		for (auto bus : buses)
		{
			cout << "Bus " << bus.first << ":";
			for (auto stop : bus.second)
			{
				cout << " " << stop;
			}
			cout << endl;
		}
	}
}

int main()
{
	int n;
	cin >> n;

	map <string, vector<string>> buses;
	map <string, vector<string>> stops;

	string request;
	for (int i = 0; i < n; ++i)
	{
		cin >> request;
		if (request == "NEW_BUS")
		{
			string bus;
			int n_stop;
			vector<string> add_stops;
			cin >> bus >> n_stop;
			string current_stop;
			for (int j = 0; j < n_stop; ++j)
			{
				cin >> current_stop;
				add_stops.push_back(current_stop);
			}
			new_bus(buses, stops, bus, add_stops);
		}
		else if (request == "BUSES_FOR_STOP")
		{
			string stop;
			cin >> stop;
			buses_for_stop(stops, stop);
		}
		else if (request == "STOPS_FOR_BUS")
		{
			string bus;
			cin >> bus;
			stops_for_bus(buses, stops, bus);
		}
		else if (request == "ALL_BUSES")
		{
			all_buses(buses);
		}
	}

	return 0;
}