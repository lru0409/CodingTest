#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int total = a + b + c + d;
	cout << total / 60 << "\n";
	cout << total % 60 << "\n";

	return (0);
}
