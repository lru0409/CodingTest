#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int T[16] = {0, };
	int P[16] = {0, };
	int dp[17] = {0, };

	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];
	
	for(int i = N; i >= 1; i--)
	{
		int deadline = i + T[i];
		if (N + 1 < deadline)
			dp[i] = dp[i+1];
		else
			dp[i] = max(dp[deadline] + P[i], dp[i+1]);
	}
	cout << dp[1] << '\n';

	return 0;
}