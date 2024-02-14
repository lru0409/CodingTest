#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[100][100];
bool contacted[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isMeltAll()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if (board[i][j] == 1)
				return (false);
		}
	}
	return (true);
}

void BFS(int x, int y)
{
	std::queue<std::pair<int, int> > Q;
	Q.push(make_pair(x, y));

	while (!Q.empty())
	{
		int cx = Q.front().first, cy = Q.front().second;
		Q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (board[nx][ny] == 1) // 치즈가 있는 부분이라면
			{
				if (contacted[nx][ny]) // 이미 외부와 접촉했다면
				{
					board[nx][ny] = 0; // 녹기
					visited[nx][ny] = true;
				}
				else // 외부와 접촉한 적 없다면
				{
					contacted[nx][ny] = true; // 접촉했음을 저장
				}
				continue;
			}
			else // 치즈가 없는 부분이라면
			{
				if (visited[nx][ny])
					continue;
				visited[nx][ny] = true;
				Q.push(make_pair(nx, ny));
			}
		}
	}
}

void cheeseMelting()
{
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			contacted[i][j] = false;
			visited[i][j] = false;
		}
	}
	
	BFS(0, 0);
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int hour = 0;
	while (true)
	{
		if (isMeltAll()) break;
		cheeseMelting();
		hour++;
	}
	std::cout << hour << '\n';

	return (0);
}
