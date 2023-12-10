#include <iostream>
#include <queue>
using namespace std;

int dist[100001];
int cnt[100001]; // 가장 빠른 시간으로 도달한 횟수

void BFS(int N, int K)
{
	queue<int> Q; // 현재 위치
	Q.push(N);
	dist[N] = 0;
	cnt[N] = 1;

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		if (dist[K] != -1 && dist[K] < dist[cur])
			return;

		for(int next : { cur + 1, cur - 1, cur * 2 })
		{
			if (next < 0 || 100000 < next) continue;
			if (dist[next] == -1) // next에 방문한 적 없다면
			{
				dist[next] = dist[cur] + 1;
				cnt[next] = cnt[cur];
				Q.push(next);
			}
			else if (dist[next] == dist[cur] + 1) // next에 방문한 적 있지만, 도달한 시간이 지금과 같다면
			{
				cnt[next] += cnt[cur];
			}
		}
	}
}

int main()
{
	int N, K;
	cin >> N >> K;
	
	for(int i = 0; i <= 100000; i++)
		dist[i] = -1;

	BFS(N, K);
	cout << dist[K] << "\n" << cnt[K] << "\n";

	return (0);
}
