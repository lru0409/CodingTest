#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int sum = 0;
	int input;
	
	while (1)
	{
		cin >> input;
		if (input == -1)
			break ;
		sum += input;
	}
	cout << sum;

	return (0);
}
