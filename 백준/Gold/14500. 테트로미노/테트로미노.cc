#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int paper[500][500];
bool visited[500][500];
int result = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void DFS(int x, int y, int depth, int sum)
{
	if (depth == 4)
	{
		if (sum > result) result = sum;
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[nx][ny]) continue;
		visited[nx][ny] = true;
		DFS(nx, ny, depth + 1, sum + paper[nx][ny]);
		visited[nx][ny] = false;
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> paper[i][j];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			visited[i][j] = true;
			DFS(i, j, 0, 0);
			visited[i][j] = false;

			if (i - 2 >= 0 && j + 1 < M)
				result = max(result, paper[i][j] + paper[i - 1][j] + paper[i - 2][j] + paper[i - 1][j + 1]);
			if (i + 1 < N && j + 2 < M)
				result = max(result, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1]);
			if (i + 2 < N && j - 1 >= 0)
				result = max(result, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 1][j - 1]);
			if (i - 1 >= 0 && j - 2 >= 0)
				result = max(result, paper[i][j] + paper[i][j - 1] + paper[i][j - 2] + paper[i - 1][j - 1]);
		}
	}

	cout << result << endl;

	return (0);
}