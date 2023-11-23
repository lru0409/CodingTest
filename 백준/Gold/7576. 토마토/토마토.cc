#include <iostream>
#include <queue>
using namespace std;

int M, N;
int tomato[1000][1000];
queue<pair<pair<int, int>, int> > Q;
int result= 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void BFS()
{
	while (!Q.empty())
	{
		int cx = Q.front().first.first, cy = Q.front().first.second;
		int day = Q.front().second;
		Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (tomato[nx][ny] != 0) continue;
			tomato[nx][ny] = 1;
			Q.push(make_pair(make_pair(nx, ny), day + 1));
			result = day + 1;
		}
	}
}

int main()
{
	cin >> M >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
				Q.push(make_pair(make_pair(i, j), 0));
		}
	}

	BFS();

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if (tomato[i][j] == 0) {
				cout << -1 << '\n';
				return (0);
			}
		}
	}
	cout << result << '\n';

	return (0);
}
