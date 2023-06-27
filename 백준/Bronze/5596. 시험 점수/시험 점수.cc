#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int s = a + b + c + d;
	cin >> a >> b >> c >> d;
	int t = a + b + c + d;

	if (s > t)
		cout << s;
	else
		cout << t;

	return (0);
}
