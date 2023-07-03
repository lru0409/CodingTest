#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	if (a / 2 < b)
		cout << a / 2;
	else
		cout << b;

	return (0);
}
