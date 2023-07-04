#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int	n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < i - 1; j++)
			cout << " ";
		for(int j = 0; j < 2 * n - (i * 2 - 1); j++)
			cout << "*";
		cout << "\n";
	}
	
	return (0);
}
