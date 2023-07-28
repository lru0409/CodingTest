#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	double dp[n];
	cin >> dp[0];
	double result = dp[0];
	for(int i = 1; i < n; i++)
	{
		cin >> dp[i];
		if (dp[i-1] > 1)
			dp[i] *= dp[i-1];
		result = max(result, dp[i]);
	}
	cout << fixed;
	cout.precision(3);
	cout << result;

	return (0);
}
