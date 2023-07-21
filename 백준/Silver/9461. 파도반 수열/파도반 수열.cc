#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	long dp[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
	for(int i = 11; i <= 100; i++)
		dp[i] = dp[i-1] + dp[i-5];
	
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		cout << dp[n] << "\n";
	}

	return (0);
}