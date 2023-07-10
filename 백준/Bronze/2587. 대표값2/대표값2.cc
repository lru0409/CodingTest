#include <iostream>
#include <algorithm>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int numbers[5];
	for(int i = 0; i < 5; i++)
		cin >> numbers[i];
	
	int sum = 0;
	for(int i = 0; i < 5; i++)
		sum += numbers[i];
	cout << sum / 5 << "\n";

	for(int i = 1; i < 5; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if (numbers[j] > numbers[j + 1])
				swap(numbers[j], numbers[j + 1]);
			else
				break ;
		}
	}
	cout << numbers[2];
	
	return (0);
}