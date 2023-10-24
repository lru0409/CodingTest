#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1001];
bool visited[1001] = { false, };

void BFS(int start)
{
	queue<int> Q;
	Q.push(start);
	visited[start] = true;

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for(int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (visited[next]) continue;
			visited[next] = true;
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
		int p1, p2;
		cin >> p1 >> p2;
		graph[p1].push_back(p2);
		graph[p2].push_back(p1);
	}

	int count = 0;
	for(int i = 1; i <= N; i++)
	{
		if (visited[i]) continue;
		BFS(i);
		count += 1;
	}
	cout << count << endl;

	return (0);
}