#include <iostream>
using namespace std;

class Rational {
public:
	Rational() {
		Init();
	}

	Rational(long long numerator, long long denominator) {
		Init(numerator, denominator);
	}

	int Numerator() const {
		return _numerator;
	}

	int Denominator() const {
		return _denominator;
	}
	void SetNumeratorDenominator(long long numerator, long long denominator)
	{
		Init(numerator, denominator);
	}

private:
	int _numerator;
	int _denominator;

	void Init(long long numerator = 0, long long denominator = 1)
	{
		if (numerator == 0 || denominator == 0)
		{
			_numerator = 0;
			_denominator = 1;
		}
		else
		{
			long long m = numerator * denominator;
			long long sign = (m) < 0 ? -1 : 1;
			long long gcd = GCD(numerator, denominator);
			_denominator = abs(denominator / gcd);
			_numerator = sign * abs(numerator / gcd);
		}
	}

	int GCD(long long numerator, long long denominator) const
	{
		long long m = abs(denominator);
		long long n = abs(numerator);

		// алгоритм Евклида
		long long temp = 0;
		while (n != 0)
		{
			if (n > 0)
			{
				temp = m;
				m = n;
				n = temp % n;
			}
		}

		return m;
	}
};

bool operator==(const Rational& lhs, const Rational& rhs)
{
	return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator* (const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/ (const Rational& lhs, const Rational& rhs)
{
	return Rational(
		lhs.Numerator() * rhs.Denominator(),
		lhs.Denominator() * rhs.Numerator());
}

int main() {
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	cout << "OK" << endl;
	return 0;
}
