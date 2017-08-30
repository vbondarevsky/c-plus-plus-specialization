#include <iostream>

using namespace std;

class Rational {
public:
	Rational() {
		_numerator = 0;
		_denominator = 1;
	}

	Rational(int numerator, int denominator) {
		if (numerator == 0)
		{
			_numerator = 0;
			_denominator = 1;
		}
		else
		{
			int sign = (numerator * denominator) < 0 ? -1 : 1;
			int gcd = GCD(numerator, denominator);
			_denominator = abs(denominator / gcd);
			_numerator = sign * abs(numerator / gcd);
		}
	}

	int Numerator() const {
		return _numerator;
	}

	int Denominator() const {
		return _denominator;
	}

private:
	int _numerator;
	int _denominator;

	int GCD(int numerator, int denominator) const
	{
		int m = abs(denominator);
		int n = abs(numerator);

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

		return m;
	}
};

int main() {
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

	cout << "OK" << endl;
	return 0;
}
