#include <iostream>
using namespace std;

int field[50][50];

void check(int y, int x, int n, int m)
{
	field[y][x] = 2;

	if (y != 0 && field[y - 1][x] == 1)
		check(y - 1, x, n, m);
	if (y != n - 1 && field[y + 1][x] == 1)
		check(y + 1, x, n, m);
	if (x != 0 && field[y][x - 1] == 1)
		check(y, x - 1, n, m);
	if (x != m - 1 && field[y][x + 1] == 1)
		check(y, x + 1, n, m);
}

int main(void)
{
	int t;
	cin >> t;

	int m, n, k; // 가로, 세로, 배추 개수
	for(int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
				field[j][k] = 0;

		int x, y;
		for(int i = 0; i < k; i++)
		{
			cin >> x >> y;
			field[y][x] = 1;
		}

		int count = 0;
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				if (field[j][k] == 1)
				{
					check(j, k, n, m);
					count++;
				}
			}
		}
		cout << count << endl;
	}

	return (0);
}