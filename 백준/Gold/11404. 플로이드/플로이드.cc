#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101
#define INF 10000000

int n, m; // 도시 개수, 버스 개수
vector<pair<int, int> > bus[MAX];
int result[MAX];

void Input()
{
	cin >> n >> m;

	int a, b, c;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		bus[a].push_back(make_pair(b, c));
	}
}

void Dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ; // start로부터 거리, 도시번호
	PQ.push(make_pair(0, start));
	result[start] = 0;

	while (!PQ.empty())
	{
		int dist = PQ.top().first;
		int city = PQ.top().second;
		PQ.pop();
		if (result[city] < dist) continue;

		for(size_t i = 0; i < bus[city].size(); i++)
		{
			int next_city = bus[city][i].first;
			int next_dist = dist + bus[city][i].second;
			if (result[next_city] < next_dist) continue;
			PQ.push(make_pair(next_dist, next_city));
			result[next_city] = next_dist;
		}
	}
}

void Solve()
{
	for(int i = 1; i <= n; i++)
	{
		// result 배열 초기화
		for(int j = 1; j <= n; j++)
			result[j] = INF;
		Dijkstra(i); // 다익스트라로 최단 거리 구하기
		// result 배열 출력
		for(int j = 1; j <= n; j++)
		{
			if (result[j] == INF) cout << "0 ";
			else cout << result[j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	Input();
	Solve();

	return (0);
}