#include <iostream>
#include <algorithm>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int buger[3];
	int drink[2];
	cin >> buger[0] >> buger[1] >> buger[2];
	cin >> drink[0] >> drink[1];

	sort(buger, buger + 3);
	sort(drink, drink + 2);

	cout << buger[0] + drink[0] - 50;

	return (0);
}
