#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int max = -1;
	int a, b, c, reward;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		if (a == b && b == c) reward = 10000 + a * 1000;
		else if (a == b || a == c) reward = 1000 + a * 100;
		else if (b == c) reward = 1000 + b * 100;
		else
		{
			if (a > b && b > c) reward = a * 100;
			else if (b > a && b > c) reward = b * 100;
			else reward = c * 100;
		}
		if (reward > max)
			max = reward;
	}
	cout << max;

	return (0);
}
