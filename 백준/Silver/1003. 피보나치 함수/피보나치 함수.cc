#include <iostream>
using namespace std;

int main(void)
{
	int dp_zero[41] = { 1, 0 };
	int dp_one[41] = { 0, 1 };
	for(int i = 2; i <= 40; i++)
	{
		dp_zero[i] = dp_zero[i-1] + dp_zero[i-2];
		dp_one[i] = dp_one[i-1] + dp_one[i-2];
	}

	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		cout << dp_zero[n] << " " << dp_one[n] << "\n";
	}

	return (0);
}