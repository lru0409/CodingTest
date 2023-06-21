#include <iostream>
using namespace std;

int main (void)
{
	int t, s;
	cin >> t >> s;

	if (s == 1 || !(12 <= t && t <= 16))
		cout << 280 << endl;
	else
		cout << 320 << endl;

	return (0);
}