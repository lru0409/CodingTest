#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int	n;
	cin >> n;

	int cnt5 = n / 5;
	while (cnt5 >= 0)
	{
		if ((n - (cnt5 * 5)) % 3 == 0)
		{
			cout << cnt5 + ((n - (cnt5 * 5)) / 3);
			return (0);
		}
		cnt5--;
	}
	cout << "-1";
	
	return (0);
}