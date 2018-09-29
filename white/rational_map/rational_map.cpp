#include <iostream>
#include <map>
#include <set>
#include <vector>

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

bool operator<(const Rational& lhs, const Rational& rhs)
{
	int l_n = lhs.Numerator();
	int l_d = lhs.Denominator();
	int r_n = rhs.Numerator();
	int r_d = rhs.Denominator();

	return l_n * r_d < l_d * r_n;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
