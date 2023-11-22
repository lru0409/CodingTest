#include <iostream>
#include <queue>
using namespace std;

#include <unistd.h>

int N;
char painting[100][100];
bool visited[100][100] = { false, };

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool isRedGreen(int x, int y)
{
	if (painting[x][y] == 'R' || painting[x][y] == 'G')
		return (true);
	return (false);
}

void BFS(int x, int y, bool color_blind)
{
	queue<pair<int, int> > Q;
	Q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!Q.empty())
	{
		int cx = Q.front().first, cy = Q.front().second;
		Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;
			if (!color_blind && painting[cx][cy] != painting[nx][ny]) continue;
			if (color_blind && painting[cx][cy] == 'B' && isRedGreen(nx, ny)) continue;
			if (color_blind && isRedGreen(cx, cy) && painting[nx][ny] == 'B') continue;
			visited[nx][ny] = true;
			Q.push(make_pair(nx, ny));
		}
		// sleep(1);
	}
}

int main()
{
	cin >> N;
	string line;
	for(int i = 0; i < N; i++) {
		cin >> line;
		for(int j = 0; j < line.length(); j++)
			painting[i][j] = line[j];
	}

	int common_count = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			BFS(i, j, false);
			common_count++;
		}
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			visited[i][j] = false;

	int color_blind_count = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			BFS(i, j, true);
			color_blind_count++;
		}
	}

	cout << common_count << '\n' << color_blind_count << '\n';

	return (0);
}
