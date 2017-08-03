#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	int i = 0;
	int counter_f = 0;
	for (auto c : s)
	{
		if(c == 'f')
		{ 
			counter_f++;
		}

		if (counter_f == 2)
		{
			break;
		}
		i++;
	}
	if (counter_f == 0)
	{
		std::cout << -2;
	}
	else if (counter_f == 1)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << i;
	}
    return 0;
}

