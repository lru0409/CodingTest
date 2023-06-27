#include <iostream>
#include <algorithm>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int p[4];
	int x, y, r;
	cin >> p[0] >> p[1] >> p[2] >> p[3];
	cin >> x >> y >> r;

	for(int i = 0; i < 4; i++)
	{
		if (p[i] == x)
		{
			cout << i + 1;
			return (0);
		}
	}
	cout << "0";
	return (0);
}
