#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int MAP[8][8];
int wall_cnt = 0;
vector<pair<int, int> > virus_pos;
int max_safe_size = 0;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int getSafeSize()
{
	queue<pair<int, int> > Q; // 바이러스 위치
	bool visited[8][8] = { false, };
	for(size_t i = 0; i < virus_pos.size(); i++) {
		Q.push(virus_pos[i]);
		visited[virus_pos[i].first][virus_pos[i].second] = true;
	}

	int virus_cnt = virus_pos.size();
	while (!Q.empty())
	{
		int cy = Q.front().first, cx = Q.front().second;
		Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (MAP[ny][nx] != 0 || visited[ny][nx]) continue;
			virus_cnt += 1;
			Q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
	return ((N * M) - virus_cnt - (wall_cnt + 3));
}

void findMaxSafeSize(int depth, int next_y, int next_x)
{
	if (depth == 3)
	{
		int safe_size = getSafeSize();
		if (safe_size > max_safe_size)
			max_safe_size = safe_size;
		return;
	}

	for(int i = next_y; i < N; i++)
	{
		for(int j = next_x; j < M; j++)
		{
			if (MAP[i][j] != 0) continue;
			MAP[i][j] = 1;
			findMaxSafeSize(depth + 1, i, j + 1);
			MAP[i][j] = 0;
		}
		next_x = 0;
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) wall_cnt += 1;
			else if (MAP[i][j] == 2) virus_pos.push_back(make_pair(i, j));
		}
	}
	
	findMaxSafeSize(0, 0, 0);
	cout << max_safe_size << '\n';

	return (0);
}
