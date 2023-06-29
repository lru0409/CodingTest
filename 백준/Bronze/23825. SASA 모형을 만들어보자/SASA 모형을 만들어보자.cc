#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	if (n / 2 < m / 2)
		cout << n / 2;
	else
		cout << m / 2;

	return (0);
}
