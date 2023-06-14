#include <iostream>

using namespace std;

int main (void)
{
	int n, m; // n개의 카드 중 3장을 골라, 합이 m과 최대한 가깝게 만들기
	cin >> n >> m;

	int card[n]; // 카드에 쓰인 수를 저장할 배열
	for(int i = 0; i < n; i++)
		cin >> card[i];
	
	int result = 0, sum;
	for(int i = 0; i < n - 2; i++)
	{
		for(int j = i + 1; j < n - 1; j++)
		{
			for(int k = j + 1; k < n; k++)
			{
				sum = card[i] + card[j] + card[k];
				if (sum > m)
					continue;
				if (m - sum < m - result)
					result = sum;
			}
		}
	}
	cout << result << endl;
	
	return (0);
}