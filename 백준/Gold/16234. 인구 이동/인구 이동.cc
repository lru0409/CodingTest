#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>
using namespace std;

int N, L, R;
int population[50][50];
bool visited[50][50] = {false};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool BFS(int y, int x)
{
	queue<pair<int, int> > Q;
	vector<pair<int, int> > unit;
	Q.push(make_pair(x, y));
	unit.push_back(make_pair(x, y));
	int average = population[y][x];
	visited[y][x] = true;

	while (!Q.empty())
	{
		int cx = Q.front().first, cy = Q.front().second;
		Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visited[ny][nx])
				continue;

			int diff = abs(population[cy][cx] - population[ny][nx]);
			if (diff < L || R < diff)
				continue;

			average += population[ny][nx];
			Q.push(make_pair(nx, ny));
			unit.push_back(make_pair(nx, ny));
			visited[ny][nx] = true;
		}
	}

	average /= unit.size();
	for(size_t i = 0; i < unit.size(); i++)
		population[unit[i].second][unit[i].first] = average;
	return unit.size() > 1 ? true : false;
}

int main()
{
	cin >> N >> L >> R;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> population[i][j];

	int day = 0;
	while (true)
	{
		memset(&visited, false, sizeof(visited));
		bool move = false;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				if (BFS(i, j) == true) // 연합이 이루어진 경우
					move = true;
			}
		}
		if (!move) break; // 연합이 하나도 이루어지지 않은 경우 (인구 이동 X)
		day++;
	}

	cout << day << '\n';
	return 0;
}