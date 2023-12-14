#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define INF 100000000
#define MAX 1001

int n, m; // 도시 개수, 버스 개수
vector<pair<int, int> > bus[MAX]; // 도착 도시, 버스 비용
int start, destination;
int dist[MAX];
int route[MAX]; // index번 정점에 최소 비용으로 도달하려면 value에서 와야 함

void Input()
{
	cin >> n >> m;

	int s, e, c;
	for(int i = 0; i < m; i++)
	{
		cin >> s >> e >> c; // 출발 도시, 도착 도시, 버스 비용
		bus[s].push_back(make_pair(e, c));
	}
	cin >> start >> destination;

	for(int i = 1; i <= n; i++)
		dist[i] = INF;
}

void Dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ; // 현재 비용, 도시
	PQ.push(make_pair(0, start));
	dist[start] = 0;
	route[start] = 0;

	while (!PQ.empty())
	{
		int cost = PQ.top().first;
		int city = PQ.top().second;
		PQ.pop();

		if (dist[city] < cost)
			continue;

		for(size_t i = 0; i < bus[city].size(); i++)
		{
			int next_city = bus[city][i].first;
			int next_cost = cost + bus[city][i].second;
			if (dist[next_city] <= next_cost)
				continue;
			PQ.push(make_pair(next_cost, next_city));
			dist[next_city] = next_cost;
			route[next_city] = city;
		}
	}
}

void Print()
{
	// 1. 최소 비용
	cout << dist[destination] << '\n';

	int count = 0;
	stack<int> result_route;
	result_route.push(destination);
	while (route[destination] != 0)
	{
		result_route.push(route[destination]);
		destination = route[destination];
	}

	// 2. 경로에 포함된 도시의 개수
	cout << result_route.size() << '\n';

	// 3. 경로
	while (!result_route.empty())
	{
		cout << result_route.top() << ' ';
		result_route.pop();
	}
}

void Solve()
{
	Dijkstra();
	Print();
}

int main()
{
	Input();
	Solve();

	return (0);
}