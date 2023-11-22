#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<vector<int> > Q;

int M, N, H;
int tomato[100][100][100];
int result = 0;

int dh[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };


void BFS()
{
	while (!Q.empty())
	{
		vector<int> cur = Q.front();
		Q.pop();

		for(int i = 0; i < 6; i++)
		{
			int nh = cur[0] + dh[i], ny = cur[1] + dy[i], nx = cur[2] + dx[i];
			if (nh < 0 || ny < 0 || nx < 0 || nh >= H || ny >= N || nx >= M) continue;
			if (tomato[nh][ny][nx] != 0) continue;
			tomato[nh][ny][nx] = 1;

			vector<int> next(4);
			next[0] = nh, next[1] = ny, next[2] = nx, next[3] = cur[3] + 1;
			result = cur[3] + 1;
			Q.push(next);
		}
	}
}

bool is_unripie_tomato()
{
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < M; k++) {
				if (tomato[i][j][k] == 0) {
					return (true);
				}
			}
		}
	}
	return (false);
}

int main()
{
	cin >> M >> N >> H;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < M; k++)
			{
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
				{
					vector<int> v(4);
					v[0] = i, v[1] = j, v[2] = k, v[3] = 0;
					Q.push(v);
				}
			}
		}
	}
	
	BFS();

	for(int i = 0; i < H; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < M; k++) {
				if (tomato[i][j][k] == 0) {
					cout << -1 << endl;
					return (0);
				}
			}
		}
	}
	cout << result << endl;
	
	return (0);
}
