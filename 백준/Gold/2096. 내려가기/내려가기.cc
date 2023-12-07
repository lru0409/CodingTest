#include <iostream>
#include <algorithm>
using namespace std;

#define MIN 0
#define MAX 1

int main()
{
	int N;
	cin >> N;

	int dp[3][2] = { 0, }; // 전 줄 각 숫자의 최솟값, 최댓값
	int input[3]; // 현재 줄의 인풋값

	int tmp0, tmp2;
	for(int i = 0; i < N; i++)
	{
		cin >> input[0] >> input[1] >> input[2];

		tmp0 = dp[0][MIN], tmp2 = dp[2][MIN];
		dp[0][MIN] = min(dp[0][MIN], dp[1][MIN]) + input[0];
		dp[2][MIN] = min(dp[2][MIN], dp[1][MIN]) + input[2];
		dp[1][MIN] = min(dp[1][MIN], min(tmp0, tmp2)) + input[1];

		tmp0 = dp[0][MAX], tmp2 = dp[2][MAX];
		dp[0][MAX] = max(dp[0][MAX], dp[1][MAX]) + input[0];
		dp[2][MAX] = max(dp[2][MAX], dp[1][MAX]) + input[2];
		dp[1][MAX] = max(dp[1][MAX], max(tmp0, tmp2)) + input[1];
	}

	int result_max = max(max(dp[0][MAX], dp[1][MAX]), dp[2][MAX]);
	int result_min = min(min(dp[0][MIN], dp[1][MIN]), dp[2][MIN]);
	cout << result_max << ' ' << result_min << '\n';

	return (0);
}
