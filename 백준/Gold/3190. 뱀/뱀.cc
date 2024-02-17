#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, L; // 보드 크기, 사과 개수, 뱀 방향 변환 횟수
queue<pair<int, char> > dir_change; // 초, 방향

#define MAX 100

#define EMPTY 0
#define SNAKE 1
#define APPLE 2

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int board[MAX][MAX] = { EMPTY, };

void Input()
{
	int x, y, sec;
	char dir;

	cin >> N >> K;
	for(int i = 0; i < K; i++) 
	{
		cin >> x >> y;
		board[x-1][y-1] = APPLE;
	}
	cin >> L;
	for(int i = 0; i < L; i++) {
		cin >> sec >> dir;
		dir_change.push(make_pair(sec, dir));
	}
}

void changeDir(int& snake_dir) // 방향 바꾸기
{
	switch (dir_change.front().second)
	{
	case 'L':
		snake_dir = (snake_dir + 3) % 4; break;
	case 'D':
		snake_dir = (snake_dir + 1) % 4; break;
	}
	dir_change.pop();
}

void Simulation()
{
	int sec = 1;
	int nx, ny;
	int snake_dir = RIGHT;
	queue<pair<int, int> > snake;

	board[0][0] = SNAKE;
	snake.push(make_pair(0, 0));

	while (true)
	{
		// cout << "===== sec: " << sec << " =====\n";
		nx = snake.back().first + dx[snake_dir];
		ny = snake.back().second + dy[snake_dir];
		// cout << "nx: " << nx << ", ny: " << ny << '\n';
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			break; // 뱀이 벽에 부딪힘
		if (board[nx][ny] == SNAKE)
			break; // 뱀이 자기 몸에 부딪힘
		if (board[nx][ny] != APPLE) // 꼬리가 위치한 칸 비우기
		{
			board[snake.front().first][snake.front().second] = EMPTY;
			snake.pop();
		}
		board[nx][ny] = SNAKE;
		snake.push(make_pair(nx, ny));

		// cout << "board:\n";
		// for(int i = 0; i < N; i++) {
		// 	for(int j = 0; j < N; j++) {
		// 		cout << board[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }

		if (!dir_change.empty() && 
				sec == dir_change.front().first)
			changeDir(snake_dir);
		// cout << "--- change dir: " << snake_dir  << '\n';
		sec++;
	}

	cout << sec << '\n';
}

int main()
{
	Input();

	Simulation();

	return 0;
}