#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int t, n, m;
	cin >> t;
	
	for(int i = 0; i < t; i++)
	{
		cin >> n >> m;

		int zeroCnt = 0;
		for(int j = n; j <= m; j++)
		{
			int num = j;
			if (num == 0) zeroCnt++;
			while (num > 0)
			{
				if (num % 10 == 0)
					zeroCnt++;
				num /= 10;
			}
		}
		cout << zeroCnt << endl;
	}

	return (0);
}