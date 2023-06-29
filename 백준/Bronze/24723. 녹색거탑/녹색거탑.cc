#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int result = 1;
	for(int i = 0; i < n; i++)
		result *= 2;
	cout << result;

	return (0);
}
