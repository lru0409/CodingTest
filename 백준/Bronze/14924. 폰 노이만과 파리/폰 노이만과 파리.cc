#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int s, t, d;
	cin >> s >> t >> d;
	cout << d / (s * 2) * t;

	return (0);
}
