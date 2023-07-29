#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int arr[n];
	int dp[n];
	int result = 1;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
		
		int j = i-1;
		while (j >= 0)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				result = max(result, dp[i]);
			}
			j--;
		}
	}
	cout << result;
	
	return (0);
}