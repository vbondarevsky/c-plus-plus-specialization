#include "LectureTitle.cpp"

int main()
{
	/*LectureTitle title("C++", "White belt", "4th");

	LectureTitle title = { "C++", "White belt", "4th" };

	LectureTitle title = { { "C++" },{ "White belt" },{ "4th" } };

	LectureTitle title(
		Course("White belt"),
		Specialization("C++"),
		Week("4th")
	);

	LectureTitle title(
		Specialization("C++"),
		Week("4th"),
		Course("White belt")
	);
*/
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);

	return 0;
}