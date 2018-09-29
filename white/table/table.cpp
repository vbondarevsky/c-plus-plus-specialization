#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
	ifstream file("input.txt");

	int n, m;
	file >> n >> m;
	file.ignore(1);
	for (string line; getline(file, line);)
	{
		istringstream stream(line);
		for (int j = 0; j < m; ++j)
		{
			string value;
			getline(stream, value, ',');
			cout << setw(10) << value;
			if (j < m - 1)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}