#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	string input[n];
	for(int i = 0; i < n; i++)
		cin >> input[i];
	
	for(int i = 0; i < n; i++)
	{
		for(int j = m - 1; j >= 0; j--)
			cout << input[i][j];
		cout << "\n";
	}

	return (0);
}