#include<iostream>
#include<vector>

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> binary;

	int n;
	while (N != 0)
	{
		n = N % 2;
		N = N / 2;

		binary.push_back(n);
	}

	for (std::vector<int>::const_reverse_iterator it = binary.rbegin(); it != binary.rend(); ++it)
	{
		std::cout << *it;
	}

	return 0;
}