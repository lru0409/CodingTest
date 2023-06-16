#include <iostream>
using namespace std;

int main (void)
{
	int n, v;
	cin >> n;

	int numbers[n];
	for(int i = 0; i < n; i++)
		cin >> numbers[i];
	
	cin >> v;
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if (numbers[i] == v)
			count++;
	}
	cout << count;

	return (0);
}