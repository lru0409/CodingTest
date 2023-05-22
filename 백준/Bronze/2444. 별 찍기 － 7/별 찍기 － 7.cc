#include <iostream>

using namespace std;

int main (void)
{
	int n;
	cin >> n;

	for(int i = 1; i < n*2; i++)
	{
		if (i <= n) {
			for(int j = 0; j < n-i; j++)
				cout << " ";
			for(int j = 0; j < i*2-1; j++)
				cout << "*";
		} else {
			for(int j = 0; j < i-n; j++) cout << " ";
			for(int j = 0; j < (n*2-i)*2-1; j++) cout << "*";
		}
		cout << endl;
	}

	return (0);
}