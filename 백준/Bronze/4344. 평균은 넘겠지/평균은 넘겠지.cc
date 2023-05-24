#include <iostream>

using namespace std;

int main (void)
{
	cout << fixed;
	cout.precision(3);

	int count;
	cin >> count;

	float results[count];

	for(int i = 0; i < count; i++)
	{
		int n; // 학생 수
		cin >> n;

		int scores[n];
		float average = 0;
		for(int j = 0; j < n; j++)
		{
			cin >> scores[j];
			average += scores[j];
		}
		average /= n;

		int overCount = 0; // 평균을 넘는 학생 수
		for(int j = 0; j < n; j++)
		{
			if (scores[j] > average)
				overCount++;
		}
		results[i] = (float)overCount/n * 100;
	}

	for(int i = 0; i < count; i++)
		cout << results[i] << "%" << endl;

	return (0);
}