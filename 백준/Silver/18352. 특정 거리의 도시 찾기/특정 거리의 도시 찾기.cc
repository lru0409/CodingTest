#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, M, K, X; // 도시 개수, 도로 개수, 거리 정보, 출발 도시
vector<int> answer;

void BFS(vector<vector<int> > graph)
{
	queue<int> Q;
	vector<int> dist(N + 1, INT_MAX);
	Q.push(X);
	dist[X] = 0;

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		for(int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (dist[next] != INT_MAX)
				continue;
			dist[next] = dist[cur] + 1;
			if (dist[next] == K)
				answer.push_back(next);
			Q.push(next);
		}
	}
}

int main()
{
	cin >> N >> M >> K >> X;

	vector<vector<int> > graph(N + 1);
	int s, e;
	for(int i = 0; i < M; i++)
	{
		cin >> s >> e;
		graph[s].push_back(e);
	}

	BFS(graph);
	if (answer.size() == 0)
		cout << -1 << '\n';
	sort(answer.begin(), answer.end());
	for(int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';

	return 0;
}