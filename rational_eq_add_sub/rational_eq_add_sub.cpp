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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

	{
		auto c = Rational(1, 2) + Rational(3, 5);

	}

    cout << "OK" << endl;
    return 0;
}
