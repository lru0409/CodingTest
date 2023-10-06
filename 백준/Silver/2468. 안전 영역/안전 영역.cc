#include <iostream>
#include <queue>
using namespace std;

int N;
int map[100][100];
bool visited[100][100];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int y, int x, int amount)
{
	queue<pair<int, int> > Q;

	Q.push(make_pair(y, x));
	visited[y][x] = 1;
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++)
		{
			if (! (0 <= cur.first + dy[i] && cur.first + dy[i] < N)) continue ;
			if  (! (0 <= cur.second + dx[i] && cur.second + dx[i] < N)) continue ;
			if (visited[cur.first + dy[i]][cur.second + dx[i]]) continue;
			if (map[cur.first + dy[i]][cur.second + dx[i]] <= amount) continue;
			Q.push(make_pair(cur.first + dy[i], cur.second + dx[i]));
			visited[cur.first + dy[i]][cur.second + dx[i]] = true;
		}
	}
}

int rain(int amount)
{
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
	
	int count = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if (visited[i][j]) continue;
			if (map[i][j] <= amount) continue;
			BFS(i, j, amount);
			count++;
		}
	}
	return (count);
}

int main()
{
	cin >> N;
	int max = 0;
	for(int i = 0; i < N; i++) 
	{
		for(int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > max) max = map[i][j];
		}
	}
	int result = 1;
	for(int i = 1; i < max; i++)
	{
		int count = rain(i);
		if (count > result) result = count;
	}
	cout << result << endl;

	return 0;
}