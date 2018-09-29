#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	const string file_name_in = "input.txt";
	ifstream stream(file_name_in);

	
	const string file_name_out = "output.txt";
	ofstream result(file_name_out);
	string line;
	while (getline(stream, line))
	{
		result << line << endl;
	}

	return 0;
}