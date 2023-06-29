#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n, w, h, l;
	cin >> n >> w >> h >> l;

	int result = (w / l) * (h / l);
	if (result < n)
		cout << result;
	else
		cout << n;

	return (0);
}
