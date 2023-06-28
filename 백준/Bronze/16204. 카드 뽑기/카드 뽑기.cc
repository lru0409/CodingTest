#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	int frontO = m;
	int frontX = n - m;
	int backO = k;
	int backX = n - k;

	int result = 0;
	result += frontO > backO ? backO : frontO;
	result += frontX > backX ? backX : frontX;
	cout << result;

	return (0);
}
