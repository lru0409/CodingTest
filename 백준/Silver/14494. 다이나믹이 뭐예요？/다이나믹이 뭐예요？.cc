#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	long dp[m + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + dp[i - 1][j - 1];
			dp[i][j] %= 1000000007;
		}
	}
	cout << dp[m][n];

	return (0);
}
