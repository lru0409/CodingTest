#include <iostream>
using namespace std;

int R, C, T;
int House[50][50]; // 미세먼지 상태

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void Spread()
{
	int tmp[50][50] = { 0, };

	// 현재 칸의 값 수정, 인접한 칸에 더할 값을 tmp 배열에 저장
	for(int r = 0; r < R; r++)
	{
		for(int c = 0; c < C; c++)
		{
			int amount = House[r][c];
			if (amount == -1 || amount== 0) continue;
			for(int i = 0; i < 4; i++)
			{
				int nx = r + dx[i], ny = c + dy[i];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				if (House[nx][ny] == -1) continue;
				tmp[nx][ny] += amount / 5;
				House[r][c] -= amount / 5;
			}
		}
	}
	// tmp 배열의 값을 현재 값에 합산
	for(int r = 0; r < R; r++)
		for(int c = 0; c < C; c++)
			House[r][c] += tmp[r][c];
}

void Work(int air_cleaner)
{
	int top = air_cleaner;
	int bottom = air_cleaner + 1;

	// to down (top)
	for(int i = top - 1; i > 0; i--)
		House[i][0] = House[i - 1][0];

	// to up (bottom)
	for(int i = bottom + 1; i < R - 1; i++)
		House[i][0] = House[i + 1][0];

	// to left (together)
	for(int i = 0; i < C - 1; i++) {
		House[0][i] = House[0][i + 1];
		House[R - 1][i] = House[R - 1][i + 1];
	}

	// to up (top)
	for(int i = 0; i < top; i++)
		House[i][C - 1] = House[i + 1][C - 1];

	// to down (bottom)
	for(int i = R - 1; i > bottom; i--)
		House[i][C - 1] = House[i - 1][C - 1];

	// to right (together)
	for(int i = C - 1; i > 1; i--) {
		House[top][i] = House[top][i - 1];
		House[bottom][i] = House[bottom][i - 1];
	}
	House[top][1] = 0;
	House[bottom][1] = 0;
}

int main()
{
	int air_cleaner = -1;

	cin >> R >> C >> T;
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			cin >> House[r][c];
			if (House[r][c] == -1 && air_cleaner == -1) {
				air_cleaner = r;
			}
		}
	}
	
	while (T--)
	{
		Spread(); // 미세먼지 확산
		Work(air_cleaner); // 공기청정기 작동
	}

	int result = 0;
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			if (House[r][c] == -1) continue;
			result += House[r][c];
		}
	}
	cout << result << '\n';

	return (0);
}
