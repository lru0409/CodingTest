#include <iostream>
#include <queue>
using namespace std;

#define HORIZONTAL 1
#define VERTICAL 2
#define DIAGONAL 3

int N;
int House[17][17];
queue<pair<pair<int, int>, int> > Q; // 파이프 위치, 방향
int result = 0;

void try_horizontal(int pipe_cy, int pipe_cx)
{
	if (pipe_cx + 1 > N)
		return;
	if (House[pipe_cy][pipe_cx + 1] == 1)
		return;
	Q.push(make_pair(make_pair(pipe_cy, pipe_cx + 1), HORIZONTAL));
}

void try_vertical(int pipe_cy, int pipe_cx)
{
	if (pipe_cy + 1 > N)
		return;
	if (House[pipe_cy + 1][pipe_cx] == 1)
		return;
	Q.push(make_pair(make_pair(pipe_cy + 1, pipe_cx), VERTICAL));
}

void try_diagonal(int pipe_cy, int pipe_cx)
{
	if (pipe_cy + 1 > N || pipe_cx + 1 > N) 
		return;
	if (House[pipe_cy + 1][pipe_cx] == 1 || House[pipe_cy][pipe_cx + 1] == 1 || House[pipe_cy + 1][pipe_cx + 1] == 1)
		return;
	Q.push(make_pair(make_pair(pipe_cy + 1, pipe_cx + 1), DIAGONAL));
}

void BFS()
{
	Q.push(make_pair(make_pair(1, 2), HORIZONTAL));

	while (!Q.empty())
	{
		int pipe_cy = Q.front().first.first;
		int pipe_cx = Q.front().first.second;
		int pipe_dir = Q.front().second;
		Q.pop();

		if (pipe_cy == N && pipe_cx == N)
			result += 1;

		switch (pipe_dir)
		{
			case HORIZONTAL:
				try_horizontal(pipe_cy, pipe_cx);
				try_diagonal(pipe_cy, pipe_cx);
				break;
			case VERTICAL:
				try_vertical(pipe_cy, pipe_cx);
				try_diagonal(pipe_cy, pipe_cx);
				break;
			case DIAGONAL:
				try_horizontal(pipe_cy, pipe_cx);
				try_vertical(pipe_cy, pipe_cx);
				try_diagonal(pipe_cy, pipe_cx);
				break;
		}
	}
}

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			cin >> House[i][j];
	
	BFS();
	cout << result << '\n';

	return (0);
}
