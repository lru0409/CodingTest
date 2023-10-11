#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void BFS(int V)
{
	queue<int> Q;
	Q.push(V);
	visited[V] = true;
	cout << V << " ";

	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for(int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (visited[next]) continue;
			cout << next << " ";
			Q.push(next);
			visited[next] = true;
		}
	}
	cout << endl;
}

void DFS(int cur)
{
	cout << cur << " ";
	for(int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];
		if (visited[next]) continue;
		visited[next] = true;
		DFS(next);
	}
}

void initVisited(int N)
{
	for(int i = 1; i <= N; i++)
		visited[i] = false;
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;
	for(int i = 0; i < M; i++)
	{
		int point1, point2;
		cin >> point1 >> point2;
		graph[point1].push_back(point2);
		graph[point2].push_back(point1);
	}
	for(int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	initVisited(N);
	visited[V] = true;
	DFS(V);
	cout << endl;

	initVisited(N);
	BFS(V);

	return (0);
}