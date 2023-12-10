#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 모든 노드를 시작점으로 하여 다익스트라로 최단 경로 구하기
// 거리가 m 이하인 노드의 아이템 수 합 구하기

#define INF 1500

int n, m, r;
int item[101];
vector<pair<int, int> > field[101];
int dist[101];
int max_item_count = 0;

void dijkstra(int start)
{
	for(int i = 1; i <= n; i++)
		dist[i] = INF;
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ; // 시작점부터의 거리, 노드
	PQ.push(make_pair(0, start));
	dist[start] = 0;

	while (!PQ.empty())
	{
		int node = PQ.top().second;
		int distance = PQ.top().first;
		PQ.pop();
		if (dist[node] < distance) continue;

		for(size_t i = 0; i < field[node].size(); i++)
		{
			int next_node = field[node][i].first;
			int next_distance = distance + field[node][i].second;
			if (dist[next_node] < next_distance) continue;
			PQ.push(make_pair(next_distance, next_node));
			dist[next_node] = next_distance;
		}
	}
}

// 시작점으로부터 거리가 m 이하인 노드의 아이템 개수 합
int getItemCount()
{
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if (dist[i] <= m)
			sum += item[i];
	}
	return (sum);
}

int main()
{
	cin >> n >> m >> r;
	for(int i = 1; i <= n; i++)
		cin >> item[i];
	int a, b, l;
	for(int i = 0; i < r; i++)
	{
		cin >> a >> b >> l;
		field[a].push_back(make_pair(b, l));
		field[b].push_back(make_pair(a, l));
	}

	for(int i = 1; i <= n; i++)
	{
		dijkstra(i);
		max_item_count = max(getItemCount(), max_item_count);
	}
	cout << max_item_count << '\n';


	return (0);
}
