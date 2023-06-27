#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int k, n, m;
	cin >> k >> n >> m;

	int tmp = (k * n) - m;
	if (tmp < 0)
		cout << "0";
	else
		cout << tmp;

	return (0);
}
