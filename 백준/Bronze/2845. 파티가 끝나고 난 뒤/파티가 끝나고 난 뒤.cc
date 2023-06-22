#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int l, p;
	cin >> l >> p;

	int tmp;
	for(int i = 0; i < 5; i++)
	{
		cin >> tmp;
		cout << tmp - (l * p) << " ";
	}

	return (0);
}