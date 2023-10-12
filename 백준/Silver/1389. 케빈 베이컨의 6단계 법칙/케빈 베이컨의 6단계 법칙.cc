#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[101];
int dist[101][101];
int sum[101] = { 0, };

void BFS(int start)
{
	bool visited[101] = { false, };
	queue<int> Q;
	Q.push(start);
	visited[start] = true;
	dist[start][start] = 0;

	int count = 0;
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for(int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (visited[next]) continue;
			visited[next] = true;
			dist[start][next] = dist[start][cur] + 1;
			Q.push(next);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int user1, user2;
		cin >> user1 >> user2;
		if (find(graph[user1].begin(), graph[user1].end(), user2) != graph[user1].end())
			continue;
		graph[user1].push_back(user2);
		graph[user2].push_back(user1);
	}

	for(int i = 1; i <= N; i++)
	{
		BFS(i);
		for(int j = 1; j <= N; j++)
			sum[i] += dist[i][j];
	}
	
	int result = 1;
	for(int i = 2; i <= N; i++)
	{
		if (sum[i] < sum[result])
			result = i;
	}
	cout << result << endl;

	return (0);
}