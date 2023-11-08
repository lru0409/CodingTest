#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
bool visited[101][101] = { false, };
int dist[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int BFS(int x, int y)
{
	queue<pair<int, int> > Q;
	Q.push(make_pair(x, y));
	visited[x][y] = true;
	dist[x][y] = 1;

	while (!Q.empty())
	{
		int cx = Q.front().first;
		int cy = Q.front().second;
		if (cx == N && cy == M) break;
		Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (visited[nx][ny] || map[nx][ny] == '0') continue;
			visited[nx][ny] = true;
			dist[nx][ny] = dist[cx][cy] + 1;
			Q.push(make_pair(nx, ny));
		}
	}
	return (dist[N][M]);
}

int main()
{
	cin >> N >> M;
	string line;
	for(int i = 1; i <= N; i++)
	{
		cin >> line;
		for(int j = 0; j < M; j++)
			map[i][j + 1] = line[j];
	}
	cout << BFS(1, 1) << endl;
	return (0);
}