#include <iostream>
using namespace std;

int queens[15]; // 퀸의 y축 위치
int N, result = 0;

bool check(int x)
{
	for(int i = 0; i < x; i++)
	{
		if (queens[i] == queens[x] || abs(queens[x] - queens[i]) == x - i)
			return (false);
	}
	return (true);
}

void NQueen(int x)
{
	if (x == N)
	{
		result += 1;
		return;
	}
	
	for(int i = 0; i < N; i++)
	{
		queens[x] = i;
		if (check(x))
			NQueen(x + 1);
	}
}

int main()
{
	cin >> N;
	NQueen(0);
	cout << result << '\n';

	return (0);
}
