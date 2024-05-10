#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> soldiers(N);
	for(int i = 0; i < N; i++)
		cin >> soldiers[i];
	
	int max_remain = 0;
	vector<int> dp(N, 1); // 현재 가질 수 있는 최장 감소 부분 수열 길이
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if (soldiers[j] > soldiers[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		max_remain = max(max_remain, dp[i]);
	}
	cout << N - max_remain << '\n';

	return 0;
}