#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int parent[100001];

void BFS(int root)
{
	queue<int> Q;
	Q.push(root);
	visited[root] = true;
	
	while (!Q.empty())
	{
		int node = Q.front();
		Q.pop();

		for(size_t i = 0; i < graph[node].size(); i++)
		{
			int next = graph[node][i];
			if (visited[next]) continue;
			Q.push(next);
			visited[next] = true;
			parent[next] = node;
		}
	}
}

int main()
{
	int N, p1, p2;
	cin >> N;

	for(int i = 0; i < N - 1; i++)
	{
		cin >> p1 >> p2;
		graph[p1].push_back(p2);
		graph[p2].push_back(p1);
	}

	BFS(1);

	for(int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}

	return (0);
}