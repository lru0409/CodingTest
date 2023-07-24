#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int dp[31][31];
	for(int i = 1; i <= 30; i++)
	{
		dp[1][i] = i;
		dp[i][i] = 1;
	}
	for(int i = 2; i <= 30; i++)
		for(int j = i + 1; j <= 30; j++)
			dp[i][j] = dp[i][j-1] + dp[i-1][j-1];

	int t, n, m;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> m;
		cout << dp[n][m] << "\n";
	}

	return (0);
}