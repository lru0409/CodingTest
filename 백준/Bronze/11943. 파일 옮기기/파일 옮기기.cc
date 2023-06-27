#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a + d < b + c)
		cout << a + d;
	else
		cout << b + c;

	return (0);
}
