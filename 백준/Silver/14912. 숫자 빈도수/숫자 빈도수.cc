#include <iostream>
using namespace std;

int getCount(int num, int digit)
{
	int count = 0;
	while (num)
	{
		if (num % 10 == digit) count++;
		num /= 10;
	}
	return (count);
}

int main(void)
{
	int n, d;
	cin >> n >> d;

	int count = 0;
	for(int i = 1; i <= n; i++)
	{
		count += getCount(i, d);
	}
	cout << count << endl;

	return (0);
}
