#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int	n;
	cin >> n;

	for(int i = 1; i < n*2; i++)
	{
		if (i <= n)
		{
			for(int j = 1; j <= n*2; j++)
			{
				if (j <= i || j > n*2 - i) cout << "*";
				else cout << " ";
			}
		}
		else
		{
			for(int j = 1; j <= n*2; j++)
			{
				if (j <= n*2 - i || j > i) cout << "*";
				else cout << " ";
			}
		}
		cout << "\n";
	}
	
	return (0);
}
