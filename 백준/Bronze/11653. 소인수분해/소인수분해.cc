#include <iostream>

using namespace std;

int main (void)
{
	int n; // n 소인수분해
	cin >> n;

	int count;
	while (n > 1)
	{
		int div = 1;
		while (div <= n)
		{
			if (n % div == 0 && div != 1)
				break;
			div++;
		}
		cout << div << endl;
		n /= div;
	}

	return (0);
}