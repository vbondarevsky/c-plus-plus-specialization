#include <iostream>
#include <sstream>

using namespace std;

class Rational {
public:
	Rational() {
		_numerator = 0;
		_denominator = 1;
	}

	Rational(int numerator, int denominator) {
		Init(numerator, denominator);
	}

	int Numerator() const {
		return _numerator;
	}

	int Denominator() const {
		return _denominator;
	}

	void SetNumeratorDenominator(int numerator, int denominator)
	{
		Init(numerator, denominator);
	}

private:
	int _numerator;
	int _denominator;

	void Init(int numerator, int denominator)
	{
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
	return Rational(
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator());
}

Rational operator/ (const Rational& lhs, const Rational& rhs)
{
	return Rational(
		lhs.Numerator() * rhs.Denominator(),
		lhs.Denominator() * rhs.Numerator());
}

istream& operator>>(istream& stream, Rational& r)
{
	int numerator = 0;
	int denominator = 0;
	stream >> numerator;
	stream.ignore(1);
	stream >> denominator;

	if (!numerator && !denominator)
	{
		return stream;
	}
	r.SetNumeratorDenominator(numerator, denominator);

	return stream;
}

ostream& operator<<(ostream& stream, const Rational& r)
{
	stream << r.Numerator() << "/" << r.Denominator();

	return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
