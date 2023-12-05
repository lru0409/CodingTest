#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int N, E; // 노드 개수, 간선 개수
vector<pair<int, int> > graph[801]; // 노드, 비용

vector<int> dijkstra(int start)
{
	vector<int> dist(N + 1, INT_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // 거리, 노드
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty())
	{
		int node = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		if (dist[node] < distance) continue;
		for(size_t i = 0; i < graph[node].size(); i++)
		{
			int next_node = graph[node][i].first;
			int next_distance = distance + graph[node][i].second;
			if (next_distance < dist[next_node])
			{
				dist[next_node] = next_distance;
				pq.push(make_pair(next_distance, next_node));
			}
		}
	}
	return (dist);
}

int main()
{
	int a, b, c;
	
	cin >> N >> E;
	for(int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	int u, v; // 반드시 거쳐야 하는 두 개의 노드
	cin >> u >> v;

	vector<int> one_distance = dijkstra(1);
	vector<int> u_distance = dijkstra(u);
	vector<int> v_distance = dijkstra(v);

	int from_u_to_v = one_distance[u] + u_distance[v] + v_distance[N];
	int from_v_to_u = one_distance[v] + v_distance[u] + u_distance[N];
	
	// u - v 가 연결되지 않았거나 u, v - N 이 연결되지 않았거나, 1 - u, v 가 연결되지 않은 경우
	if (u_distance[v] == INT_MAX || v_distance[N] == INT_MAX || one_distance[u] == INT_MAX)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << min(from_u_to_v, from_v_to_u) << '\n';
	}

	return (0);
}
