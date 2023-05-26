#include <iostream>

using namespace std;

string grades[9] = { "A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
float subjectScores[9] = { 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0 };

float getSubjectScore(string grade) // 등급으로 과목평점 구하기
{
	for(int i = 0; i < 9; i++)
	{
		int idx = 0;
		while (grade[idx])
		{
			if (grade[idx] != grades[i][idx])
				break;
			idx++;
		}
		if (idx == grade.length())
			return (subjectScores[i]);
	}
	return (0);
}

int main (void)
{
	cout << fixed;
	cout.precision(6);

	string subject; float score; string grade;

	float sum1 = 0; // 학점 총합
	float sum2 = 0; // (학점 X 과목평점)의 합

	for(int i = 0; i < 20; i++)
	{
		cin >> subject >> score >> grade;
		
		if (grade == "P")
			continue;

		float subjectScore = getSubjectScore(grade);
		sum1 += score;
		sum2 += score * subjectScore;
	}
	cout << sum2/sum1 << endl;

	return (0);
}
