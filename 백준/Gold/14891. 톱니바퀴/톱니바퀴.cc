#include <iostream>
using namespace std;

int gears[4][8]; // N극은 0, S극은 1
int K; // 회전 횟수
int tooth[4] = { 0, 0, 0, 0 }; // 12시 방향 톱니의 인덱스

void Input()
{
	string line;
	for(int i=0; i<4; i++)
	{
		cin >> line;
		for(int j=0; j<8; j++)
			gears[i][j] = line[j] - '0';
	}
	cin >> K;
}

void Rotate(int gear, int dir) // 기준 톱니, 방향
{
	switch (dir)
	{
	case 1: // 시계 방향 회전
		if (tooth[gear] == 0)
			tooth[gear] = 8;
		tooth[gear] -= 1;
		break;
	case -1: // 반시계 방향 회전
		if (tooth[gear] == 7)
			tooth[gear] = -1;
		tooth[gear] += 1;
		break;
	}
}

// 왼쪽 톱니바퀴와 맞닿은 극
int GetLeftPole(int gear)
{
	int left_tooth = tooth[gear];
	if (left_tooth < 2)
		left_tooth += 8;
	left_tooth -= 2;
	return gears[gear][left_tooth];
}

// 오른쪽 톱니바퀴와 맞닿은 극
int GetRightPole(int gear)
{
	int right_tooth = tooth[gear];
	if (right_tooth > 5)
		right_tooth -= 8;
	right_tooth += 2;
	return gears[gear][right_tooth];
}

int toggle_dir(int dir)
{
	if (dir == 1)
		return -1;
	else
		return 1;
}

void RotateLeftGears(int gear, int dir)
{
	int left_pole = GetLeftPole(gear);
	Rotate(gear, dir);

	if (gear > 0 && left_pole != GetRightPole(gear-1))
		RotateLeftGears(gear-1, toggle_dir(dir));
}

void RotateRightGears(int gear, int dir)
{
	int right_pole = GetRightPole(gear);
	Rotate(gear, dir);

	if (gear < 3 && right_pole != GetLeftPole(gear+1))
		RotateRightGears(gear+1, toggle_dir(dir));
}

void Solve()
{
	int rotation_gear, rotation_dir; // 회전시킨 톱니바퀴와 방향
	for(int i=0; i<K; i++) // K번 회전
	{
		cin >> rotation_gear >> rotation_dir;
		rotation_gear -= 1; // 인덱스로 변경

		RotateLeftGears(rotation_gear, rotation_dir);
		Rotate(rotation_gear, toggle_dir(rotation_dir));
		RotateRightGears(rotation_gear, rotation_dir);
	}
}

void Output()
{
	int ret = 0;
	int score = 1;
	for(int i=0; i<4; i++)
	{
		ret += gears[i][tooth[i]] * score;
		score *= 2;
	}
	cout << ret << "\n";
}

int main(void)
{
	Input();
	Solve();
	Output();
}