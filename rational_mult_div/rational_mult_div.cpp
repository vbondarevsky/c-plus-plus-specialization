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

bool operator==(const Rational& lhs, const Rational& rhs)
{
	return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator+ (const Rational& lhs, const Rational& rhs)
{
	return Rational(
		lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator());
}

Rational operator- (const Rational& lhs, const Rational& rhs)
{
	return Rational(
		lhs.Numerator() * rhs.Denominator() - lhs.Denominator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator());
}

Rational operator* (const Rational& lhs, const Rational& rhs)
{
	int t_n = lhs.Numerator() * rhs.Numerator();
	int t_d = lhs.Denominator() * rhs.Denominator();
	return Rational(t_n, t_d);
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

	const Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
	if (r == Rational(2, 3)) {
		cout << "equal";
	}

    cout << "OK" << endl;
    return 0;
}
