#include <iostream>
#include <vector>
using namespace std;

int N;
int result = 0;

vector<int> queens; // 퀸의 y축 위치

// 이전 퀸들과 가로로 겹치지 않는가?
bool isPossibleHorizontal(int count, int y)
{
	for(int i = 0; i < count; i++)
	{
		if (queens[i] == y)
			return (false);
	}
	return (true);
}

// 이전 퀸들과 대각선으로 겹치지 않는가?
bool isPossibleDiagonal(int count, int y)
{
	// 왼쪽 위로 가는 대각선
	int tmp_cnt = count - 1;
	int tmp_y = y - 1;
	while (tmp_cnt >= 0 && tmp_y >= 0)
	{
		if (queens[tmp_cnt] == tmp_y)
			return (false);
		tmp_cnt--;
		tmp_y--;
	}

	// 왼쪽 아래로 가는 대각선
	tmp_cnt = count - 1;
	tmp_y = y + 1;
	while (tmp_cnt >= 0 && tmp_y < N)
	{
		if (queens[tmp_cnt] == tmp_y)
			return (false);
		tmp_cnt--;
		tmp_y++;
	}

	return (true);
}

void NQueen(int count)
{
	if (count == N)
	{
		result += 1;
		return;
	}
	
	for(int i = 0; i < N; i++)
	{
		if (isPossibleHorizontal(count, i) && isPossibleDiagonal(count, i))
		{
			queens.push_back(i);
			NQueen(count + 1);
			queens.pop_back();
		}
	}
}


int main()
{
	cin >> N;
	NQueen(0);
	cout << result << '\n';

	return (0);
}
