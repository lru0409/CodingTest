#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[1000][1000];
int dist[1000][1000][2]; // 벽을 부수지 않은 상태, 부순 상태
//19,660,800
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int BFS()
{
	queue<pair<pair<int, int>, int> > Q; // 좌표, 벽 부셨는지 여부
	Q.push(make_pair(make_pair(0, 0), 0));
	dist[0][0][0] = 1;

	while (!Q.empty())
	{
		int cx = Q.front().first.first, cy = Q.front().first.second;
		int break_wall = Q.front().second;
		Q.pop();
		// cout << "cx: " << cx << ", cy: " << cy << ", break wall: " << break_wall << ", dist: " << dist[cx][cy][break_wall] << '\n';

		if (cx == N - 1 && cy == M - 1) // 목표 지점에 도달한 경우
			return (dist[cx][cy][break_wall]);

		for(int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			
			if (map[nx][ny] == '1' && break_wall == 0) // 벽이지만 부술 수 있는 경우
			{
				dist[nx][ny][1] = dist[cx][cy][0] + 1;
				Q.push(make_pair(make_pair(nx, ny), 1));
			}
			else if (map[nx][ny] == '0' && dist[nx][ny][break_wall] == 0) // 벽이 아니고 아직 방문하지 않은 경우
			{
				dist[nx][ny][break_wall] = dist[cx][cy][break_wall] + 1;
				Q.push(make_pair(make_pair(nx, ny), break_wall));
			}
		}
	}
	return (-1);
}

int main()
{
	string line;

	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> line;
		for(int j = 0; j < M; j++) {
			map[i][j] = line[j];
		}
	}

	cout << BFS() << '\n';

	return (0);
}