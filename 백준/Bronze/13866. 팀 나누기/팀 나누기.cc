#include <iostream>
#include <cstdlib>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << abs(b + c - (a + d));

	return (0);
}
