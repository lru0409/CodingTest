#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int k;
	for(int i = 0; i < n; i++)
	{
		cin >> k;
		for(int j = 0; j < k; j++)
			cout << "=";
		cout << "\n";
	}

	return (0);
}
