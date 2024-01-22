// 행과 열의 문자가 같으면 왼쪽 대각선 값 + 1
// 다르면 왼쪽, 위쪽 중 더 큰 값

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	int dp[MAX][MAX] = { 0, };
	for(size_t r = 1; r <= str1.size(); r++) // str1의 i번째 문자까지 취급
	{
		for(size_t c = 1; c <= str2.size(); c++) // str2의 j번째 문자까지 취급
		{
			if (str1[r - 1] == str2[c - 1])
			{
				dp[r][c] = dp[r - 1][c - 1] + 1;
			}
			else
			{
				dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);
			}
		}
	}
	std::cout << dp[str1.size()][str2.size()] << '\n';

	return (0);
}