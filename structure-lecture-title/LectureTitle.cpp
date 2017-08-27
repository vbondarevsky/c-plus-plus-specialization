#include <string>

using namespace std;

struct Specialization
{
	string value;

	explicit Specialization(const string& new_value)
	{
		value = new_value;
	}
};

struct Course
{
	string value;

	explicit Course(const string& new_value)
	{
		value = new_value;
	}
};

struct Week
{
	string value;

	explicit Week(const string& new_value)
	{
		value = new_value;
	}
};

struct LectureTitle
{
	string specialization;
	string course;
	string week;

	LectureTitle(const Specialization& s, const Course& c, const Week& w)
	{
		specialization = s.value;
		course = c.value;
		week = w.value;
	}
};