#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N, H;
int tomato[100][100][100];
int result = 0;

int dh[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };

void setQueue(queue<vector<int> >& Q)
{
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < M; k++) {
				if (tomato[i][j][k] == 1) // 익은 토마토
				{
					vector<int> v;
					v.push_back(i);
					v.push_back(j);
					v.push_back(k);
					v.push_back(0);
					Q.push(v);
				}
			}
		}
	}
}

// 익은 토마토가 있는 곳을 기준으로 동시에 돌린다?
void BFS()
{
	queue<vector<int> > Q;
	setQueue(Q);

	while (!Q.empty())
	{
		int ch = Q.front()[0];
		int cy = Q.front()[1];
		int cx = Q.front()[2];
		int day = Q.front()[3];
		Q.pop();

		for(int i = 0; i < 6; i++)
		{
			int nh = ch + dh[i];
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (nh < 0 || ny < 0 || nx < 0 || nh >= H || ny >= N || nx >= M) continue;
			if (tomato[nh][ny][nx] != 0) continue;

			tomato[nh][ny][nx] = 1;
			vector<int> v;
			v.push_back(nh);
			v.push_back(ny);
			v.push_back(nx);
			v.push_back(day + 1);
			result = day + 1;
			Q.push(v);
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
	for(int i = 0; i < H; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k < M; k++)
				cin >> tomato[i][j][k];
	
	BFS();

	if (is_unripie_tomato())
		cout << -1 << endl;
	else
		cout << result << endl;
	
	return (0);
}
