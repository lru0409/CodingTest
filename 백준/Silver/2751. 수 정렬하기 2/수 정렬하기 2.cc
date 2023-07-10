#include <iostream>
#include <algorithm>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int numbers[n];
	for(int i = 0; i < n; i++)
		cin >> numbers[i];
	
	sort(numbers, numbers + n);

	for(int i = 0; i < n; i++)
		cout << numbers[i] << "\n";
	
	return (0);
}