#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int change[100001] = { 0, };
	for(int i = 1; i <= n; i++)
	{
		change[i] = -1;
		if (i >= 5 && change[i - 5] != -1)
			change[i] = change[i - 5] + 1;
		else if (i >= 2 && change[i - 2] != -1)
			change[i] = change[i - 2] + 1;
	}
	cout << change[n];

	return (0);
}