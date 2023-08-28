#include <iostream>
using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	int max = 0;
	for(int i = 1; i <= K; i++)
	{
		int num = N * i;
		int newNum = 0;
		while (num > 0)
		{
			newNum = (newNum * 10) + (num % 10);
			num /= 10;
		}
		if (newNum > max)
			max = newNum;
	}
	cout << max << endl;

	return (0);
}
