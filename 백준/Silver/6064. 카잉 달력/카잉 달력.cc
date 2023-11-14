#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int M, N, x, y;
	for(int i = 0; i < T; i++)
	{
		cin >> M >> N >> x >> y;

		int year = x;
		while (true)
		{
			int tmp_y = year % N;
			if (tmp_y == 0) tmp_y = N;
			if (tmp_y == y)
			{
				cout << year << '\n';
				break;
			}
			year += M;
			if ((year - x) % N == 0)
			{
				cout << -1 << '\n';
				break;
			}
		}
	}

	return (0);
}