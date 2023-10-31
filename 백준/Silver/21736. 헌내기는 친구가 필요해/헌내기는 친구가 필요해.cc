#include <iostream>
#include <queue>
using namespace std;

int N, M;
char campus[600][600];
bool visited[600][600];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int get_person_count(int x, int y)
{
	int count = 0;
	queue<pair<int, int> > Q;
	Q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i], ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny] || campus[nx][ny] == 'X') continue;
			Q.push(make_pair(nx, ny));
			visited[nx][ny] = true;
			if (campus[nx][ny] == 'P') count += 1;
		}
	}
	return (count);
}

int main()
{
	cin >> N >> M;
	int i_position[2];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> campus[i][j];
			if (campus[i][j] == 'I')
			{
				i_position[0] = i;
				i_position[1] = j;
			}
		}
	}

	int person_count = get_person_count(i_position[0], i_position[1]);
	if (person_count <= 0)
		cout << "TT" << endl;
	else
		cout << person_count << endl;

	return (0);
}