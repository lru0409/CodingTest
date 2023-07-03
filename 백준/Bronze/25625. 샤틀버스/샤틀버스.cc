#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int x, y;
	cin >> x >> y;

	if (x > y) 
		cout << x + y;
	else 
		cout << y - x;

	return (0);
}
