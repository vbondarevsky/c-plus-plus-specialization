#include <iostream>

int main()
{
	int m, n;
	std::cin >> m >> n;

	// алгоритм Евклида
	int temp = 0;
	while (n != 0)
	{
		if (n > 0)
		{
			temp = m;
			m = n;
			n = temp % n;
		}
	}
	std::cout << m;

	return 0;
}