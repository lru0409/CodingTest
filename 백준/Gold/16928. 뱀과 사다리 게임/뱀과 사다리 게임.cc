#include <iostream>
#include <map>
#include <queue>
using namespace std;

map<int, int> jump;
bool visited[101] = { false, };
int dist[101];

int BFS(int start)
{
	queue<int> Q;
	Q.push(start);
	visited[start] = true;
	dist[start] = 0;

	while (Q.front() != 100)
	{
		int cur = Q.front();
		Q.pop();
		for(int i = 1; i <= 6; i++)
		{
			int next = cur + i;
			if (next > 100 || visited[next]) continue;

			while (jump.find(next) != jump.end())
				next = jump[next];
			if (visited[next]) continue;

			Q.push(next);
			dist[next] = dist[cur] + 1;
			visited[next] = true;
		}
	}
	return (dist[100]);
}

int main()
{
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < N + M; i++)
	{
		int s, e;
		cin >> s >> e;
		jump[s] = e;
	}

	cout << BFS(1) << endl;
	return (0);
}