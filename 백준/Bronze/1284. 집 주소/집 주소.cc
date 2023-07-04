#include <iostream>
#include <climits>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, width;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break ;
		
		width = 1;
		while (n)
		{
			if (n % 10 == 1) width += 2;
			else if (n % 10 == 0) width += 4;
			else width += 3;
			width++;
			n /= 10;
		}
		cout << width << "\n";
	}

	return (0);
}
