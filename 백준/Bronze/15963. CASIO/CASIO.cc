#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	long long n, m;
	cin >> n >> m;
	if (n == m)
		cout << 1;
	else
		cout << 0;

	return (0);
}
