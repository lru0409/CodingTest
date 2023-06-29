#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;

	int n2 = a/2 + b;
	if (n2 < n)
		cout << n2;
	else
		cout << n;

	return (0);
}
