#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> queue;

	string op;
	int a;
	for (int i = 0; i < N; ++i)
	{
		cin >> op;
		if (op != "WORRY_COUNT")
		{
			cin >> a;
		}

		if (op == "WORRY")
		{
			queue[a] = -1;
		}
		else if(op == "QUIET")
		{
			queue[a] = 0;
		}
		else if (op == "COME")
		{
			if (a < 0)
			{
				for (int j = 0; j < -a; ++j)
				{
					queue.pop_back();
				}
			}
			else
			{
				for (int j = 0; j < a; ++j)
				{
					queue.push_back(0);
				}
			}
		}
		else if (op == "WORRY_COUNT")
		{
			a = 0;
			for (auto v : queue)
			{
				if (v == -1)
				{
					a++;
				}
			}
			cout << a << endl;
		}
	}
	return 0;
}