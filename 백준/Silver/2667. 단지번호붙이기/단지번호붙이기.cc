#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[25][25];
bool visited[25][25];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int BFS(int x, int y)
{
	queue<pair<int, int> > Q;
	Q.push(make_pair(x, y));
	visited[x][y] = true;

	int count = 1;
	while (!Q.empty())
	{
		int cx = Q.front().first, cy = Q.front().second;
		Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] || map[nx][ny] == 0) continue;
			Q.push(make_pair(nx, ny));
			visited[nx][ny] = true;
			count++;
		}
	}
	return (count);
}

int main()
{
	cin >> N;

	string line;
	for(int i = 0; i < N; i++)
	{
		cin >> line;
		for(int j = 0; j < line.length(); j++)
			map[i][j] = line[j] - '0';
	}
	
	vector<int> result;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if (visited[i][j]) continue;
			if (map[i][j] == 0) continue;
			result.push_back(BFS(i, j));
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for(size_t i = 0; i < result.size(); i++)
		cout << result[i] << '\n';

	return (0);
}