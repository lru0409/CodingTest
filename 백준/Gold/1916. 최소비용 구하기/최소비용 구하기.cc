#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define INF 100000000
using namespace std;

int N, M;
vector<pair<int, int> > Bus[MAX]; // 도착 도시, 비용
int start, destination;
int dist[MAX];

void Input()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		Bus[s].push_back(make_pair(e, c));
	}

	cin >> start >> destination;
	for(int i = 1; i <= N; i++)
		dist[i] = INF;
}

void Dijkstra()
{
	priority_queue<pair<int, int> > pq; // 든 비용, 현재 도시
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost > dist[cur])
			continue;
		for(int i = 0; i < Bus[cur].size(); i++)
		{
			int ncity = Bus[cur][i].first;
			int ncost = cost + Bus[cur][i].second;
			if (ncost >= dist[ncity]) continue;
			dist[ncity] = ncost;
			pq.push(make_pair(-ncost, ncity));
		}
	}
	cout << (dist[destination]) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	Input();
	Dijkstra();

	return (0);
}
