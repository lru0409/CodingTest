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
			for(int j = 0; j < i - 1; j++)
				cout << " ";
			for(int j = 0; j < n*2-(i*2-1); j++)
				cout << "*";
		}
		else
		{
			// i = 6
			for(int j = 0; j < n*2-i-1; j++)
				cout << " ";
			for(int j = 0; j < i-(n*2-i-1); j++)
				cout << "*";
		}
		cout << "\n";
	}
	
	return (0);
}
