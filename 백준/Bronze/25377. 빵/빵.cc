#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int a, b;
	int min = 1001;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a <= b && b < min)
			min = b;
	}
	if (min == 1001)
		cout << "-1";
	else
		cout << min;

	return (0);
}
