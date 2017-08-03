#include <iostream>

int main()
{
	int from, to;
	std::cin >> from >> to;
	for (int i = from; i <= to; ++i)
	{
		if (i % 2 == 0)
		{
			std::cout << i << " ";
		}
	}
    return 0;
}

