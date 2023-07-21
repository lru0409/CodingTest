#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int dp[11] = { 0, 1, 2, 4, };
	for(int i = 4; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		cout << dp[n] << "\n";
	}

	return (0);
}
