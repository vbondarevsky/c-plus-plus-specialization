#include <iostream>

int main()
{
	double N, A, B, X, Y;
	std::cin >> N >> A >> B >> X >> Y;

	if (N > B)
	{
		std::cout << N - N * Y / 100;
	}
	else if (N > A)
	{
		std::cout << N - N*X / 100;
	}
	else
	{
		std::cout << N;
	}
    return 0;
}

