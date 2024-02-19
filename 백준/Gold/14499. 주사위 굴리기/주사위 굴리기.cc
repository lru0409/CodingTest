#include <iostream>
using namespace std;

// 주사위를 굴리는 방향
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

// 주사위 면
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define FRONT 4
#define BACK 5

#define MAX 20

int N, M; // 지도 세로 크기, 가로 크기
int map[MAX][MAX];

int dice_y, dice_x; // 주사위 위치
int dice[6] = { 0, }; // 주사위의 각 면에 적힌 값

int dy[4] = { 0, 0, -1, 1 }; // 동서북남
int dx[4] = { 1, -1, 0, 0 };

int rt[4][4] = {
	{ UP, LEFT, DOWN, RIGHT }, // 동쪽으로 굴렸을 때 회전
	{ UP, RIGHT, DOWN, LEFT }, // 서
	{ UP, FRONT, DOWN, BACK }, // 북
	{ UP, BACK, DOWN, FRONT } // 남
};

// 주사위를 굴리고 맨 윗 면의 수 반환
int rollTheDice(int dir)
{
	// 주사위 위치 이동
	dice_y += dy[dir];
	dice_x += dx[dir];
	if (dice_y < 0 || dice_x < 0 || dice_y >= N || dice_x >= M)
	{
		dice_y -= dy[dir];
		dice_x -= dx[dir];
		return -1;
	}

	// cout << "===== dir: " << dir << ", y: " << dice_y << ", x: " << dice_x << " =====\n";
	int temp = dice[rt[dir][0]];
	dice[rt[dir][0]] = dice[rt[dir][1]];
	dice[rt[dir][1]] = dice[rt[dir][2]];
	dice[rt[dir][2]] = dice[rt[dir][3]];
	dice[rt[dir][3]] = temp;

	if (map[dice_y][dice_x] == 0) {
		map[dice_y][dice_x] = dice[DOWN];
	} else {
		dice[DOWN] = map[dice_y][dice_x];
		map[dice_y][dice_x] = 0;
	}

	// cout << "  " << dice[BACK] << '\n';
	// cout << dice[LEFT] << ' ' << dice[UP] << ' ' << dice[RIGHT] << '\n';
	// cout << "  " << dice[FRONT] << '\n';
	// cout << "  " << dice[DOWN] << '\n';

	return dice[UP];
}

int main()
{
	int K; // 명령 개수
	int i, j, dir, result;

	cin >> N >> M >> dice_y >> dice_x >> K;
	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++)
			cin >> map[i][j];
	
	for(i = 0; i < K; i++)
	{
		cin >> dir;
		result = rollTheDice(dir - 1);
		if (result >= 0)
			cout << result << '\n';
			// cout << "=> " << result << '\n';
	}

	return 0;
}