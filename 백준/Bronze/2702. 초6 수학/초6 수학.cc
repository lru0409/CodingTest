#include <iostream>
using namespace std;

int leastCommonMultiple(int a, int b)
{
	int greater;
	if (a > b) greater = a;
	else greater = b;

	int multiple = greater;
	while (multiple < a * b)
	{
		if (multiple % a == 0 && multiple % b == 0)
			break;
		multiple += greater;
	}
	return (multiple);
}

int greatestCommonFactor(int a, int b)
{
	int factor;
	if (a < b) factor = a;
	else factor = b;

	while (factor > 1)
	{
		if (a % factor == 0 && b % factor == 0)
			break;
		factor--;
	}
	return (factor);
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	int t, a, b;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		cin >> a >> b;
		cout << leastCommonMultiple(a, b) << " ";
		cout << greatestCommonFactor(a, b) << "\n";
	}

	return (0);
}