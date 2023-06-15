#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	string grade;
	cin >> grade;

	float score = 0;
	switch(grade[0])
	{
		case 'A' :
			score += 4.0;
			break;
		case 'B' :
			score += 3.0;
			break;
		case 'C' :
			score += 2.0;
			break;
		case 'D' :
			score += 1.0;
	}

	switch(grade[1])
	{
		case '+' :
			score += 0.3;
			break;
		case '-' :
			score -= 0.3;
	}

	cout << fixed;
	cout.precision(1);
	cout << score;
	return (0);
}