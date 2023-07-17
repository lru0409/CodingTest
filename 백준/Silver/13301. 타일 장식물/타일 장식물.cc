#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	long long round[81];
	round[1] = 4;
	round[2] = 6;

	for(int i = 3; i <= n; i++)
		round[i] = round[i - 1] + round[i - 2];
	cout << round[n];

	return (0);
}