#include <string>
#include <algorithm>

using namespace std;

class ReversibleString
{
public:
	ReversibleString() {}

	ReversibleString(string str)
	{
		s = str;
	}

	void Reverse()
	{
		reverse(s.begin(), s.end());
	}

	string ToString() const
	{
		return s;
	}

private:
	string s;
};