#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int scores[300];
	for(int i = 0; i < n; i++)
		cin >> scores[i];
	
	int dp[300];
	dp[0] = scores[0];
	dp[1] = scores[0] + scores[1];
	dp[2] = max(scores[0] + scores[2], scores[1] + scores[2]);

	for(int i = 3; i < n; i++)
		dp[i] = max(dp[i-3] + scores[i-1] + scores[i], dp[i-2] + scores[i]);

	cout << dp[n-1] << endl;

	return (0);
}