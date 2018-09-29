#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	const string file_name = "input.txt";
	ifstream stream(file_name);

	string line;
	while (getline(stream, line))
	{
		cout << line << endl;
	}

	return 0;
}