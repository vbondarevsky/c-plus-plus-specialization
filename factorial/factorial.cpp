
int Factorial(int x)
{
	int factorial = 1;

	if (x > 0)
	{
		for (int i = x; i > 0; --i)
		{
			factorial *= i;
		}
	}

	return factorial;
}