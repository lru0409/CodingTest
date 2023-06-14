#include <iostream>
#include <algorithm>

using namespace std;

int main (void)
{
	int m, n; // m * n 크기의 보드
	cin >> m >> n;

	char board[m][n];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> board[i][j];
	
	int count[2]; // 올바른 자리에 있지 않은 요소 개수
	int min = m * n; // 가장 적은 count 구하기
	for(int i = 0; i <= m - 8; i++)
	{
		for(int j = 0; j <= n - 8; j++)
		{
			count[0] = 0;
			count[1] = 0;
			for(int k = i; k < i + 8; k++)
			{
				for(int l = j; l < j + 8; l++)
				{
					// 맨 왼쪽 상단이 W
					if (board[k][l] == 'B' && k % 2 == l % 2)
						count[0]++;
					if (board[k][l] == 'W' && k % 2 != l % 2)
						count[0]++;
					// 맨 왼쪽 상단이 B
					if (board[k][l] == 'B' && k % 2 != l % 2)
						count[1]++;
					if (board[k][l] == 'W' && k % 2 == l % 2)
						count[1]++;
				}
			}
			sort(count, count + 2);
			if (count[0] < min)
				min = count[0];
		}
	}
	cout << min << endl;

	return (0);
}