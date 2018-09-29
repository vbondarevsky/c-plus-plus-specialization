#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream input("input.txt");

	for (string line; getline(input, line);)
	{
		istringstream stream(line);
		float number;
		stream >> number;

		cout << fixed << setprecision(3) << number << endl;
	}

	return 0;
}