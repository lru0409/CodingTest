#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001
#define INF 100000

int N, M, X; // 마을(학생) 수, 도로 수, 모이는 마을
vector<pair<int, int> > road[MAX]; // index에서 first로 갈 때 소요시간 second
int dist[MAX];

void Input()
{
	cin >> N >> M >> X;

	int a, b, t;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b >> t; // 시작점, 끝점, 소요시간
		road[a].push_back(make_pair(b, t));
	}
}

void Dijkstra(int start)
{
	for(int i = 1; i <= N; i++)
		dist[i] = INF;
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ; // 소요시간, 마을
	PQ.push(make_pair(0, start));
	dist[start] = 0;

	while (!PQ.empty())
	{
		int distance = PQ.top().first;
		int town = PQ.top().second;
		PQ.pop();
		if (dist[town] < distance) continue;

		for(size_t i = 0; i < road[town].size(); i++)
		{
			int next_town = road[town][i].first;
			int next_distance = distance + road[town][i].second;
			if (dist[next_town] < next_distance) continue;
			PQ.push(make_pair(next_distance, next_town));
			dist[next_town] = next_distance;
		}
	}
}

void Solve()
{
	// X에서 각 마을로 이동하는 최단 거리 구하기
	int distance_from_X[MAX];
	Dijkstra(X);
	for(int i = 1; i <= N; i++)
		distance_from_X[i] = dist[i];
	
	// 각 마을에서 X로 이동하는 최단 거리 -> 총 최단 거리구하기
	int total_distance[MAX]; // 각 마을 마다의 총 최단 거리
	for(int i = 1; i <= N; i++)
	{
		if (i == X)
		{
			total_distance[i] = 0;
			continue;
		}
		Dijkstra(i);
		total_distance[i] = dist[X] + distance_from_X[i]; // X로 가는 거리 + X에서 오는 거리
	}

	// 총 최단 거리 중 가장 긴 거리 구하기
	int max_distance = 0;
	for(int i = 1; i <= N; i++)
	{
		if (total_distance[i] > max_distance)
			max_distance = total_distance[i];
	}
	cout << max_distance << '\n';
}

int main()
{
	Input();
	Solve();

	return (0);
}