#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 200000

int V, E, start;
vector<pair<int, int> > graph[20001]; // 연결된 노드, 가중치
int dist[20001];

void Input()
{
	cin >> V >> E >> start;

	int u, v, w;
	for(int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	// dist 초기화
	for(int i = 1; i <= V; i++)
		dist[i] = INF;
}

void Dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ; // 시작 노드부터의 거리, 노드
	PQ.push(make_pair(0, start));
	dist[start] = 0;

	while (!PQ.empty())
	{
		int distance = PQ.top().first;
		int node = PQ.top().second;
		PQ.pop();

		if (dist[node] < distance)
			continue;

		for(size_t i = 0; i < graph[node].size(); i++)
		{
			int next_node = graph[node][i].first;
			int next_distance = distance + graph[node][i].second;
			if (dist[next_node] < next_distance)
				continue;
			dist[next_node] = next_distance;
			PQ.push(make_pair(next_distance, next_node));
		}
	}
}

int main()
{
	Input();
	Dijkstra();

	for(int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return (0);
}
