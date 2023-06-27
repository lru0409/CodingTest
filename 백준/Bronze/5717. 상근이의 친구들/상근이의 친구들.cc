#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == 0)
			break ;
		cout << a + b << "\n";
	}

	return (0);
}
