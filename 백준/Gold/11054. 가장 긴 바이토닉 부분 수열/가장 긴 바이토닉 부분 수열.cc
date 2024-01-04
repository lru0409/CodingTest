#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 각 원소에 대해 증가하는 부분 수열 크기, 감소하는 부분 수열 크기 구하기

#define MAX 1000
int N;
int A[MAX];
int increasing_dp[MAX];
int decreasing_dp[MAX];

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
		increasing_dp[i] = 1;
		decreasing_dp[i] = 1;
	}

	// 증가하는 부분 수열 길이 구하기
	for(int cur = 0; cur < N; cur++)
	{
		for(int prev = 0; prev < cur; prev++)
		{
			if (A[prev] < A[cur] && increasing_dp[cur] < increasing_dp[prev] + 1)
				increasing_dp[cur] = increasing_dp[prev] + 1;
		}
	}
	// 감소하는 부분 수열 길이 구하기
	for(int cur = N - 1; cur >= 0; cur--)
	{
		for(int next = N - 1; next > cur; next--)
		{
			if (A[cur] > A[next] && decreasing_dp[cur] < decreasing_dp[next] + 1)
				decreasing_dp[cur] = decreasing_dp[next] + 1;
		}
	}

	int result = 0;
	for(int i = 0; i < N; i++)
	{
		int len = increasing_dp[i] + decreasing_dp[i] - 1;
		if (len > result) result = len;
	}
	cout << result << '\n';

	return (0);
}