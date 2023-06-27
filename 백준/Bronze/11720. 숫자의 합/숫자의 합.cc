#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	string numbers;
	cin >> numbers;
	int result = 0;
	for(int i = 0; i < n; i++)
		result += numbers[i] - '0';
	cout << result;

	return (0);
}
