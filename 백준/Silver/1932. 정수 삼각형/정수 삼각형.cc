#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> triangle[500];
vector<int> dp[500];

int main()
{
	int n, num;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cin >> num;
			triangle[i].push_back(num);
			dp[i].push_back(num);
		}
	}

	dp[0][0] = triangle[0][0];
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
			dp[i + 1][j + 1] = dp[i][j] + triangle[i + 1][j + 1];
		}
	}

	int result = 0;
	for(int i = 0; i < n; i++)
	{
		if (dp[n - 1][i] > result)
			result = dp[n - 1][i];
	}
	cout << result << '\n';

	return (0);
}
