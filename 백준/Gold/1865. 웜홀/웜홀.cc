#include <iostream>
#include <vector>
using namespace std;

#define MAX 501
#define INF 5000000

struct Edge {
	int source, destination, weight;
};

int N, M, W; // 지점, 도로, 웜홀 개수
vector<Edge> edges; // 간선들 정보
int dist[MAX];

// 음의 사이클이 있는 경우 true, 없는 경우 false 반환
bool bellmanFord(int start)
{
	vector<int> dist(N + 1, INF);
	dist[start] = 0;

	for(int i = 1; i <= N - 1; i++)
	{
		for(int j = 0; j < edges.size(); j++)
		{
			int s = edges[j].source;
			int d = edges[j].destination;
			int weight = edges[j].weight;
			if (dist[s] + weight < dist[d])
				dist[d] = dist[s] + weight;
		}
	}

	for(int j = 0; j < edges.size(); j++)
	{
		int s = edges[j].source;
		int d = edges[j].destination;
		int weight = edges[j].weight;
		if (dist[s] + weight < dist[d])
			return (true);
	}

	return (false);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC; // 테케 개수
	cin >> TC;

	int S, E, T;
	for(int i = 0; i < TC; i++)
	{
		cin >> N >> M >> W;
		for(int j = 0; j < M; j++) {
			cin >> S >> E >> T;
			edges.push_back({S, E, T});
			edges.push_back({E, S, T});
		}
		for(int j = 0; j < W; j++) {
			cin >> S >> E >> T;
			edges.push_back({S, E, -T});
		}

		if (bellmanFord(1)) cout << "YES\n";
		else cout << "NO\n";;

		edges.clear();
	}

	return(0);
}