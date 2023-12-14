#include <iostream>
#include <queue>
using namespace std;

int N;
int Space[21][21];
int shark_size = 2;
pair<int, int> shark_pos;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void Input()
{
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> Space[i][j];
			if (Space[i][j] == 9) {
				shark_pos.first = i;
				shark_pos.second = j;
				Space[i][j] = 0;
			}
		}
	}
}

int BFS()
{
	queue<pair<pair<int, int>, int> > Q; // 위치, 거리
	bool visited[20][20] = { false, };
	Q.push(make_pair(make_pair(shark_pos.first, shark_pos.second), 0));
	visited[shark_pos.first][shark_pos.second] = true;

	int x = N, y = N, time = -1; // 도착할 칸, 이동 시간
	while (!Q.empty())
	{
		int cx = Q.front().first.first, cy = Q.front().first.second;
		int dist = Q.front().second;
		Q.pop();

		if (Space[cx][cy] != 0 && Space[cx][cy] < shark_size) // 작은 물고기를 찾은 경우
		{
			if (time == -1 || (time == dist && (cx < x || (cx == x && cy < y))))
			{
				x = cx;
				y = cy;
				time = dist;
				continue;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (Space[nx][ny] > shark_size || visited[nx][ny]) continue;
			Q.push(make_pair(make_pair(nx, ny), dist + 1));
			visited[nx][ny] = true;
		}
	}
	shark_pos.first = x, shark_pos.second = y;
	Space[x][y] = 0;

	return (time);
}

void Solve()
{
	int time = 0;
	int eat_count = 0;
	while (1)
	{
		int move_time = BFS();
		if (move_time == -1) break;
		time += move_time;
		eat_count += 1;
		if (eat_count == shark_size) {
			shark_size += 1;
			eat_count = 0;
		}
	}
	cout << time << '\n';
}

int main()
{
	Input();
	Solve();

	return (0);
}
