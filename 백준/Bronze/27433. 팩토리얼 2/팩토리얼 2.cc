#include <iostream>
using namespace std;

int main (void)
{
	int n;
	cin >> n;

	long long result = 1;
	for(int i = 1; i <= n; i++)
		result *= i;
	cout << result << endl;

	return (0);
}