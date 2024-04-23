#include <iostream>
#include <vector>
using namespace std;

#define MAX 6

int N;
char map[MAX][MAX];
vector<pair<int, int> > teachers;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool Check()
{
	for(int t = 0; t < teachers.size(); t++)
	{
		for(int dir = 0; dir < 4; dir++)
		{
			int ty = teachers[t].first + dy[dir];
			int tx = teachers[t].second + dx[dir];
			while (0 <= ty && ty < N && 0 <= tx && tx < N)
			{
				if (map[ty][tx] == 'O')
					break;
				if (map[ty][tx] == 'S')
					return false;
				ty += dy[dir];
				tx += dx[dir];
			}
		}
	}
	return true;
}

bool Combination(int depth, int ny, int nx)
{
	if (depth == 3)
	{
		if (Check() == true)
			return true;
		return false;
	}

	for(int y = ny; y < N; y++)
	{
		for(int x = nx; x < N; x++)
		{
			if (map[y][x] != 'X')
				continue;
			map[y][x] = 'O';
			if (Combination(depth + 1, y, x) == true)
				return true;
			map[y][x] = 'X';
		}
		nx = 0;
	}
	return false;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T')
				teachers.push_back(make_pair(i, j));
		}
	}

	if (Combination(0, 0, 0) == true)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}