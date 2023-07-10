#include <iostream>
#include <algorithm>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int	n;
	cin >> n;

	int numbers[n];
	for(int i = 0; i < n; i++)
		cin >> numbers[i];
	
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 1; j < n - i; j++)
		{
			if (numbers[j - 1] > numbers[j])
				swap(numbers[j - 1], numbers[j]);
		}
	}

	for(int i = 0; i < n; i++)
		cout << numbers[i] << "\n";
	
	return (0);
}