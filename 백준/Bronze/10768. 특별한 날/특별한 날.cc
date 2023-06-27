#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int mon, day;
	cin >> mon >> day;

	if (mon == 2 && day == 18)
		cout << "Special";
	else if (mon < 2 || (mon == 2 && day < 18))
		cout << "Before";
	else
		cout << "After";

	return (0);
}
