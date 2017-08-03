#include<iostream>
#include<cmath>

int main()
{
	double a, b, c;
	std::cin >> a >> b >> c;

	double D;
	D = std::pow(b, 2) - 4 * a*c;

	if (a != 0 && b != 0)
	{
		if (D == 0)
		{
			std::cout << -b / (2 * a);
		}
		else if (D > 0)
		{
			std::cout << (-b + std::sqrt(D)) / (2 * a) << " ";
			std::cout << (-b - std::sqrt(D)) / (2 * a);
		}
	}
	if (a == 0 && b != 0)
	{
		std::cout << -c / b;
	}

    return 0;
}

