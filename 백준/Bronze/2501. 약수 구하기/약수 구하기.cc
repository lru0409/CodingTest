#include <iostream>

using namespace std;

int main (void)
{
	int n, k; // n의 약수들 중 k번째로 작은 수 출력하기
	cin >> n >> k;

	int count = 0;
	for(int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			count++;
		if (count == k)
		{
			cout << i << endl;
			return (0);
		}
	}
	cout << "0" << endl;

	return (0);
}