#include <iostream>

using namespace std;

int main (void)
{
	int n; // n의 가장 작은 생성자 구하기
	cin >> n;

	for(int i = 1; i < n; i++)
	{
		// i의 분해합 구하기
		int tmp = i;
		int sum = i;
		while (tmp != 0)
		{
			sum += tmp % 10;
			tmp /= 10;
		}

		if (sum == n)
		{
			cout << i << endl;
			return (0);
		}
	}
	cout << "0" << endl;
	return (0);
}