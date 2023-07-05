#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for(int i = 1; i < n*2; i++)
	{
		if (i <= n)
		{
			for(int j = 0; j < n - i; j++) cout << " ";
			for(int j = 0; j < i; j++) cout << "*";
		}
		else
		{
			for(int j = 0; j < i - n; j++) cout << " ";
			for(int j = 0; j < n - (i - n); j++) cout << "*";
		}
		cout << "\n";
	}
}
