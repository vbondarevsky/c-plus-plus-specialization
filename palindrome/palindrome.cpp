#include<string>
#include<algorithm>

using namespace std;

bool IsPalindrom(string s)
{
	string reversed_s(s);
	reverse(reversed_s.begin(), reversed_s.end());

	return s == reversed_s;	
}