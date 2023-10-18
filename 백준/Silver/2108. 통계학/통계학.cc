#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int numbers[500000];
	int sum = 0;
	int counting[8001] = { 0, };
	for(int i = 0; i < N; i++)
	{
		cin >> numbers[i];
		sum += numbers[i];
		counting[numbers[i] + 4000] += 1;
	}
	sort(numbers, numbers + N);

	int countingMax = 0;
	for(int i = -4000; i <= 4000; i++)
	{
		if (counting[i + 4000] > countingMax)
			countingMax = counting[i + 4000];
	}

	int countingMaxCount = 0;
	int countingMaxNumber = 0;
	for(int i = -4000; i <= 4000; i++)
	{
		if (counting[i + 4000] == countingMax)
		{
			countingMaxCount += 1;
			countingMaxNumber = i;
			if (countingMaxCount == 2)
				break;
		}
	}

	cout << (int)round((float)sum / N) << endl; // 산술평균
	cout << numbers[N / 2] << endl; // 중앙값
	cout << countingMaxNumber << endl; // 최빈값
	cout << numbers[N-1] - numbers[0] << endl; // 범위

	return (0);
}