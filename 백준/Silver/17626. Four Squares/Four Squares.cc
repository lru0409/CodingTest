#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int dp[50001];
	dp[0] = 0;
	int squre_root = 1;
	for(int i = 1; i <= n; i++)
	{
		if (i == pow(squre_root + 1, 2)) squre_root += 1;
		int min_count = 100;
		for(int j = 1; j <= squre_root; j++)
		{
			int squre_number = j * j;
			min_count = min(dp[i - squre_number], min_count);
		}
		dp[i] = min_count + 1;
	}
	cout << dp[n] << endl;
	return (0);
}