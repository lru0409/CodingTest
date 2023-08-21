#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	while (1)
	{
		int tmp = n;
		while (tmp > 0)
		{
			if (tmp%10 != 4 && tmp%10 != 7)
				break;
			tmp /= 10;
		}
		if (tmp == 0)
		{
			cout << n << endl;
			return (0);
		}
		n--;
	}

	return (0);
}