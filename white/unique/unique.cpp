#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	set<string> words;
	string word;
	for (int i = 0; i < n; ++i)
	{
		cin >> word;
		words.insert(word);
	}

	cout << words.size() << endl;

	return 0;
}