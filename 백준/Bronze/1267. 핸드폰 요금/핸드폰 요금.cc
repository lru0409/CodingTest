#include <iostream>
#include <climits>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int y = 0, m = 0, time;
	for(int i = 0; i < n; i++)
	{
		cin >> time;
		y += (time / 30 + 1) * 10;
		m += (time / 60 + 1) * 15;
	}

	if (y == m)
		cout << "Y M " << y;
	else if (y < m)
		cout << "Y " << y;
	else
		cout << "M " << m;

	return (0);
}
