#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	long dp[91] = { 0, 1, 1, };
	for(int i = 3; i <= n; i++)
		dp[i] = dp[i-1] + dp[i-2];
	cout << dp[n];
	
	return (0);
}