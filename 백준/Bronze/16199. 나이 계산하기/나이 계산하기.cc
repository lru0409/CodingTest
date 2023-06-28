#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int birth[3], standard[3];
	cin >> birth[0] >> birth[1] >> birth[2];
	cin >> standard[0] >> standard[1] >> standard[2];

	if (standard[1] > birth[1] || (standard[1] == birth[1] && standard[2] >= birth[2]))
		cout << standard[0] - birth[0] << endl;
	else
		cout << standard[0] - birth[0] - 1 << endl;
	cout << standard[0] - birth[0] + 1 << endl;
	cout << standard[0] - birth[0] << endl;

	return (0);
}
