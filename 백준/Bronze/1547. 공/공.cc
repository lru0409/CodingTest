#include <iostream>
#include <climits>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int m;
	cin >> m;

	int ball_pos = 1;
	int x, y;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		if (ball_pos == x)
			ball_pos = y;
		else if (ball_pos == y)
			ball_pos = x;
	}
	cout << ball_pos;

	return (0);
}
