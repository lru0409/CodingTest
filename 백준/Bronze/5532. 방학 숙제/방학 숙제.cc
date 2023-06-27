#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	int x = a / c;
	if (a % c != 0)
		x += 1;
	int y = b / d;
	if (b % d != 0)
		y += 1;
	
	if (x > y)
		cout << l - x;
	else
		cout << l - y;

	return (0);
}
