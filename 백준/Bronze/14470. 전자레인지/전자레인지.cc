#include <iostream>
#include <cstdlib>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	int second = 0;
	while (a != b)
	{
		if (a == 0)
			second += d + e;
		else if (a < 0)
			second += c;
		else
			second += e;
		a += 1;
	}
	cout << second;

	return (0);
}
