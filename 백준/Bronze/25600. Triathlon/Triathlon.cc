#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int a, d, g, score;
	int max = -1;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> d >> g;
		score = a * (d + g);
		if (a == d + g)
			score *= 2;
		if (score > max)
			max = score;
	}
	cout << max;

	return (0);
}
