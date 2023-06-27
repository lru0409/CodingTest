#include <iostream>
#include <cstdlib>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;

	if (a + b >= c * 2)
		cout << a + b - (c * 2);
	else
		cout << a + b;

	return (0);
}
