#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101
#define INF 10000000

int n, m; // 도시 개수, 버스 개수
int dist[MAX][MAX]; // [출발도시][도착도시] = 비용

void Input()
{
	cin >> n >> m;

	// 최단 거리 배열을 INF로 초기화
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dist[i][j] = INF;
			if (i == j) dist[i][j] = 0; // 자기 자신으로의 거리는 0으로 초기화
		}
	}
	int a, b, c; // 출발도시, 도착도시, 비용
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
}

void Solve()
{
	for(int k = 1; k <= n; k++) { // 경유 노드 선택
		for(int i = 1; i <= n; i++) { // 출발 노드 선택
			for(int j = 1; j <= n; j++) { // 도착 노드 선택
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	// 모든 도시 쌍에 대한 최소 비용 출력
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) cout << "0 ";
			else cout << dist[i][j] << ' ';
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