#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 101
#define MAX_K 100001

pair<int, int> things[MAX_N]; // 무게, 가치
int dp[MAX_N][MAX_K] = { 0, };

int main()
{
	int N, K, W, V;
	cin >> N >> K;

	for(int i = 1; i <= N; i++)
	{
		cin >> W >> V;
		things[i] = make_pair(W, V);
	}

	for(int n = 1; n <= N; n++) // n 번째 물건까지 취급
	{
		for(int k = 1; k <= K; k++) // 현재 목표 무게 k
		{
			// n번째 물건의 무게가 k보다 큰 경우, n번째 물건이 추가되기 전의 가치를 가져오기
			// n번째 물건의 무게가 k 이하인 경우, [n번째 물건이 추가되기 전의 n번째 물건의 무게만큼 뺐을 때의 가치] + n번째 물건의 가치

			// n번째 물건의 무게가 k보다 큰 경우 : n번째 물건을 포기
			if (things[n].first > k)
			{
				dp[n][k] = dp[n - 1][k]; // n번째 물건이 추가되기 전의 가치를 그대로 가져오기
			}
			else // n번째 물건의 무게가 k 이하인 경우 : n번째 물건 넣기를 시도 가능
			{
				// n번째 물건의 추가되기 전, n번째 물건 만큼 무게를 확보했을 때 가치 + n번째 물건의 가치 (n번째 물건 추가 시도를 했을 때 가치)
				int try_n_value = dp[n - 1][k - things[n].first] + things[n].second;
				dp[n][k] = max(dp[n - 1][k], try_n_value); // n번째 물건 추가 시도했을 때와 하지 않았을 떄의 가치 중 큰 것을 선택
			}
		}
	}
	cout << dp[N][K] << '\n';

	return (0);
}