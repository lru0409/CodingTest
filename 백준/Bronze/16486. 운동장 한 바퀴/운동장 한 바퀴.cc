#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int d1, d2;
	cin >> d1 >> d2;

	cout << fixed;
	cout.precision(6);
	cout << d1 * 2 + 3.141592 * d2 * 2;

	return (0);
}
