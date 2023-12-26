#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 현재 위치, 지나온 알파벳

int R, C;
char Board[20][20];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool alphabet[26] = { false, }; // 현재 경로에서 그 알파벳을 지나왔는지 여부
int result = 0; // 최대한 지날 수 있는 칸 수

void Input()
{
	cin >> R >> C;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			cin >> Board[i][j];
}

void DFS(int x, int y, int count) // 현재 위치, 지나온 칸 수
{
	if (count > result)
		result = count;

	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if (alphabet[Board[nx][ny] - 'A']) continue;
		alphabet[Board[nx][ny] - 'A'] = true;
		DFS(nx, ny, count + 1);
		alphabet[Board[nx][ny] - 'A'] = false;
	}
}

void Solve()
{
	alphabet[Board[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	cout << result << '\n';
}

int main()
{
	Input();
	Solve();

	return (0);
}