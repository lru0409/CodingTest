#include <iostream>

using namespace std;

int main (void)
{
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	if ((a1*n0) + a0 <= c * n0 && a1 <= c)
		cout << "1\n";
	else
		cout << "0\n";
	
	return (0);
}