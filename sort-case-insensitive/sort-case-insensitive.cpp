#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<string> v(n);
	for (auto& i : v)
	{
		cin >> i;
	}

	sort(begin(v), end(v),
		[](string s1, string s2) {
		transform(s1.begin(), s1.end(), s1.begin(), tolower);
		transform(s2.begin(), s2.end(), s2.begin(), tolower);
		return s1 < s2;
	});

	for (const auto& i : v)
	{
		cout << i << " ";
	}

	return 0;
}